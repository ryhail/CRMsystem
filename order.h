#pragma once
#include "clientCall.h"
class order :
	public clientCall
{
protected:
	double cost;
	int status; // 0 - Принят 1 - Оплачен 2 - В разработке 3 - тестируется 4 - Готов
public:
    order();
    order(int id, int clientId, string name, double cost, int status);
    order(const order& ord);
    double getCost();
    void setCost(double cost);
    int getStatus();
    void setStatus(int status);
    void tabletop();
    order& operator=(order& ord);
    bool operator>(const order& ord) const;
    bool operator==(const order& ord) const;
    bool operator<(const order& ord) const;
    bool operator<=(const order& ord) const;
    bool operator>=(const order& ord) const;
    friend ostream& operator<<(ostream& out, const order& ord);
    friend istream& operator>>(istream& in, order& ord);
    friend ofstream& operator<<(ofstream& fout, const order& ord);
    friend ifstream& operator>>(ifstream& fin, order& ord);
};

