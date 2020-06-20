 ///
 /// @file    Empty.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-20 22:26:52
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
 
//编译器是自带下面的模板的
class Empty
{};

int main(void)
{ 
	cout <<"sizeof(Empty) = " <<sizeof(Empty)<<endl;
	Empty e1; //1.默认（无参）构造函数
	Empty e2;

	printf("&e1 = %p \n",&e1);
	printf("&e2 = %p \n",&e2);

	Empty e3 = e1; //2.调用拷贝构造函数
	e3 = e2; //3.赋值运算符函数

	//对象要销毁时，会调用析构函数
	return 0;

}
