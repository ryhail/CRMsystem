#include "order.h"

order::order(int id, int clientId, string name, double cost, int status) : clientCall(id, clientId, name),
                                                                               cost(cost), status(status) {}

order::order(const order &ord) : clientCall(ord) {
    this->cost = ord.cost;
    this->status = ord.status;
}

double order::getCost() {
    return cost;
}

void order::setCost(double cost) {
    order::cost = cost;
}

int order::getStatus() {
    return status;
}

void order::setStatus(int status) {
    order::status = status;
}

void order::tabletop()
{
    dynamic_cast<clientCall*>(this)->tabletop();
    cout << setw(12) << "Стоимость"
        << setw(10) << "Статус";
}

order& order::operator=(order& ord)
{
    (clientCall&)(*this) = (clientCall&)ord;
    this->cost = ord.cost;
    this->status = ord.status;
    return (*this);
}

bool order::operator>(const order& ord) const
{
    return (clientCall&)(*this) > ((clientCall&)ord) && (cost > ord.cost || ord.cost == -1) && (status > ord.status || ord.status == -1);
}

bool order::operator==(const order& ord) const
{
    return (clientCall&)(*this) == ((clientCall&)ord) && (cost == ord.cost || ord.cost == -1) && (status == ord.status || ord.status == -1);
}

bool order::operator<(const order& ord) const
{
    return (clientCall&)(*this) < ((clientCall&)ord) && (cost < ord.cost || ord.cost == -1) && (status < ord.status || ord.status == -1);
}

bool order::operator<=(const order& ord) const
{
    return (clientCall&)(*this) <= ((clientCall&)ord) && (cost <= ord.cost || ord.cost == -1) && (status <= ord.status || ord.status == -1);
}

bool order::operator>=(const order& ord) const
{
    return (clientCall&)(*this) >= ((clientCall&)ord) && (cost >= ord.cost || ord.cost == -1) && (status >= ord.status || ord.status == -1);
}

order::order() 
{
    cost = -1;
    status = -1;
}

ostream& operator<<(ostream& out, const order& ord)
{
    out << (clientCall&)ord;
    out << setw(11) << ord.cost << "$";
    out << setw(10);
    switch (ord.status) {
    case 0:
        out << "принят";
        break;
    case 1:
        out << "оплачен";
        break;
    case 2:
        out << "в работе";
        break;
    case 3:
        out << "тесты";
        break;
    case 4:
        out << "готов";
        break;
    default:
        break;
    }
    return out;
}

istream& operator>>(istream& in, order& ord)
{
    in >> (clientCall&)ord;
    ord.cost = input_dble(in, "Введите стоимость: ");
    ord.status = input_int_bord(in, 0, 4, "Введите статус\n0 - Добавлен\n1 - Оплачен\n2 - В работе\n3 - Тесты\n4 - Сдан: ");
    system("cls");
    return in;
}

ofstream& operator<<(ofstream& fout, const order& ord)
{
    fout << (clientCall&)ord;
    fout << ord.cost << " " << ord.status << " ";
    return fout;
}

ifstream& operator>>(ifstream& fin, order& ord)
{
    fin >> (clientCall&)ord;
    fin >> ord.cost;
    fin >> ord.status;
    fin.get();
    return fin;
}
