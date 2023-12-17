#pragma once
#include "Exception.h"
class input_exc :
    public Exception
{
public:

    input_exc(int code, string msg);
    ~input_exc();
};
//
int input_int(istream& in, string msg="Input int: ");
int input_int_bord(istream& in, int min, int max, string msg = "Input int bord: ");
double input_dble(istream& in, string msg = "Input double: ");
string input_str(istream& in, string msg = "Input str eng: ");
string input_str_any(istream& in, string msg = "Input str any: ");
bool input_yn(istream& in, string msg = "Input y/n: ");
char input_char(istream& in, string msg = "Input char: ");
string input_email(istream& in, string msg = "Input email: ");