 ///
 /// @file    namespace_3.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-07 16:00:25
 ///
 
#include <iostream>
using std::cout;
using std::endl;
 
int num = 1;

namespace B //声明
{
	void displayC();//命名空间中函数声明
}

namespace A
{
	int num = 10;
	void displayA()
	{
		cout << "A::displayA()"<< endl;
		B::displayC();//error  加上声明 OK
	}
	namespace C //A中嵌套C
	{
		int num = 22;
		void displayC()
		{
			cout << "A::C::num = "<< num << endl;
			cout << "A::C::displayC()" << endl;
		}
	}
}

namespace B
{
	int num = 100;
	void displayB(int num)
	{
		cout<< "B::displayB()" << endl;
		cout<< " 形参num = "<< num << endl;
		cout<< " B::num = "<< B::num << endl;
		cout<< " A::num = "<< A::num << endl;
		cout<< "全局变量num ="<< ::num << endl;//匿名的命名空间，C的库函数都是位于匿名空间
		A::displayA();//OK
	}
	void displayC()
	{
		cout<< "displayC()" << endl;
	}

}


using A::displayA;
int main(void)
{
	displayA();
	B::displayB(1000); //cout  1000

	A::C::displayC();  //命名空间的嵌套
	return 0;
}
