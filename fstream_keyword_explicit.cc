 ///
 /// @file    fstream_keyword_explicit.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-26 22:12:29
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
class Point
{
public:
	explicit
	Point(int ix=0,int iy=0)
	:_ix(ix)
	,_iy(iy)
	{
		cout <<"Pint(int ,int)" <<endl;
	}

	void print() const
	{
		cout << "(" << _ix
		     << "," << _iy
		     << ")" << endl;
	}

	~Point()
	{
		cout<< "~Pint()"<< endl;
	}
private:
	int _ix;
	int _iy;
};

void test()
{
	Point p = 1; //直观冲突  发生了隐式转换了  int -> Point 优化的过程看不到 -fno-elide-constructors
	p.print();
}

int main(void)
{
	test();
	return 0;
}

