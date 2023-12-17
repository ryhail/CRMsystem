#pragma once
#include <iostream>
#include <string>
using namespace std;
class Exception
{
protected:
	string msg;
	int code;
public:
	Exception(int, string);
	void what();
	~Exception();
};


