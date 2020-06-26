 ///
 /// @file    fstream_ifstream.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-26 22:59:04
 ///


#include <fstream>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;
using std::ifstream;

void test()
{
	ifstream ifs("iostream_cin_getline.cc");
	if(!ifs)
	{
		cout << "ifstream open error!"<<endl;
		return;
	}

//	string s;
//	while(ifs>>s)
//	{
//		cout << s<<endl;   //以空格为分隔符
//	}

	string line;
	while(getline(ifs,line)) //这个getline函数是std::getline()  不是ifstream::getline()
	{
		cout << line <<endl; // 以\n 为分隔符  换行 
	}

	ifs.close();
}
int main(void)
{
    test();
	return 0;
}
