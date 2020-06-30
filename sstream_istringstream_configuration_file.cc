 ///
 /// @file    sstream_istringstream_configuration_file.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-30 22:28:00
 ///
 
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;
using std::istringstream;

void readConfiguration(const string &filename)  //c++11标准　ifstream 的构造函数
{
	ifstream ifs(filename); //c++ 11 标准        文件输入流
	if(!ifs)
	{
		cout <<"ifstream open fail!" <<endl;
		return;
	}

	string key;
	string value;
	string line;
	while(std::getline(ifs,line))
	{
	   istringstream iss(line); //字符串输入流
	   iss >>key >>value;
	   cout << key << "-->" <<value << endl;
	}
}

int main(void)
{
	readConfiguration("config.txt");

	return 0;
 
}
