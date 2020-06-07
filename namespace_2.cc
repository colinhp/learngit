 ///
 /// @file    usenamespace.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-07 10:50:09
 ///
 
#include <cstdlib>
#include <iostream>

namespace A
{
	void displayA()
	{
		std::cout << "A::displayA()"<< std::endl;
	}
}
 
using namespace A;

void cout() // OK
{
	std::cout<< "cout()" <<std::endl; 
}

int main(void)
{
	displayA();
	
	cout();
	return 0;
}
