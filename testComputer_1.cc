 ///
 /// @file    testComputer_1.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-15 14:07:02
 ///
 
#include "Computer_1.h"
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	Computer c1;
	c1.setBrand("MacBook"); //.成员访问运算符
	c1.setPrice(12000);
	c1.print();


	return 0;
 
}
