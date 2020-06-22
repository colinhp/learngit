 ///
 /// @file    Member_function_static.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-21 21:24:03
 ///

#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
class Computer
{
public:
	Computer(const char * brand, int price)
	:_brand(new char[strlen(brand)+1]())
	,_price(price)
	{
		cout<< "Computer(const char *brand,int price)"<< endl;
		strcpy(_brand,brand);
		_totalprice += _price;
	}

	Computer(const Computer &rhs)
	:_brand(new char[strlen(rhs._brand)]())
	,_price(rhs._price)
	{
		cout <<"Computer(const Computer &rhs)" << endl;
		strcpy(_brand,rhs._brand);
	}

	Computer & operator = (const Computer &rhs)
	{
		cout << "Computer & operator = (const Computer &rhs)" <<endl;
		if(this!= &rhs)
		{
			delete [] _brand;
			_brand = new char[strlen(rhs._brand)+1]();
			strcpy(_brand,rhs._brand);
			_price = rhs._price;

		}
		return * this;
	}

	void print(void)
	{
		cout << "brand =" << this->_brand <<endl;
		cout << "price =" << this->_price <<endl;
	}

	//静态成员函数  1.无隐含this指针所以不能访问非静态的数据成员和成员函数 2.只能访问静态数据成员和成员函数
	static void printTotalPrice()
	{	
	//	cout << "brand =" << _brand <<endl;  //error 非静态的数据成员 不能访问
	//	cout << "price =" << _price <<endl;  //error
	//	print();							 //error 非静态的成员函数 不能访问

		cout << "totalprice = " << _totalprice <<endl; //OK 可以访问静态的数据成员
	}

	~Computer()
	{
		cout << "~Computer()" << endl;
		_totalprice -= _price;
		delete [] _brand;
	}

private:
	char * _brand;
	int _price;
	static double _totalprice;

};

double Computer::_totalprice = 0;

int main(void)
{
	Computer c("Xiaomi",666);
	c.print();
	c.printTotalPrice();		 //静态成员函数 对象调用
	Computer::printTotalPrice(); //静态成员函数可以用类名调用

	cout << endl;

	Computer c1("Macbook",333);
	c1.print();

	c = c1;
	c1.print();
	c1.printTotalPrice();

	return 0;
}
