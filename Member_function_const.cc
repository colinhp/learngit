 ///
 /// @file    Member_function_const.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-22 12:51:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix =0,int iy=0)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "Point(int,int)" <<endl;
	}

#if 0
	void print(/*     Point * const this   */)
	{
		cout << "void print()" << endl;
		_ix =100;
		cout << "(" << this->_ix;
		cout <<","  << this->_iy;
		cout << ")" <<endl;
	}
#endif

	void setX(int ix)
	{
		_ix = ix;
	}
#if 1
	void print(/*     const Point * const this  */) const   //const 成员函数 作用：对数据成员 只读操作
	{
		//this->ix = 100;  error
		cout << "void print() const" << endl;
		cout << "(" << _ix;
		cout << "," << _iy;
		cout << ")" <<endl;

	//	setX(100);  //error  const 成员函数不能调用非const成员函数 因为非const成员函数会对成员变量就行修改的
	}
#endif 

	void func(const Point &rhs)  //这个道理相同，const 对象只能调用const函数成员 
	{
		rhs.print();
	}

	~Point()
	{

	}
private:
	int _ix;
	int _iy;

};
//有一个const成员函数的时候 既能满足const对象 要求也能满足 非const对象的要求
//我们以后写成员函数都加上const  前提是不对数据成员就行修改
void test()
{
	Point p(1,2);         //不调用const成员函数
	p.print();
	Point p0(1,2);        // 非const对象可以调用const成员函数   当只有const版本的时候  #if 0 注释掉 print()
	p0.print();

	const Point p1(3,4);  //const 对象只能调用const成员函数
	p1.print();

}


int main(void)
{
	test();
	return 0;
}
