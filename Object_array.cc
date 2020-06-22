 ///
 /// @file    Object_array.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-22 15:33:14
 ///
 
#include <iostream>
#include <pthread.h>
using std::cout;
using std::endl;
 
class Point
{
public:
	Point(int ix= 0,int iy=0)
	:_ix(ix)
	,_iy(iy)
	{
		cout << "Point (int,int)" <<endl;
	}

	void print() const 
	{
		cout << "(" << this->_ix
			 << "," << this->_iy
			 << ")" << endl;
	}
	~Point()
	{
		cout << "~Point()" << endl;
	}
private:
	int _ix;
	int _iy;
};

int main(void)
{
   //Point points[5];// 会默认创建5个对象 
    Point(1,2).print();  //这个匿名对象创建完毕马上被销毁 执行析构

	Point  points[5]={
		Point(1,2),  //匿名  Point p1(1,2); 这样是有名字的
		Point(3,4),
		Point(5,6)
	};

	points[0].print();
	points[1].print();
	points[2].print();
	points[3].print();
	points[4].print();

	return 0;
}
