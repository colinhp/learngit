 ///
 /// @file    const.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-07 19:00:47
 ///
 
#include <ctime>
#include <iostream>
using std::cout;
using std::endl;

#define  MAX  1000
int  test0()   // C 
{
	int num =2;
	cout << num * MAX << endl;
	return 0;
}

int test1()
{
	const int value = 1; 
	cout << "value = " << value <<endl;
}

int main(void)
{
	test1();
	return 0;
}
