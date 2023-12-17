#pragma once
#include "order.h"
class sysOrder :
    public order
{
    string arch;     //Архитектура системы
    int maxUsers;    //Максимальное количество одновременных пользователей
public:
    sysOrder();
    sysOrder(int id, int clientId, const string &name, double cost, int status, const string &arch, int maxUsers);
    const string& getArch() const;
    void setArch(const string &arch);
    int getMaxUsers() const;
    void setMaxUsers(int maxUsers);
    string getFileName();
    void tabletop();
    bool comparator(int& num, sysOrder&, int sort_p = 1);
    void setCertainValues();
    sysOrder& operator=(const sysOrder& ord);
    bool operator<=(const sysOrder& ord) const;
    bool operator>=(const sysOrder& ord) const;
    friend ostream& operator<<(ostream& out, const sysOrder& ord);
    friend istream& operator>>(istream& in, sysOrder& ord);
    friend ofstream& operator<<(ofstream& fout, const sysOrder& ord);
    friend ifstream& operator>>(ifstream& fin, sysOrder& ord);
    template<typename iterator>
    static bool comp(iterator fst, iterator scnd, int& num);
};

template<typename iterator>
inline bool sysOrder::comp(iterator first, iterator second, int& num)
{
    if (num == 0) {
        cout << "Заполните нужные поля: \n1 - Имя заказа\n2 - Стоимость\n3 - Статус" << endl
            << "4 - Архитектура\n5 - Количество пользователей\n";
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
        retvalue = first->getArch() < second->getArch();
        break;
    case(5):
        retvalue = first->getMaxUsers() < second->getMaxUsers();
        break;
    default:
        break;
    }
    return retvalue;
}
