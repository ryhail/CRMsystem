#include "mainheader.h"
#include <stack>
int main()
{
    setlocale(LC_ALL, "");
    Interface app;
	
	list<devOrder> Dev; Stack<list<devOrder>> devSt;
	list<sysOrder> Sys; Stack<list<sysOrder>> sysSt;
	list<engOrder> Eng; Stack<list<engOrder>> engSt;
	list<string> mainMenu = { "Заказы ПО",
							 "Инженерные заказы",
							 "Заказы систем" };
	bool wh_flag = true;
	int mainChoice = 0;
	while (wh_flag) {
		system("cls");
		mainChoice = app.getChoiceFromMenu(mainMenu);
		switch (mainChoice) {
		case -1:
			wh_flag = false;
			break;
		case 1:
			app.workWithList(Dev, devSt);
			break;
		case 2:
			app.workWithList(Eng, engSt);
			break;
		case 3:
			app.workWithList(Sys, sysSt);
			break;
		default:
			break;
		}
	}
	
    return 0;
}
