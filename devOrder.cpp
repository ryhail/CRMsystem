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
    cout << setw(10) << "Язык пр." << setw(10) << "Интерфейс";

}

void devOrder::setCertainValues()
{
    int num = 1;
    while (num) {
        cout << "Заполните нужные поля: \n0 - закончить\n1 - Имя заказа\n2 - Стоимость\n3 - Статус"<< endl
            << "4 - Язык программирования\n5 - Интерфейс\n6 - Id клиента\n";
        num = input_int_bord(cin, 0, 6, "Выберите что изменить: ");
        switch (num) {
        case(0):
            break;
        case (1):
            this->name = input_str(cin, "Введите имя заказа: ");
            break;
        case (2):
            this->cost = input_dble(cin, "Введите стоимость: ");
            break;
        case(3):
            this->status = input_int_bord(cin, 0, 4, "Введите статус\n0 - Добавлен\n \
                1 - Оплачен\n2 - В работе\n3 - Тестируется\n4 - Сдан: ");
            break;
        case(4):
            this->pr_lang = input_str_any(cin, "Введите язык программирования: ");
            break;
        case(5):
            this->ui = input_int_bord(cin, 0, 2, "Введите интерфейс\n0 - Оконное\n \
                1 - Мобильное\n2 - Веб-сайт\n");
            break;
        case(6):
            this->client_id = input_int(cin, "Введите Id клиента");
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
        out << "оконное";
        break;
    case 1:
        out << "мобильное";
        break;
    case 2:
        out << "веб-сайт";
        break;
    default:
        break;
    }
    return out;
}

istream& operator>>(istream& in, devOrder& ord)
{
    in >> (order&)ord;
    ord.pr_lang = input_str_any(in, "Введите язык программирования: ");
    ord.ui = input_int_bord(in, 0, 2,"Введите интерфес программы:\n0 - Оконное\n1 - Мобильное\n2 - Веб-сайт: ");
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
