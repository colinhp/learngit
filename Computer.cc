 ///
 /// @file    Computer.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-15 13:23:24
 ///
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
 
class Computer
{
public:
	void setBrand(const char * brand ) //成员函数
	{
		strcpy(_brand,brand);
	}
	void setPrice(float price)
	{
		_price = price;
	}
	void print()
	{
		cout << "brand ="<< _brand <<endl;
		cout << "price ="<< _price <<endl;
	}

private:
	char _brand[20];  //数据成员
	float _price;

};

int main(void)
{
	Computer c1;
	c1.setBrand("MacBook"); //.成员访问运算符
	c1.setPrice(12000);
	c1.print();

	return 0;
 
}
