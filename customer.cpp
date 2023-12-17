#include "customer.h"

customer::customer() {
    company = "UNDF";
}

customer::customer(int _id)
{
    int id;
    string buf;
    streampos pos;
    ifstream file = open_file_i("files/customers.txt");
    while (true) {
        pos = file.tellg();
        file >> id;
        if (file.eof()) break;
        if (id == _id) {
            file.seekg(pos);
            file >> (*this);
        }
        else {
            getline(file, buf);
        }
    }
    close_file(file);
}

string customer::getCompany()
{
    return this->company;
}

void customer::setCompany(string com)
{
    this->company = com;
}

void customer::defineById(int _id)
{
    int id;
    string buf;
    streampos pos;
    ifstream file = open_file_i("files/customers.txt");
    while (true) {
        pos = file.tellg();
        file >> id;
        if (file.eof()) break;
        if (id == _id) {
            file.seekg(pos);
            file >> (*this);
        }
        else {
            getline(file, buf);
        }
    }
    close_file(file);
}

void customer::defineByMail(string mail)
{
    string buf;
    streampos pos;
    ifstream file = open_file_i("files/customers.txt");
    while (true) {
        pos = file.tellg(); 
        file >> (*this);
        if (this->email == mail) {
            file.seekg(pos);
            break;
        }
        if (file.eof()) break;
    }
    if (file.eof())
        id = -1;
    close_file(file);
}

void customer::tabletop()
{
    entity().tabletop();
    cout <<setw(20) << "Организация";
}

void customer::setCertainValues()
{
    int num = 1;
    while (num) {
        cout << "Заполните нужные поля для клиента: \n0 - закончить\n1 - Имя\n2 - Фамилия\n3 - Электронная почта\n4 - Компания\n";
        num = input_int_bord(cin, 0, 5);
        switch (num) {
        case(0):
            break;
        case (1):
            this->fName = input_str(cin, "Введите имя: ");
            break;
        case (2):
            this->sName =input_str(cin, "Введите фамилию: ");
            break;
        case(3):
            this->email = input_email(cin, "Введите электронную почту: ");
            break;
        case(4):
            this->company = input_str(cin, "Введите название компании: ");
            break;
        default:
            break;
        }
        system("cls");
    }
}

string customer::getFileName()
{
    return "files/customers.txt";
}

bool customer::operator<=(const customer& ent) const
{
    return (entity&)(*this) <= (entity&)ent && (this->company <= ent.company || ent.company == "UNDF");
}

bool customer::operator>=(const customer& ent) const
{
    return (entity&)(*this) >= (entity&)ent && (this->company >= ent.company || ent.company == "UNDF");
}

ostream& operator<<(ostream& out, const customer& ent)
{
    out << (entity&)ent;
    out << setw(20) << ent.company;
    return out;
}

istream& operator>>(istream& in, customer& ent)
{
    in >> (entity&)ent;
    ent.company = input_str(in, "Введите название организации: ");
    return in;
}

ofstream& operator<<(ofstream& fout, const customer& ent)
{
    fout << (entity&)ent;
    fout << ent.company << endl;
    return fout;
}

ifstream& operator>>(ifstream& fin, customer& ent)
{
    fin >> (entity&)ent;
    getline(fin, ent.company, '\n');
    return fin;
}
