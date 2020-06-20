 ///
 /// @file    string.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-09 12:59:47
 ///


#include "string.h" //C 风格的字符串
#include "stdlib.h"

#include <iostream>
#include <string>  //C++ 风格 字符串
using std::cout;
using std::endl;
using std::string;


void test0()  //C字符串拼接 这个方法会越界
{
	char str1[] = "hello world";  //字符数组
	char str2[100] = "shenzhen";

	cout <<"sizeof(str1) = " <<sizeof(str1) << endl; // 12 '\0'
	cout <<"strlen(str1) = " <<strlen(str1) << endl; // 11
	strcat(str1,str2);                                          //str1 拼接后会越界
	cout <<"str1 = " << str1 <<endl;

	const char * str3 = "welcome to string";   //C风格的字符串类型 
	cout << "str3 = "<< str3 << endl;


	//遍历数组中的内容---会多出个s
	for(int idx = 0; idx != sizeof(str1); ++idx)
	{
		cout << str1[idx] << endl;
	}
}
 
void test1() //C字符串拼接 新开辟空间  考虑很多问题
{
	char str1[] = "hello world";
	char str2[100] = "shenzhen";
	
	int len = strlen(str1) + strlen(str2) + 1;
	char * pstr = (char *)malloc(len);                                      //    char * pstr = new char(len);
	memset(pstr,0,len);
	strcpy(pstr,str1);
	strcat(pstr,str2);
	cout<< "pstr = "<< pstr << endl;

	//遍历数组中的内容 --无s 有个空行  \0 输出就是个行
	for(int idx = 0; idx != sizeof(str1); ++idx)
	{
		cout << str1[idx] << endl;
	}

	free(pstr);
}

void test2() //C++ 风格 字符串拼接
{
	string s1 ="hello world";   //C 风格字符串转换成C++ 风格的字符串  还可以用()的方式获取个字符串 string s4("aaa");
	string s2 ="shenzhen";
	
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;

	string s3 = s1 + s2;    //----1
	cout<<"sizeof(string) = "<< sizeof(string)<< endl; //32
	cout<<"string s3 = "<< s3 << endl;

	string s4 = s1 + "shenzhen";  // ------2
	cout << "s4 = " << s4 << endl;
	
	string s5 = "hello world" + s2; //-------3
	cout << "s5 = " << s5 << endl;  

	string s6 = s1 + 'A';   //也可以加个字符-------4
	cout << "s6 = " << s6 << endl;

	s1.append(s2); //成员函数 实现字符串拼接   //------5
	cout << "s1 = " << s1 << endl;

	//遍历string
	
	int len = s1.size();  //---1
	cout << "s1's length =" << len << endl;

	len  = s1.length();  //---2
	cout << "s1's length =" << len << endl;

	for(int idx = 0; idx != len; ++idx)
	{
		cout << s1[idx] << endl; //数组下标访问
	}

	const char * pdata = s1.c_str();             //----1 C++风格字符串转换成C 风格的字符串 因为 strcpy()等函数 都是用到 const char * 

	cout << "pdata[1] = " << pdata[1]<< endl;

	const char * pdata1 = s1.data();             //----2 C++风格字符串转换成C 风格的字符串  这样风格转换完 就可已传给C风格的函数当作参数了 
	cout << "pdata1[1] = " << pdata1[1]<< endl;
	

	//截取子串
	string s7 = s1.substr(); //输出串本身
	cout << "s7 = " << s7 << endl;
	
	string s8 = s1.substr(6,5); //截取world
	cout << "s8 = " << s8 << endl;

	//查找子串
	int pos = s1.find("world");
	cout << "pos = " << pos << endl;

	string s9 = s1.substr(pos,5); //  string s9 = s1.substr(s1.find("world"),5);   find 与 substr 结合使用
	cout << "s9 = " << s9 << endl;

	//比较字符串是否相等 c中 strcmp	
	cout <<"if (s1 == s2): " << (s1 == s2) << endl;
	cout <<"if (s3 == s4): " << (s3 == s4) << endl;

}

int main(void)
{
	//test0();
	//test1();
	test2();
	return 0;
}
