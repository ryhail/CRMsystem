#include "devOrder.h"

devOrder::devOrder() 
{
    this->pr_lang = "UNDF";
    this->ui = -1;
}

devOrder::devOrder(int id, int clientId, const string &name, double cost, int status, const string &prLang, int ui)
        : order(id, clientId, name, cost, status), pr_lang(prLang), ui(ui) {}

devOrder::devOrder(const devOrder& ord) : order(ord)
{
    this->pr_lang = ord.pr_lang.c_str();
    this->ui = ord.ui;
}

string devOrder::getFileName()
{
    return "files/devorders.txt";
}

string devOrder::getPrLang() {
    return pr_lang;
}

void devOrder::setPrLang(string prLang) {
    pr_lang = prLang;
}

int devOrder::getUi() {
    return ui;
}

void devOrder::setUi(int ui) {
    devOrder::ui = ui;
}

void devOrder::tabletop()
{
    dynamic_cast<order*>(this)->tabletop();
    cout << setw(10) << "���� ��." << setw(10) << "���������";

}

void devOrder::setCertainValues()
{
    int num = 1;
    while (num) {
        cout << "��������� ������ ����: \n0 - ���������\n1 - ��� ������\n2 - ���������\n3 - ������"<< endl
            << "4 - ���� ����������������\n5 - ���������\n6 - Id �������\n";
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
            this->status = input_int_bord(cin, 0, 4, "������� ������\n0 - ��������\n \
                1 - �������\n2 - � ������\n3 - �����������\n4 - ����: ");
            break;
        case(4):
            this->pr_lang = input_str_any(cin, "������� ���� ����������������: ");
            break;
        case(5):
            this->ui = input_int_bord(cin, 0, 2, "������� ���������\n0 - �������\n \
                1 - ���������\n2 - ���-����\n");
            break;
        case(6):
            this->client_id = input_int(cin, "������� Id �������");
        default:
            break;
        }
        system("cls");
    }
}

devOrder& devOrder::operator=(const devOrder& ord)
{
    (order&)(*this) = (order&)ord;
    this->pr_lang = ord.pr_lang.c_str();
    this->ui = ord.ui;
    return (*this);
}

bool devOrder::operator>(const devOrder& ord) const
{
    return (order&)(*this) > (order&)ord 
        && (this->pr_lang > ord.pr_lang || ord.pr_lang == "UNDF") 
        && (this->ui > ord.ui || ord.ui == -1);
}

bool devOrder::operator==(const devOrder& ord) const
{
    return (order&)(*this) == (order&)ord 
        && (this->pr_lang == ord.pr_lang || ord.pr_lang == "UNDF") 
        && (this->ui > ord.ui || ord.ui == -1);
}

bool devOrder::operator<(const devOrder& ord) const
{
    return (order&)(*this) < (order&)ord 
        && (this->pr_lang == ord.pr_lang || ord.pr_lang == "UNDF") 
        && (this->ui > ord.ui || ord.ui == -1);
}

bool devOrder::operator<=(const devOrder& ord) const
{
    return (order&)(*this) <= (order&)ord 
        && (this->pr_lang <= ord.pr_lang || ord.pr_lang == "UNDF") 
        && (this->ui <= ord.ui || ord.ui == -1);

}
bool devOrder::operator>=(const devOrder& ord) const
{
    return (order&)(*this) >= (order&)ord 
        && (this->pr_lang >= ord.pr_lang || ord.pr_lang == "UNDF") 
        && (this->ui >= ord.ui || ord.ui == -1);

}

ostream& operator<<(ostream& out, const devOrder& ord)
{
    out << (order&)ord;
    out << setw(10);
    out << ord.pr_lang;
    out << setw(10);
    switch (ord.ui)
    {
    case 0:
        out << "�������";
        break;
    case 1:
        out << "���������";
        break;
    case 2:
        out << "���-����";
        break;
    default:
        break;
    }
    return out;
}

istream& operator>>(istream& in, devOrder& ord)
{
    in >> (order&)ord;
    ord.pr_lang = input_str_any(in, "������� ���� ����������������: ");
    ord.ui = input_int_bord(in, 0, 2,"������� �������� ���������:\n0 - �������\n1 - ���������\n2 - ���-����: ");
    system("cls");
    return in;
}

ofstream& operator<<(ofstream& fout, const devOrder& ord)
{
    fout << (order&)ord;
    fout << ord.pr_lang << " " << ord.ui << endl;
    return fout;
}

ifstream& operator>>(ifstream& fin, devOrder& ord)
{
    fin >> (order&)ord;
    fin >> ord.pr_lang;
    fin >> ord.ui;
    return fin;
}
