 ///
 /// @file    sstream_istringstream_configuration_file.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-30 21:05:15
 ///
 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::string;

void readConfiguration(const string & filename)  //c++11写法
{
	ifstream ifs(filename); //C++11构造函数写法  iflename.c_str() C98构造函数通过
	if(!ifs)
	{
		cout << "ifstream open error!"<<endl;
		return;
	}
	string key;
	string value;
	string line;
	while(getline(ifs,line)) //文件输入流　读到字符串输入流
	{
		istringstream iss(line);
		iss >> key >> value;
		cout << key << "-->" << value <<endl;
	}

}

int main(void)
{
	readConfiguration("config.txt");

	return 0;
 
}
