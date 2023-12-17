#pragma once
#include "order.h"
class devOrder :
    public order
{   
    string pr_lang;     // язык программирования для программы
    int ui;             // 0 - web приложение 1 - Мобильное приложение 2 - API 3 - Оконное приложение
public:
    devOrder();
    devOrder(int id, int clientId, const string &name, double cost, int status, const string &prLang, int ui);
    devOrder(const devOrder& ord);
    string getFileName();
    string getPrLang();
    void setPrLang(string prLang);
    int getUi();
    void setUi(int ui);
    void tabletop();
    //bool comparator(int& num, devOrder& ,int sort_p = 1);
    void setCertainValues();
    devOrder& operator=(const devOrder& ord);
    bool operator>(const devOrder& ord) const;
    bool operator==(const devOrder& ord) const;
    bool operator<(const devOrder& ord) const;
    bool operator<=(const devOrder& ord) const;
    bool operator>=(const devOrder& ord) const;
    friend ostream& operator<<(ostream& out, const devOrder& ord);
    friend istream& operator>>(istream& in, devOrder& ord);
    friend ofstream& operator<<(ofstream& fout, const devOrder& ord);
    friend ifstream& operator>>(ifstream& fin, devOrder& ord);
    template<typename iterator>
    static bool comp(iterator fst, iterator scnd, int& num);
};

template<typename iterator>
inline static bool devOrder:: comp(iterator first, iterator second, int& num)
{
    if (num == 0) {
        cout << "Заполните нужные поля: \n1 - Имя заказа\n2 - Стоимость\n3 - Статус" << endl
            << "4 - Язык программирования\n5 - Интерфейс\n";
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
        retvalue = first->getPrLang() < second->getPrLang();
        break;
    case(5):
        retvalue = first->getUi() < second->getUi();
        break;
    default:
        break;
    }
    return retvalue;
}
