 ///
 /// @file    const_pointer.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-07 19:40:40
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
void test0(void)
{
	int a = 10;
	int b = 20;
	const int * pa = &a;
	pa = &b;            // ok   可以改变指向
    *pa = 30;           // error 不能更改所指变量的值
}

void  test1(void)
{
	int a = 10;
	int b = 20;
	int * const pc = &a;
	*pc = 30;  //OK
	pc = &b;   //error

}
int main(void)
{
	//test0();
	test1();
	return 0;
}
