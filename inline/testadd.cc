 ///
 /// @file    testadd.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-09 11:42:27
 ///
 


#include "add.h"
#include "add.h" //单个 实体 一个.cc文件中 实际不会这样 但是引用别的头文件有可能包含add.h 加上宏定义  不会报错

#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	int a = 3, b = 4;
	cout<<"add(a+b) = "<< add(a,b) << endl;
	return 0;
}
