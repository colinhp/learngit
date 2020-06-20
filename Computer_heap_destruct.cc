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

	~Computer()
	{
		delete [] _brand; //避免内存泄露
		cout <<"~Computer()" <<endl;
	}

	void print()
	{
		cout << "brand=" <<_brand <<endl;
		cout << "price=" <<_price <<endl;
	}

private:
	char * _brand;
	float _price;

};

//全局区对象
Computer g_c("Lenvono",8888);

int main(void)
{
	cout<<"sizeof(float) = " << sizeof(float) <<endl;
	cout<<"sizeof(Computer) = " << sizeof(Computer) <<endl;

	//栈空间
	Computer c("Mac Book",100000); //找对象，当生命周期结束时候，也会自动调用析构函数
	c.print();	

	//堆空间
	Computer *c1 = new Computer("Xiao Mi",6666); //堆对象,必须执行delete 才能回收
	c1->print();
	delete c1; //delete 操作的步骤 下面会具体讲解

	g_c.print();
	return 0;

}

