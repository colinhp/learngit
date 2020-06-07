 ///
 /// @file    usenamespace.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-07 10:50:09
 ///
 
#include <iostream>
using namespace std;

namespace A
{
	void displayA()
	{
		cout<< "A::displayA()"<<endl;
	}
}
 
using namespace A;//--2--style
int main(void)
{
	//A::displayA();//--1--style
	
	displayA();
	return 0;
}
