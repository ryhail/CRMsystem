#include "sysOrder.h"

const string &sysOrder::getArch() const {
    return arch;
}

void sysOrder::setArch(const string &arch) {
    sysOrder::arch = arch;
}

int sysOrder::getMaxUsers() const {
    return maxUsers;
}

void sysOrder::setMaxUsers(int maxUsers) {
    sysOrder::maxUsers = maxUsers;
}

string sysOrder::getFileName()
{
    return "files/sysorders.txt";
}

void sysOrder::tabletop()
{
    dynamic_cast<order*>(this)->tabletop();
    cout << setw(15) << "�����������" << setw(15) << "���-�� ������";
}

bool sysOrder::comparator(int& num, sysOrder& ord, int sort_p)
{
    if (num == 0) {
        cout << "��������� ������ ����: \n1 - ��� ������\n2 - ���������\n3 - ������" << endl
            << "4 - �����������\n5 - ������������ ��������� �������������\n";
        num = input_int_bord(cin, 0, 5, "");
    }
    bool retvalue = false;
    switch (num) {
    case (1):
        retvalue = (this->getName() > ord.getName());
        break;
    case (2):
        retvalue = (this->getCost() > ord.getCost());
        break;
    case(3):
        retvalue = this->getStatus() > ord.getStatus();
        break;
    case(4):
        retvalue = this->arch > ord.arch;
        break;
    case(5):
        retvalue = this->maxUsers > ord.maxUsers;
        break;
    default:
        break;
    }
    if (sort_p)
        return retvalue;
    else
        return !retvalue;
}

void sysOrder::setCertainValues()
{
    int num = 1;
    while (num) {
        cout << "��������� ������ ����: \n0 - ���������\n1 - ��� ������\n2 - ���������\n3 - ������" << endl
            << "4 - �����������\n5 - ���������� �������������\n6 - Id �������\n";
        num = input_int_bord(cin, 0, 6, "�������� ��� ��������: ");
        switch (num) {
        case(0):
            break;
        case (1):
            this->name = input_str(cin, "������� ��� ������: ");
            break;
        case (2):
            this->cost = input_dble(cin, "������� ���������: ");
            break;
        case(3):
            this->status = input_int_bord(cin, 0, 4, "������� ������\n0 - ��������\n1 - �������\n2 - � ������\n3 - �����������\n4 - ����: ");
            break;
        case(4):
            this->arch = input_str(cin, "������� �����������: ");
            break;
        case(5):
            this->maxUsers = input_int(cin, "������� ���������� �������������: ");
            break;
        case(6):
            this->client_id = input_int(cin, "������� Id �������: ");
        default:
            break;
        }
        system("cls");
    }
}

sysOrder& sysOrder::operator=(const sysOrder& ord)
{
    (order&)(*this) = (order&)ord;
    this->arch = ord.arch;
    this->maxUsers = ord.maxUsers;
    return (*this);
}

bool sysOrder::operator<=(const sysOrder& ord) const
{
    return ((order&)(*this) <= (order&)ord) && (this->arch <= ord.arch || ord.arch == "UNDF") && (this->maxUsers <= ord.maxUsers || ord.maxUsers == -1);
}

bool sysOrder::operator>=(const sysOrder& ord) const
{
    return ((order&)(*this) >= (order&)ord) && (this->arch >= ord.arch || ord.arch == "UNDF") && (this->maxUsers >= ord.maxUsers || ord.maxUsers == -1);
}

sysOrder::sysOrder()
{
    arch = "UNDF";
    maxUsers = -1;
}

sysOrder::sysOrder(int id, int clientId, const string &name, double cost, int status, const string &arch, int maxUsers)
        : order(id, clientId, name, cost, status), arch(arch), maxUsers(maxUsers) {}

ostream& operator<<(ostream& out, const sysOrder& ord)
{
    out << (order&)ord;
    out << setw(15);
    out << ord.arch;
    out << setw(15);
    out << ord.maxUsers;
    return out;
}

istream& operator>>(istream& in, sysOrder& ord)
{
    in >> (order&)ord;
    ord.arch = input_str(in, "�����������: ");
    ord.maxUsers = input_int_bord(in, 10, 10000, "������������ ����� �������������: ");
    return in;
}

ofstream& operator<<(ofstream& fout, const sysOrder& ord)
{
    fout << (order&)ord;
    fout << ord.arch << " " << ord.maxUsers << "\n";
    return fout;
}

ifstream& operator>>(ifstream& fin, sysOrder& ord)
{
    fin >> (order&)ord;
    fin >> ord.arch;
    fin >> ord.maxUsers;
    fin.get();
    return fin;
}
