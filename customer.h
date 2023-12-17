#pragma once
#include "entity.h"	

class customer :
	public entity
{
	string company;
public:
	customer();
	customer(int _id);
	string getCompany();
	void setCompany(string com);
	void defineById(int id);
	void defineByMail(string mail);
	void tabletop();
	void setCertainValues();
	string getFileName();
	bool operator<=(const customer& ent) const;
	bool operator>=(const customer& ent) const;
	friend ostream& operator<<(ostream& out, const customer& ent);
	friend istream& operator>>(istream& in, customer& ent);
	friend ofstream& operator<<(ofstream& fout, const customer& ent);
	friend ifstream& operator>>(ifstream& fin, customer& ent);
};

