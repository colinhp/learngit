 ///
 /// @file    iostream_cin_status.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-26 14:56:27
 ///
 
#include <ios>
#include <stdio.h>
#include <iostream>
#include <string>
#include <limits>
using std::cout;
using std::cin;
using std::endl;
using std::string;
void printCin()
{
	cout << "cin  badbit = " << cin.bad()<<endl;
	cout << "cin  failbit = " << cin.fail()<<endl;
	cout << "cin  eofbit = " << cin.eof()<<endl;
	cout << "cin  goodbit = " << cin.good()<<endl;
}


void test()
{

	//看看天天用的两个对象的大小
	cout <<"sizeof(cout) = " << sizeof(cout)<<endl;
	cout <<"sizeof(cin) = " << sizeof(cin)<<endl;

	printCin(); //0001

	int number; 
	while(cin>>number){//.good 输入错误字符就退出了
		cout << "number  =" << number <<endl;
	}
	printCin(); //输入字母 输入有问题  failbit 置为 1  输入流检查出错   0100

	cout<< "重置流的状态"<<endl;
	cin.clear();   
	cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');  //不清空下面会被输出
	printCin();

	//cin>> number; //上面出错 cin无法重新输入 上面是输入的字符串 所有更改为string 从新试下 cin有缓冲区的 能等到上面的数据 所以要先清空
	//cout << "number  =" << number <<endl;
	string s;
	cin >> s;
	cout << "string s =" << s <<endl;
	
}

void test0()
{
	int number;
	cout <<">>please input an interger :";
	while(cin>>number, !cin.eof()) //0只有到结尾才退出,逗号表达式的使用
	{
		if(cin.bad()) // 1坏了就不能恢复了
		{
			cout <<"cin has breaken!" <<endl;
			return;
		}else if(cin.fail()){ //2错误可以恢复
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			cout <<">>please input an interger :";
			continue;
		}
		cout << "number = " <<number <<endl;
	}
	//打印流的状态看一下 Ctrl+d 之后
	printCin();
	cout<<"1111程序输入流停止但是程序还在，Ctrl+d"<<endl; //
}



int main(void)
{
	//test();
	test0();
	return 0;
}
