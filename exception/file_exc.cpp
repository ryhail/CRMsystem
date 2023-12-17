#include "file_exc.h"
using namespace std;
file_exc::file_exc(int cd, string msg, string file) : Exception(cd, msg)
{
	this->filename = file;
}

void file_exc::what_file()
{
	cout << "Error code: " << this->code << endl << this->msg << this->filename << endl;
}

file_exc::~file_exc() = default;

fstream open_file(string filename, std::ios_base::openmode mode)
{
	fstream fs;
	try {
		fs.open(filename, mode);
		if (!fs.is_open()) {
			throw file_exc(11, "File for input wasnt open: ", filename);
		}
		if (!fs.good()) {
			throw file_exc(11, "File for input wasnt open: ", filename);
		}
	}
	catch (file_exc& err) {
		err.what_file();
	}
	return fs;
}

ifstream open_file_i(string filename, std::ios_base::openmode mode)
{
	ifstream ifs;
	try {
		ifs.open(filename, mode);
		if (!ifs.is_open()) {
			throw file_exc(11, "File for input wasnt open: ", filename);
		}
		if (!ifs.good()) {
			throw file_exc(11, "File for input wasnt open: ", filename);
		}
	}
	catch (file_exc& err) {
		err.what_file();
	}

	return ifs;
}

ofstream open_file_o(string filename, std::ios_base::openmode mode)
{
	ofstream ofs;
	try {
		ofs.open(filename, mode);
		if (!ofs.is_open()) {
			throw file_exc(12, "File for output wasnt open: ", filename);
		}
	}
	catch (file_exc& err) {
		err.what_file();
	}
	return ofs;
}

