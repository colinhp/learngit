 ///
 /// @file    reference.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-07 22:44:51
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
void  test0(void)
{
	int num = 100;
	int &ref = num;
	cout<< "num =  "<< num << endl;
	cout<< "ref =  "<< ref << endl;
	
	cout<< "num =  "<< &num << endl;
	cout<< "ref =  "<< &ref << endl;

	ref = 200;
	cout<< "修改引用之后："<< endl;
	cout<< "num =  "<< num << endl;
	cout<< "ref =  "<< ref << endl;

//	int &ref1;  //error  引用不能独立存在,必须要初始化
}

void swap(int &x,int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}
	

void test1(void)
{
	int a = 3,b = 4;
	cout<<"before swap() a= "<< a << "b = "<< b << endl;
	swap(a,b);
	cout<<"after swap() a= "<< a << "b = "<< b << endl;
}


int main(void)
{
	//test0();
	test1();
	return 0;
}
