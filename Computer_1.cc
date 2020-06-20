 ///
 /// @file    Computer.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-15 13:23:24
 ///


#include "Computer_1.h"
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
 

void Computer::setBrand(const char * brand ) 
{
	strcpy(_brand,brand);
}
void Computer::setPrice(float price)
{
	_price = price;
}
void Computer::print()
{
	cout << "brand ="<< _brand <<endl;
	cout << "price ="<< _price <<endl;
}
