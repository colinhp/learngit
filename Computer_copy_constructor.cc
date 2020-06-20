 ///
 /// @file    Computer2.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-19 15:50:16
 ///
#include <string.h> 
#include <iostream>
using std::cout;
using std::endl;
 
class Computer
{
public:
	Computer(const char * brand,float price)
	:_brand(new char[strlen(brand)+1]())
	,_price(price)
	{
		cout << "Computer(cosnst char *,float)" <<endl;
		strcpy(_brand,brand);
	}
#if 0
    //系统提供的复制构造函数	
	Computer(const Computer & rhs)
	:_brand(rhs._brand)   //浅拷贝
	,_price(rhs._price)
	{
		cout <<	"Computer(const Computer & rhs)" <<endl;
	}
#endif

	Computer(const Computer &rhs)
	:_brand(new char[strlen(rhs._brand)+1]()) //深拷贝-----先开空间在拷贝  因为在类内部可以调用私有_brand成员
	,_price(rhs._price)
	{
		cout<<"Computer(const Computer &rhs)"<<endl;
		strcpy(_brand,rhs._brand);
	}




	void print()
	{
		cout << "brand=" <<_brand <<endl;
		cout << "price=" <<_price <<endl;
	}

	~Computer()
	{
		delete [] _brand; //避免内存泄露
		cout <<"~Computer()" <<endl;
	}
private:
	char * _brand;
	float _price;

};


int main(void)
{

	Computer c("Xiaomi",9999);
	cout <<"c:";
	c.print();

	cout <<endl;

	Computer c1 = c; // Computer c1(c);
	cout <<"c1:";
	c1.print();

	return 0;

}

