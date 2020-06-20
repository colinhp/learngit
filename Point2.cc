 ///
 /// @file    Point.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-18 12:08:08
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 

class Point
{
public:
	Point()
	:_ix(0)
	,_iy(0)
	{
		cout<< "Point()" <<endl;
	}

	Point(int ix, int iy)
	:_ix(ix),_iy(iy)
	{
		cout<< "Point(int ,int)" <<endl;
	}

	void print()
	{
		cout<<"(" << _ix 
			<<"," << _iy
			<<")" << endl;
	}

	~Point() //系统提供的析构函数
	{
		cout<< "~Point()" <<endl;
	}
private:
	int _ix;
	int _iy;
};


void test(void)
{
	Point pt;
	pt.print();

	Point pt1(1,2); //栈上对象被销毁时就会自动调用析构函数
	pt1.print();


}

int main(void)
{

	test();
	return 0;
}
