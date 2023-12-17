#include "file_txt.h"

void file_txt::open(string fname,int mode)
{
	if(fname != "")
		filename = fname;
	this->mode = mode;
	switch (mode) {
	case 1:
		file_in = open_file_i(filename);
		break;
	case 2:
		file_out = open_file_o(filename);
		break;
	case 3:
		file_out = open_file_o(filename, 3);
		break;
	}
}

bool file_txt::feof()
{
	return file_in.eof();
}

streampos file_txt::getPos()
{
	return file_in.tellg();
}

void file_txt::setPos(streampos pos)
{
	file_in.seekg(pos);
}

void file_txt::close()
{
	if (file_in.is_open())
		close_file(file_in);
	if (file_out.is_open())
		close_file(file_out);
}
