#pragma once
#include "order.h"
class engOrder :
    public order
{
    int number;             // Количество заказанных плат
    string mprocessor;      //Микропроцессор на плате
    string io_interface;    //интерфейс для пподключения к платe
public:
    engOrder();
    engOrder(int id, int clientId, const string &name, double cost, int status, int number, const string &mprocessor, const string &ioInterface);
    int getNumber() const;
    void setNumber(int number);
    const string &getMprocessor() const;
    string getFileName();
    void setMprocessor(const string &mprocessor);
    const string &getIoInterface() const;
    void setIoInterface(const string &ioInterface);
    void tabletop();
    bool comparator(int& num, engOrder&, int sort_p = 1);
    void setCertainValues();
    engOrder& operator=(const engOrder& ord);
    bool operator<=(const engOrder& ord) const;
    bool operator>=(const engOrder& ord) const;
    friend ostream& operator<<(ostream& out, const engOrder& ord);
    friend istream& operator>>(istream& in, engOrder& ord);
    friend ofstream& operator<<(ofstream& fout, const engOrder& ord);
    friend ifstream& operator>>(ifstream& fin, engOrder& ord);
    template<typename iterator>
    static bool comp(iterator fst, iterator scnd, int& num);
};

template<typename iterator>
inline static bool engOrder::comp(iterator first, iterator second, int& num)
{
    if (num == 0) {
        cout << "Заполните нужные поля: \n1 - Имя заказа\n2 - Стоимость\n3 - Статус" << endl
            << "4 - Количество плат\n5 - Микропроцессор\n6 - Интерфейс подключения\n";
        num = input_int_bord(cin, 1, 5, "");
    }
    bool retvalue = false;
    switch (num) {
    case (1):
        retvalue = (first->getName() < second->getName());
        break;
    case (2):
        retvalue = (first->getCost() < second->getCost());
        break;
    case(3):
        retvalue = first->getStatus() < second->getStatus();
        break;
    case(4):
        retvalue = first->getNumber() < second->getNumber();
        break;
    case(5):
        retvalue = first->getMprocessor() < second->getMprocessor();
        break;
    case(6):
        retvalue = first->getIoInterface() < second->getIoInterface();
        break;
    default:
        break;
    }
    return retvalue;
}
