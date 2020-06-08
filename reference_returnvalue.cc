 ///
 /// @file    reference_returnvalue.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-08 10:06:33
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
int arr[5]={1,2,3,4,5}; //全局数组

int & func(int idx)
{
	return arr[idx];  //返回引用无复制
}

int func1()
{

	int number =10;
	return number;    //有复制操作的
}

int & func2()   //2,3都在函数栈空间之上
{
	int number = 10;
	return number;  //不要局部变量的引用 会出错  函数结束销毁 number 是不确定的
}

int * func3()
{
	int number = 0;
	return &number; //与上同理
}

int & func4() //4开在堆空间之上,但是不要轻易返回一个堆空间变量的引用，除非有了一个回收空间的策略
{
	int *p = new int(11);
	return *p;
}

int main(void)
{
	cout<< func(0) << endl;

	func(0) = 10;
	cout<<"arr[0] = " << arr[0] << endl;

	//cout<< func2() << endl;

	int a = 3;
	int b = 4;
	int c = a + b +func4();  //问题：每调用一次fun4函数 就是产生一次内存泄露
	cout<< "C = "<< c << endl;


    //回收方案一：但是func4当做接口给别人使用的时候，是不知道要去释放空间的
	int & ref = func4();
	cout<< " &ref = "<< ref <<endl;
	delete &ref;


	return 0;
}
