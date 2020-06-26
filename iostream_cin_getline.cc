 ///
 /// @file    iostream_cin_getline.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-26 14:37:12
 ///
 
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
 
void test()
{
	char ch[20];
	cout << "enter a sentence..."<<endl;
	cin >>ch;   //不结束
	cout << "The string read with cin is "<< ch <<endl;

	cin.getline(ch,20,'/');  // 指定遇到/ 结束
	cout <<  "The second part is "<< ch <<endl;

	cin.getline(ch,20);  //函数默认遇到回车结束               读的都是ch数组中的内容
	cout << "The third part is" <<ch <<endl;

}
int main(void)
{
	test();
	return 0;
}
