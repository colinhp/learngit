 ///
 /// @file    Singleton_pattern.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-22 15:53:35
 ///
 

#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;
 
class Singleton
{
public:
	static Singleton*  getInstance()
	{
		if( NULL == _pInstance )
		{
			_pInstance  = new Singleton();

		}
		return _pInstance;
	}

	void print()
	{
		cout<< "print()"<< endl;
	}


	void destroy()
	{
		cout << "destroy()" <<endl;
		if(_pInstance)
		{
		    delete _pInstance;
		}
	}
private:
	Singleton()
	{
		cout <<"Singleton()" << endl;
	}
	~Singleton()
	{
		cout <<"~Singleton()" << endl;
	}
private:
	static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance = NULL;

int main(void)
{
 
	//Singleton s1;
	//Singleton s2;
	//Singleton *p  = new Singleton();
	//Singleton *p1  = new Singleton();

	//p  p1 是为了测试 输出 地址 发现是一样的
	Singleton *p =  Singleton::getInstance();
	Singleton *p1 =  Singleton::getInstance();

	//p->getInstance()->print();

	//p->getInstance()->destroy();
	
	//以后就这样创建对象 调用方法
	Singleton::getInstance()->print();
	Singleton::getInstance()->destroy();

	//printf("%p \n", &p);    这输出的是p和p1变量的地址
    //printf("%p \n", &p1);    这输出的是p和p1变量的地址
	printf("p = %p \n", p);  //这输出的是创建的对象的地址 单例模式 地址是一个
	printf("p1= %p \n", p1);

	return 0;
}
