 ///
 /// @file    Data_member_reference.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-21 15:30:02
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
	,_ref(_ix)  //如果没有初始化 会报错 引用成员必须在初始化列表中进行初始化
	{
		cout << "Point(int,int,ref)" << endl;
	}

	void print(void)
	{
		cout << "(" << _ix
			 << "," << _iy
			 << "," << _ref
			 << ")" << endl;
	}

	~Point()
	{
	}
private:
	int _ix;
	int _iy;
	int &_ref;
};


int main(void)
{
	Point p(1,2);
    p.print();	
	 
}
