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
	//有参构造
	Computer(const char * brand,float price)
	:_brand(new char[strlen(brand)+1]())
	,_price(price)
	{
		cout << "Computer(const char *,float)" <<endl;
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
	//拷贝构造
	Computer(const Computer &rhs)
	:_brand(new char[strlen(rhs._brand)+1]()) //深拷贝-----先开空间在拷贝  因为在类内部可以调用私有_brand成员
	,_price(rhs._price)
	{
		cout<<"Computer(const Computer &rhs)"<<endl;
		strcpy(_brand,rhs._brand);
	}

#if 0
	//系统提供的赋值运算符函数
	Computer & operator=(const Computer &rhs)
	{
		cout<<"Computer & operator=(Computer &rhs)" <<endl;
		_brand = rhs._brand;  //隐藏this 等价于 this->_brand = rhs._brand;
		_price = rhs._price;
		return *this;
	}
#endif
	Computer & operator=(const Computer &rhs)
	{
		cout<<"Computer & operator=(Computer &rhs)" <<endl;
		
		if(this != &rhs) //比较左右操作数的地址就行
		{

			//先回收左操作数的空间
			delete [] _brand;
			
			//在进行深拷贝
			_brand = new char[strlen(rhs._brand)+1]();
			strcpy(_brand,rhs._brand);

			_price = rhs._price;

		}
		return *this;
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

//拷贝构造函数
void  test(void)
{
	Computer c("Xiaomi",9999);
	cout <<"c:";
	c.print();

	cout <<endl;

	Computer c1 = c; // Computer c1(c);
	cout <<"c1:";
	c1.print();
}
//赋值操作函数
void test1(void)
{
	Computer c1("MacBook",7777);
	cout<<"c1=";
	c1.print();

	cout<<endl;

	Computer c2("Air",8888);
	cout<<"c2=";
	c2.print();
	
	cout<<endl;
	
	c2 = c1;//还原函数完整的调用形式   c2.operator=(c1);
	cout<<"c2=";
	c2.print();

	cout <<endl;
}

int main(void)
{
	test1();
	return 0;
}




