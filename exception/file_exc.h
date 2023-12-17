#pragma once
#include "Exception.h"
#include <fstream>
class file_exc :
    public Exception
{
    string filename;
public:
    file_exc(int, string, string);
    void what_file();
    ~file_exc();
};
template<typename T>
void close_file(T& file) {
	try {
		if (!file.is_open()) {
			throw file_exc(13, "File isnt open, but called closing",	"");
		}
		else if (file.bad()) {
			throw file_exc(14, "Files state corrupted", "");
		}
		file.close();
	}
	catch (file_exc& err) {
		err.what_file();
	}
}

fstream open_file(string filename, std::ios_base::openmode mode = 1);
ifstream open_file_i(string filename, std::ios_base::openmode mode = 1);
ofstream open_file_o(string filename, std::ios_base::openmode mode = 2);
