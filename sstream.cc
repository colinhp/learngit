 ///
 /// @file    sstream.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-30 15:41:19
 ///

#include <string>
#include <sstream>
#include <iostream>
using std::cout;
using std::endl;
using std::stringstream;  //字符串输入输出流
using std::string;

void test(void)
{
	int ival = 512;
	int ival2 = 1024;
	stringstream ss;
	ss << "ival ="<< ival <<" "<<"ival2 =" <<ival2 << endl;   //1、一起输入ss内部缓冲区
	string str = ss.str();   //str()获取缓冲区数据
	cout << str <<endl;

	while(ss >> str) //2、分别输出
	{
		cout << str <<endl;
	}
}
void test0()
{
	int num1 = 10;
	int num2 = 20;
	stringstream ss;
	ss << "num1= " << num1 << "num2= "<<num2;  //加上endl 会多输出一遍  所有类型变成字符串  C中sprintf()

	string str;
	int number;
	while(!ss.eof())
	{
		ss >> str >>number;
		cout << "str: " << str <<endl;
		cout << "number: " << number <<endl;
	}
}


int main(void)
{
//	test();
	test0();

	return 0;
}
