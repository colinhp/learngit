 ///
 /// @file    Data_member_classobject.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-21 15:42:03
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	Point(int ix =0,int iy =0)
	:_ix(ix)
	,_iy(iy)
	{
		cout <<"Point(int,int)" << endl;
	}

	void print(void)
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}
	~Point()
	{

	}
private:
	int _ix;
	int _iy;

};

class Line
{
public:
	Line()   ////即使没有显示调用，也最好把这个默认构造函数写出来-- 提醒自己是有对象的创建的
	:_pt1()
	,_pt2()
	{
		cout <<"Line()" << endl;
	}
	
	Line(int x1,int y1,int x2,int y2)
	:_pt1(x1, y1)   //调用有参的构造函数   即 数据成员是对象 可以直接在初始化表达式处 调用有参构造函数
	,_pt2(x2, y2)
	{
		cout<<"Lint (int,int,int,int)" <<endl;
	}

	void printline()
	{
		_pt1.print();
		cout<<"-->";
		_pt2.print();
		cout<<endl;
	}
private:
	Point _pt1;
	Point _pt2;

};


int main(void)
{
	//Line l(1,2,3,4)

	Line line;   //没写point 也会调用point的构造函数
	line.printline();

	return 0;
}
