#pragma once
#include "File.h"
#include <list>

class file_txt :
    public File
{
	int mode;
	ifstream file_in;
	ofstream file_out;
public:
	void open(string fname,int mode = 1);
    bool feof();
    streampos getPos();
    void setPos(streampos pos);
	template<typename T>
	void parseFile(list<T>& lst); 
	template<typename T>
	void addOneToFile(T buf);
	template<typename T>
	void saveToFile(list<T>& lst);
	void close();
};

template<typename T>
inline void file_txt::parseFile(list<T>& lst)
{
	T buf;
	while (true) {
		file_in >> buf;
		if (feof()) break;
		lst.push_back(buf);
	}
}

template<typename T>
inline void file_txt::addOneToFile(T buf)
{
	file_out.seekp(0, ios::end);
	file_out << buf;
}

template<typename T>
inline void file_txt::saveToFile(list<T>& lst)
{
	for (auto& obj : lst)
	{
		file_out << obj;
	}
}
