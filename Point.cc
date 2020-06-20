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
#if 1 
	Point()  //默认构造函数  无参构造函数
	:_ix(0),_iy(0)    //初始化列表 C++ 特有
	{
		cout<< "Point()" <<endl;
	}

#endif
	Point(int ix, int iy)  //构造函数可以带参数  注意：只要写了自己的构造函数 系统就不会提供默认构造函数  要自己提供
	:_ix(ix),_iy(iy)       //真正的对数据成员初始化
	{
		cout<< "Point(int ,int)" <<endl;
		//_ix = ix; //赋值语句
		//_iy = iy;
	}

	void print()
	{
		cout<<"(" << _ix 
			<<"," << _iy
			<<")" << endl;
	}
private:
	int _ix;
	int _iy;
};


int main(void)
{
	Point pt;
	pt.print();

	Point pt1(1,2);
	pt1.print();

	return 0;
}
