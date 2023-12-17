#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "exception/input_exc.h"
#include "exception/file_exc.h"

using namespace std;
class entity
{
protected:
	int id;
	string fName;
	string sName;
	string email;
public:
	entity();
	int getId();
	void setId(int);
	string getFname();
	void setFname(string name);
	string getSname();
	void setSname(string name);
	string getEmail();
	void setEmail(string name);
	void tabletop();
	bool operator<=(const entity& ent) const;
	bool operator>=(const entity& ent) const;
	friend ostream& operator<<(ostream& out, const entity& ent);
	friend istream& operator>>(istream& in, entity& ent);
	friend ofstream& operator<<(ofstream& fout, const entity& ent);
	friend ifstream& operator>>(ifstream& fin, entity& ent);
};

