 ///
 /// @file    Data_member_static.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-21 16:01:53
 ///
 
#include <cctype>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
 
class Computer
{
public:
	Computer(const char * brand,int price)
	:_brand(new char[strlen(brand)+1]())
	,_price(price)
	{
		strcpy(_brand,brand);
		_totalprice += _price;
	}

	Computer(const Computer  &rhs)
	:_brand(new char[strlen(rhs._brand)+1]())
	,_price(rhs._price)
	{
		cout<< "Computer (const Computer &rhs)"  << endl;
		strcpy(_brand,rhs._brand);
	}

	Computer & operator = (const Computer &rhs)
	{
		cout << "Computer & operator=(const Computer &rhs) " <<endl;
		if(this != &rhs)
		{
			delete [] _brand ;
			_brand = new char[strlen(rhs._brand)+1]();
			strcpy(_brand,rhs._brand);
			_price = rhs._price;

		}
		return *this;
	}

	void print(void)
	{
		cout <<"brand = "<< this->_brand <<endl;
		cout <<"price = "<< this->_price <<endl;
		cout <<"totalprice = "<< this->_totalprice <<endl;
	}

	~Computer()
	{
		cout<< "~Computer()" <<endl;
		_totalprice -= _price;
		delete [] _brand;
	}

private:
	char * _brand;  //64位操作系统 指针8个字节大小
	int _price; //改成double 可以看效果明显些 因为有字节对齐
	static int _totalprice; //被该类的所有对象所共享  在全局区  不作为对象的一部分
};

int Computer::_totalprice = 0;//静态数据成员必须在类之外进行初始化  否则会报错 未定义

void test(void)
{
	cout <<"sizeof(Computer) = " << sizeof(Computer) << endl; //8+4 16 对齐 并不占用对象的存储空间
	Computer c("Xiaomi",666);
	c.print();

	cout<< endl;

	Computer c1("Macbook",333);
	c1.print();

}

int main(void)
{
 
	test();
	return 0;
}
