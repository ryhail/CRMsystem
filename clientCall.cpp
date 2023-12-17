#include "clientCall.h"


clientCall::clientCall() {
    id = -1;
    client_id = -1;
    name = "UNDF";
}

clientCall::clientCall(int id, int client_id, string name) {
    this->id = id;
    this->client_id = client_id;
    this->name = name;
}

clientCall::clientCall(const clientCall &call) {
    this->id = call.id;
    this->client_id = call.client_id;
    this->name = call.name.c_str();
}

int clientCall::getId() {
    return this->id;
}

int clientCall::getClientId() {
    return this->client_id;
}

customer clientCall::getClient()
{
    return customer(client_id);
}

void clientCall::tabletop()
{
    cout << setw(4) << "ID" << setw(4) << "CID" << setw(20) << "Имя заказа";
}


clientCall& clientCall::operator=(clientCall& call)
{
    this->id = call.id;
    this->client_id = call.client_id;
    this->name = call.name.c_str();
    return (*this);
}

bool clientCall::operator>(const clientCall& call) const
{
    return ((this->name > call.name) || (call.name == "UNDF"));
}

bool clientCall::operator<(const clientCall& call) const
{
    return ((this->name < call.name) || (call.name == "UNDF"));
}

bool clientCall::operator<=(const clientCall& ord) const
{
    return ((this->name <= ord.name) || (ord.name == "UNDF"));
}

bool clientCall::operator>=(const clientCall& ord) const
{
    return ((this->name >= ord.name) || (ord.name == "UNDF"));
}

bool clientCall::operator==(const clientCall& call) const
{
    return ((this->name == call.name) || (call.name == "UNDF"));
}

string clientCall::getName() {
    return name;
}

void clientCall::setName(string name) {
    clientCall::name = name;
}

void clientCall::setId(int id) {
    clientCall::id = id;
}

void clientCall::setClientId(int clientId) {
    client_id = clientId;
}

ostream &operator<<(ostream &os, const clientCall &call) {
    os << setw(4) << call.id << setw(4) << call.client_id << setw(20) << call.name;
    return os;
}

istream& operator>>(istream& in, clientCall& call)
{
    call.name = input_str(in, "Имя заказа: ");
    system("cls");
    return in;
}

std::ofstream& operator<<(std::ofstream& os, const clientCall& call)
{
    os << call.id;
    os << " ";
    os << call.client_id << " ";
    os << call.name << "/ ";
    return os;
}

ifstream& operator>>(ifstream& in, clientCall& call)
{
    in >> call.id;
    in >> call.client_id;
    in.get();
    getline(in, call.name,'/');
    return in;
}
