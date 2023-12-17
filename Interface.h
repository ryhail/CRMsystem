#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "exception/input_exc.h"
#include <list>
#include "conio.h"
#include <windows.h>
#include "customer.h"
#include "Algorithm.h"
#include "Stack/Stack.h"
#include "file_txt.h"

class Interface
{
public:
	Interface();
	~Interface();
	template<typename T>
	void printTable(list<T>&);
	template<typename T>
	void addNew(list<T>&);
	template<typename T>
	void workWithList(list<T>&, Stack<list<T>>&);
	template<typename T>
	int getChoiceFromMenu(list<T>& menu);
	template<typename T>
	void drawSomeMenu(list<T>& menu, int pos);
	template<typename T>
	void editOrder(list<T>& lst);
	template<typename T>
	void clientOrder(list<T>& lst);
	template<typename T>
	void deleteOrder(list<T>& lst);
	template<typename T>
	list<T> cancelLast(Stack<list<T>>&, list<T>& lst);
	template<typename T>
	void saveState(Stack<list<T>>&, list<T>&);
};

template<typename T>
void Interface::printTable(list<T>& lst) {
	if (lst.empty()) {
		cout << "Список пуст" << endl;
		return;
	}
	T().tabletop();
	cout << endl;
	for (T& order : lst)
	{
		cout << order << endl;
	}
}

template<typename T>
inline void Interface::addNew(list<T>& lst)
{
	T buf;
	if (lst.empty())
		buf.setId(1);
	else
		buf.setId(lst.back().getId() + 1);
	cin >> buf;
	string mail;
	customer temp;
	list<customer> clients;
	file_txt file;

	file.open(temp.getFileName(), 1);
	file.parseFile(clients);
	file.close();

	mail = input_email(cin, "Введите почту клиента: ");
	temp.defineByMail(mail);
	if (temp.getId() == -1) {
		cout << "Клиента с такой почтой не найдено, ввод нового клиента" << endl;
		cin >> temp;
		temp.setId(clients.back().getId() + 1);
		clients.push_back(temp);
	}
	buf.setClientId(temp.getId());
	lst.push_back(buf);

	file.open("", 2);
	file.saveToFile(clients);
	file.close();
}

template<typename T>
int Interface::getChoiceFromMenu(list<T>& menu)
{
	int pos = 1;
	char key = 0;
	bool wh_flag = true;
	drawSomeMenu(menu, pos);
	while (wh_flag) {
		rewind(stdin);
		key = 0;
		if (_kbhit())
			switch (_getch()) {
			case 13:
				wh_flag = false;
				break;
			case 72:
				if (pos == 1)
					break;
				pos--;
				system("cls");
				drawSomeMenu(menu, pos);
				break;
			case 80:
				if (pos == menu.size())
					break;
				pos++;
				system("cls");
				drawSomeMenu(menu, pos);
				break;
			case 26:
				return 0;
			case 27:
				return -1;
			default:
				break;
			}
	}
	return pos;
}

template<typename T>
void Interface::drawSomeMenu(list<T>& menu, int pos)
{
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int i = 1;
	for (T str : menu) {
		if (i == pos) {
			SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);
			cout << str << endl;
			SetConsoleTextAttribute(hConsole, 7);
			i++;
			continue;
		}
		i++;
		cout << str << endl;
	}
	cout << "Нажмите ESC для выхода" << endl;
}
template<typename T>
inline void Interface::editOrder(list<T>& lst)
{
	int ord_id = getChoiceFromMenu(lst) - 1;
	if (ord_id < 0) return;
	auto it = lst.begin();
	for (int i = 0; i < ord_id; i++) it++;
	it->setCertainValues();
}

template<typename T>
inline void Interface::clientOrder(list<T>& lst)
{
	int ord_id = getChoiceFromMenu(lst) - 1;
	if (ord_id < 0) return;
	auto it = lst.begin();
	for (int i = 0; i < ord_id; i++) it++;
	it->getClient().tabletop();
	cout << endl << it->getClient() << endl;
}

template<typename T>
inline void Interface::deleteOrder(list<T>& lst)
{
	int ord_id = getChoiceFromMenu(lst) - 1;
	if (ord_id < 0) return;
	auto it = lst.begin();
	for (int i = 0; i < ord_id; i++) it++;
	if (input_yn(cin, "Вы уверены? y/n"))
	{
		lst.erase(it++);
	}
	while (it != lst.end()) {
		it->setId(it->getId() - 1);
		it++;
	}
}

template<typename T>
inline void Interface::saveState(Stack<list<T>>& st, list<T>& lst)
{
	if (st.size() == 5) {
		st.pop_bottom();
	}
	st.push(lst);
}

template<typename T>
inline list<T> Interface::cancelLast(Stack<list<T>>& stck, list<T>& lst)
{
	if (stck.isEmpty()) {
		cout << "Последних действий не найдено" << endl;
		return lst;
	}
	else {
		cout << "Изменение отменено" << endl;
		return stck.pop();
	}
}

template<typename T>
void Interface::workWithList(list<T>& lst, Stack<list<T>>& st)
{
	T buf;
	file_txt file;
	list<string> list_menu = {"Показать все заказы",
							  "Редактировать заказ",
							  "Добавить заказ",
							  "Удалить заказ",
							  "Информация о клиенте",
							  "Поиск по параметрам",
							  "Сортировка заказов" };
	list<T> edited;
	int lst_choice = 0, ord_id = 0;
	bool wh_flag = true;
	int num = 0;
	file.open(buf.getFileName(), 1);
	file.parseFile(lst);
	file.close();

	while (wh_flag) {
		system("cls");
		lst_choice = getChoiceFromMenu(list_menu);
		system("cls");
		switch (lst_choice) {
		case -1:
			wh_flag = false;
			break;
		case 0:
			lst = cancelLast(st, lst);
			system("pause");
			break;
		case 1:
			printTable(lst);
			system("pause");
			break;
		case 2:	
			saveState(st, lst);
			editOrder(lst);
			break;
		case 3:
			saveState(st, lst);
			addNew(lst);
			break;
		case 4:
			saveState(st, lst);
			deleteOrder(lst);
			break;
		case 5:
			clientOrder(lst);
			system("pause");
			break;
		case 6:
			edited = Algorithm_custom::searchRelevant(lst);
			printTable(edited);
			system("pause");
		case 7:
			edited = lst;
			num = 0;
			Algorithm_custom::quickSort(edited.begin(), edited.end(), T::comp, num);
			printTable(edited);
			system("pause");
		default:
			break;
		}
		
	}
	file.open("", 2);
	file.saveToFile(lst);
	file.close();

	lst.clear();
	edited.clear();
}
