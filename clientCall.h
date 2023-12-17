#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "exception/input_exc.h"
#include "customer.h"

using namespace std;

class clientCall
{
protected:
	int id;
	int client_id;
    string name;
public:
    clientCall();
    clientCall(int id, int client_id, string name);
    clientCall(const clientCall& call);
    void setId(int id);
    void setClientId(int clientId);
    string getName();
    void setName(string name);
    int getId();
    int getClientId();
    customer getClient();
    void tabletop();
    clientCall& operator=(clientCall& call);
    bool operator>(const clientCall& call) const;
    bool operator==(const clientCall& call) const;
    bool operator<(const clientCall& call) const;
    bool operator<=(const clientCall& ord) const;
    bool operator>=(const clientCall& ord) const;
    friend ostream &operator<<(ostream &os, const clientCall &call);
    friend istream &operator>>(istream& in, clientCall& call);
    friend ofstream& operator<<(ofstream& os, const clientCall& call);
    friend ifstream& operator>>(ifstream& in, clientCall& call);
};

