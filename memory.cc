 ///
 /// @file    memory.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-12 18:02:31
 ///
 
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
 

//全局变量 --- 地址多次运行都不变
int g_a = 10;
int g_b = 20;

//const修饰的全局变量----全局常量
const int c_g_a = 10;
const int c_g_b = 20;

int * func(int b)  //形参变量也存放在栈区
{
	b = 100;
	int a =10;//局部变量保存在栈区 栈区的数据 函数执行完毕自动释放
	return &a; //不要返回栈区变量的地址  
}

int * func1()
{
	//指针p本身还是局部变量 放在栈区上的  但是指针所保存的数据是放在堆区上的
	int  *p = new int(10); //利用new关键字将数据开辟到堆区
	return p;
}

void func2()
{

	//全局区---全局变量 、静态变量、 常量
	
	//普通局部变量
	
	int  a = 10;
	int  b = 20;
	cout << "局部变量a的地址:"<< (long)&a <<endl; //(int)&a  error: cast from ‘int*’ to ‘int’ loses precision [-fpermissive] 因为64位系统指针 8个字节
	
	cout << "局部变量b的地址:"<< (long)&b <<endl;

	cout << "全局变量a的地址:"<< (long)&g_a <<endl;
	cout << "全局变量b的地址:"<< (long)&g_b <<endl;

	//静态变量 --- 地址多次运行都不变

	static int s_a = 10;
	static int s_b = 20;
	cout << "静态变量a的地址:"<< (long)&s_a <<endl;
	cout << "静态变量b的地址:"<< (long)&s_b <<endl;
	
	//常量
	//字符串常量
	//const char * p = "123456"; //只读
	cout << "字符串常量的地址:"<< (long)&"hello world"<<endl;
	
	//const修饰的变量--------const修饰的局部变量/const修饰的全局变量
	
	cout << "全局常量c_g_a的地址:"<< (long)&c_g_a <<endl;
	cout << "全局常量c_g_b的地址:"<< (long)&c_g_b <<endl;


	//const修饰的局部变量----局部常量
	const int c_l_a = 10;
	const int c_l_b = 20;
	cout << "局部常量c_l_a的地址:" << (long)&c_l_a<<endl;
	cout << "局部常量c_l_b的地址:" << (long)&c_l_b<<endl;
}


int main(void)
{
	//int *p = func();   //接收func的返回值
	//cout <<*p <<endl;  //error 段错误  vs编译器第一次能输出 但是第二次就不能了
	int * p1 = func1();
	cout << *p1 << endl;

	func2();
	cout << long(&func)<<endl; //说明函数的地址 在代码区  只读

	return 0;
 
}
