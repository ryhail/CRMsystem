#include "input_exc.h"

input_exc::input_exc(int code, string msg) : Exception(code, msg) {}
input_exc::~input_exc() = default;

int input_int(istream& in,string msg)
{
	int num = 0;
	int flag = true;
	cout << msg;
	do
	{
		flag = true;
		try {
			rewind(stdin);
			in >> num;
			if (in.fail() || in.peek() != '\n') {
				throw input_exc(1, "Input error, integer was expected");
			}
		}
		catch (input_exc& err)
		{
			in.clear();
			err.what();
			cout << msg;
			flag = false;
		}
	} while (!flag);
	return num;
}

int input_int_bord(istream& in, int min, int max, string msg)
{
	int num = 0;
	int flag = true;
	cout << msg;
	do
	{
		flag = true;
		try {
			rewind(stdin);
			in >> num;
			if (in.fail() || in.peek() != '\n') {
				throw input_exc(1, "Input error, integer was expected");
			}
			else if (!(num <= max && num >= min))
				throw input_exc(1, "Input error, out of borders");
		}
		catch (input_exc& err)
		{
			in.clear();
			err.what();
			cout << msg;
			flag = false;
		}
	} while (!flag);
	return num;
}

double input_dble(istream& in, string msg)
{
	double num = 0;
	int flag = true;
	cout << msg;
	do
	{
		flag = true;
		try {
			rewind(stdin);
			in >> num;
			if (in.fail() || in.peek() != '\n') {
				throw input_exc(2, "Input error, double was expected");
			}
		}
		catch (input_exc& err)
		{
			in.clear();
			err.what();
			cout << msg;
			flag = false;
		}
	} while (!flag);
	return num;
}

string input_str(istream& in, string msg)
{
	string buf;
	char buf2[100];
	bool flag = false;
	cout << msg;
	do {
		flag = true;
		try
		{
			rewind(stdin);
			in.getline(buf2, sizeof(buf2));
			buf = buf2;
			if (buf.length() == 0) {
				throw input_exc(3, "Empty string");
			}
			else if (in.gcount() != buf.length() + 1) {
				throw input_exc(4, "string is too long");
				
			}
			else 
				for (int i = 0; i < buf.length(); i++) {
					if (!((buf[i] >= 'A' && buf[i] <= 'Z') || (buf[i] >= 'a' && buf[i] <= 'z') || buf[i] == ' '))
						throw input_exc(5, "string contains restricted characters");
				}
		}
		catch (input_exc& err) {
			in.clear();
			err.what();
			cout << msg;
			flag = false;
		}
	} while (!flag);
	return buf;
}
string input_str_any(istream& in, string msg)
{
	string buf;
	char buf2[100];
	bool flag = false;
	cout << msg;
	do {
		flag = true;
		try
		{
			rewind(stdin);
			in.getline(buf2, sizeof(buf2));
			buf = buf2;
			if (buf.length() == 0) {
				throw input_exc(3, "Empty string");
			}
			else if (in.gcount() != buf.length() + 1) {
				throw input_exc(4, "string is too long");

			}
		}
		catch (input_exc& err) {
			in.clear();
			err.what();
			cout << msg;
			flag = false;
		}
	} while (!flag);
	return buf;
}
bool input_yn(istream& in,string msg)
{
	char buf;
	bool flag = false;
	cout << msg;
	do {
		flag = true;
		try {
			in >> buf;
			if (!((buf == 'y' || buf == 'n') || (buf == 'Y' || buf == 'N')))
				throw input_exc(6, "Input y or n");
			else if (in.peek() != '\n')
				throw input_exc(7, "Input only one character");
		}
		catch (input_exc& err) {
			in.clear();
			rewind(stdin);
			err.what();
			cout << msg;
			flag = false;
		}
	} while (!flag);
	if (buf == 'y')
		return true;
	else 
		return false;
}

char input_char(istream& in,string msg)
{
	char buf;
	bool flag = false;
	cout << msg;
	do {
		flag = true;
		try {
			in >> buf;
			if (in.peek() != '\n')
				throw input_exc(7, "Input only one character");
		}
		catch (input_exc& err) {
			in.clear();
			rewind(stdin);
			err.what();
			cout << msg;
			flag = false;
		}
	} while (!flag);
	return buf;
}

string input_email(istream& in, string msg)
{
	string buf;
	char buf2[100];
	bool flag = false;
	bool at_flag = false;
	cout << msg;
	do {
		flag = true;
		try
		{
			rewind(stdin);
			in.getline(buf2, sizeof(buf2));
			buf = buf2;
			if (buf.length() == 0) {
				throw input_exc(3, "Empty string");
			}
			else if (in.gcount() != buf.length() + 1) {
				throw input_exc(4, "string is too long");
			}
			else {
				for (int i = 0; i < buf.length(); i++) {
					if (buf[i] == '@')
						at_flag = true;
					else if (buf[i] == ' ')
						throw input_exc(5, "Spaces in email address");
				}
				if (at_flag == false)
					throw input_exc(5, "No @ sign");
			}
		}
		catch (input_exc& err) {
			in.clear();
			err.what();
			cout << msg;
			flag = false;
		}
	} while (!flag);
	return buf;
}
