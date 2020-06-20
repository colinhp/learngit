 ///
 /// @file    inline.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-09 11:02:18
 ///
 

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
 
#define Max(x,y)  x > y ? x: y
#define Multiply(x,y) x * y

void test0()
{

	int a = 3, b = 4;
	printf("Ma(a,b) = %d  \n",Max(a,b));

	//cout<< Max(a,b)<< endl; //error  (x>y?x:y) 加上小括号就可以使用cout OK

}
void test1()
{
	int a = 3 ,b = 4,c = 5;
	printf("Multiply(a + b, c)= %d \n",Multiply( a + b , c));  // 3+4*5 = 23  不是想要的(3+4)*5 = 35 Multiply(x,y) (x)*(y)
}

inline
int max(int x,int y)
{
	return x>y?x:y;
}

inline
int multiply(int x, int y)
{
	return x * y;
}

int main(void)
{
	test0();
	test1();

	cout << max(3,4) << endl;
	cout << multiply(3 + 4 ,5) << endl;


	return 0;
}
