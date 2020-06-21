 ///
 /// @file    Data_member_const.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-21 15:06:57
 ///
 
#include <iostream>
#include <pthread.h>
using std::cout;
using std::endl;
 
class Point
{
public:
	Point(int ix = 0,int iy = 0)
	:_ix(ix)  //必须在这初始化
	,_iy(iy)
	{
		cout<<"Point(int,int)"<< endl;

	}

	void print(void)
	{
		cout<< "(" << this->_ix
			<< "," << this->_iy
			<< ")" << endl;
	}

	void setX( int ix)
	{
		_ix = ix;   //加上const 关键字之后 一旦对象创建完毕 是不允许修改的了
	}
	
	~Point()
	{

	}
private:
	const int _ix; //常量成员 且必须在初始化表达式中进行初始化     初始化后不能修改  这个数据就是固定的了
	const int _iy;

};

int main(void)
{
	Point p(1,2);

	p.print();

	return 0;
}
