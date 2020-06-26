 ///
 /// @file    iostream_cin_get.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-26 14:07:51
 ///
 
#include <stdio.h>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
 
void test()
{
	char c;
	cout <<"enter a sentence..."<<endl;
	while((c = cin.get()) != EOF)
	{
		cout.put(c); 	
	}
}

void test0()
{
	char ch;
	cout <<"enter a sentence..."<<endl;
	while(cin.get(ch))
	{
		cout.put(ch);
	}
	cout << "end"<<endl;
}

int main(void)
{
	//test();
	test0();
	return 0;
 
}
