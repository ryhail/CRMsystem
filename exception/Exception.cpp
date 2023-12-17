#include "Exception.h"

Exception::Exception(int cd, string msg)
{
	this->code = cd;
	this->msg = msg;
}

void Exception::what()
{
	cout << endl << "Îøèáêà: " << code << endl << msg << endl;
}

Exception::~Exception() = default;
