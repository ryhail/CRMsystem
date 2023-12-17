#include "entity.h"

entity::entity()
{
    id = -1;
    fName = "UNDF";
    sName = "UNDF";
    email = "UNDF";
}

int entity::getId()
{

    return this->id;
}

void entity::setId(int _id)
{
    id = _id;
}

string entity::getFname()
{
    return this->fName;
}

void entity::setFname(string name)
{
    fName = name;
}

string entity::getSname()
{
    return this->sName;
}

void entity::setSname(string name)
{
    sName = name;
}

string entity::getEmail()
{
    return this->email;
}

void entity::setEmail(string name)
{
    this->email = name;
}

void entity::tabletop()
{
    cout << setw(4) << "ID" << setw(10) << "»м€" << setw(15) << "‘амили€" << setw(30) << "Email";
}

bool entity::operator<=(const entity& ent) const
{
    return (this->id <= ent.id || ent.id == -1) && (this->fName <= ent.fName || ent.fName == "UNDF") && (this->sName <= ent.sName || ent.sName == "UNDF") && (this->email <= ent.email || ent.email == "UNDF");
}

bool entity::operator>=(const entity& ent) const
{
    return (this->id >= ent.id || ent.id == -1) && (this->fName >= ent.fName || ent.fName == "UNDF") && (this->sName >= ent.sName || ent.sName == "UNDF") && (this->email >= ent.email || ent.email == "UNDF");
}

ostream& operator<<(ostream& out, const entity& ent)
{
    out << setw(4) << ent.id << setw(10) << ent.fName << setw(15) << ent.sName << setw(30) << ent.email;
    return out;
}

istream& operator>>(istream& in, entity& ent)
{
    ent.fName = input_str(in, "¬ведите им€: ");
    ent.sName = input_str(in, "¬ведите фамилию: ");
    ent.email = input_email(in, "¬ведите почту: ");
    return in;
}

ofstream& operator<<(ofstream& fout, const entity& ent)
{
    fout << ent.id << " " << ent.fName << " " << ent.sName << " " << ent.email << " ";
    return fout;
}

ifstream& operator>>(ifstream& fin, entity& ent)
{
    fin >> ent.id;
    fin.get();
    fin >> ent.fName;
    fin.get();
    fin >> ent.sName;
    fin.get();
    fin >> ent.email;
    fin.get();
    return fin;
}
