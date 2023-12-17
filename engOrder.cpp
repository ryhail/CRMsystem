#include "engOrder.h"

engOrder::engOrder()
{
    mprocessor = "UNDF";
    io_interface = "UNDF";
}

int engOrder::getNumber() const {
    return number;
}

void engOrder::setNumber(int number) {
    engOrder::number = number;
}

const string &engOrder::getMprocessor() const {
    return mprocessor;
}

string engOrder::getFileName()
{
    return "files/engorders.txt";
}

void engOrder::setMprocessor(const string &mprocessor) {
    engOrder::mprocessor = mprocessor;
}

const string &engOrder::getIoInterface() const {
    return io_interface;
}

void engOrder::setIoInterface(const string &ioInterface) {
    io_interface = ioInterface;
}

engOrder::engOrder(int id, int clientId, const string &name, double cost, int status, int number, const string &mprocessor,
                   const string &ioInterface) : order(id, clientId, name, cost, status), number(number),
                                                mprocessor(mprocessor), io_interface(ioInterface) {}

void engOrder::tabletop()
{
    dynamic_cast<order*>(this)->tabletop();
    cout << setw(6) << "Кол-во" << setw(15) << "Процессор" << setw(8) << "I/O";
}

bool engOrder::comparator(int& num, engOrder& ord, int sort_p)
{
    if (num == 0) {
        cout << "Заполните нужные поля: \n1 - Имя заказа\n2 - Стоимость\n3 - Статус" << endl
            << "4 - Микропроцессор\n5 - Интерфейс подключения\n6 - Количество плат\n";
        cin >> num;
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
        retvalue = this->mprocessor > ord.mprocessor;
        break;
    case(5):
        retvalue = this->io_interface > ord.io_interface;
        break;
    case(6):
        retvalue = this->number > ord.number;
        break;
    default:
        break;
    }
    if (sort_p)
        return retvalue;
    else
        return !retvalue;

}

void engOrder::setCertainValues()
{
    int num = 1;
    while (num) {
        cout << "Заполните нужные поля: \n0 - закончить\n1 - Имя заказа\n2 - Стоимость\n3 - Статус" << endl
            << "4 - Микропроцессор\n5 - Интерфейс подключения\n6 - Количество плат\n7 - Айди клиента\n";
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
            this->status = input_int_bord(cin, 0, 4, "Введите статус\n0 - Добавлен\n1 - Оплачен\n2 - В работе\n3 - Тестируется\n4 - Сдан: ");
            break;
        case(4):
            this->mprocessor = input_str(cin, "Введите микропроцессор: ");
            break;
        case(5):
            this->io_interface = input_str(cin, "Введите интерфейс интерфейс подключения: ");
            break;
        case(6):
            this->number = input_int(cin, "Введите количество плат: ");
            break;
        case(7):
            this->client_id = input_int(cin, "Введите Id клиента: ");
        default:
            break;
        }
        system("cls");
    }
}

engOrder& engOrder::operator=(const engOrder& ord)
{
    (order&)(*this) = (order&)ord;
    this->number = ord.number;
    this->mprocessor = ord.mprocessor;
    this->io_interface = ord.io_interface;
    return (*this);
}

bool engOrder::operator<=(const engOrder& ord) const
{
    return (engOrder&)(*this) <= (engOrder&)ord && (this->mprocessor <= ord.mprocessor || ord.mprocessor == "UNDF") && (this->io_interface <= ord.io_interface || ord.io_interface == "UNDF");
}

bool engOrder::operator>=(const engOrder& ord) const
{
    return (engOrder&)(*this) >= (engOrder&)ord && (this->mprocessor >= ord.mprocessor || ord.mprocessor == "UNDF") && (this->io_interface >= ord.io_interface || ord.io_interface == "UNDF");
}

ostream& operator<<(ostream& out, const engOrder& ord)
{
    out << (order&)ord;
    out << setw(6) << ord.number << setw(15) << ord.mprocessor << setw(8) << ord.io_interface;
    return out;
}

istream& operator>>(istream& in, engOrder& ord)
{
    in >> (order&)ord;
    ord.number = input_int(in, "Введите количество плат: ");
    ord.mprocessor = input_str(in, "Введите микропроцессор: ");
    ord.io_interface = input_str(in, "Введите интерфейс подключения: ");
    return in;
}

ofstream& operator<<(ofstream& fout, const engOrder& ord)
{
    fout << (order&)ord;
    fout << ord.number;
    fout << " " << ord.mprocessor << " " << ord.io_interface << "\n";
    return fout;
}

ifstream& operator>>(ifstream& fin, engOrder& ord)
{
    fin >> (order&)ord;
    fin >> ord.number;
    fin.get();
    fin >> ord.mprocessor;
    fin >> ord.io_interface;
    return fin;
}
