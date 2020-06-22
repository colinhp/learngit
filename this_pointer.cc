 ///
 /// @file    this_pointer.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-22 15:09:46
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class nullPointerCaller
{
public:
	static void test()
	{
		cout << "static int _iy = " << _iy << endl;
	}
	void test0()
	{
		cout << "very good" << endl;
	}
	void test1(int num)
	{
		cout << "形参num =" << num <<endl;
	}
	void test2()
	{
		cout << "非静态数据成员_ix = " << this->_ix <<endl;
	}

private:
	int _ix;
	static int _iy;
};

int nullPointerCaller::_iy = 0;

int main(void)
{
	nullPointerCaller  *p = NULL;
	p->test();       //静态成员函数没有this指针
	p->test0();      //OK 没有访问成员
	p->test1(10);    //OK 没有访问成员
	p->test2();      //ERR  this->_ix;  this 是空的 所以段错误

	return 0; 
}
