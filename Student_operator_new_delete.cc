 ///
 /// @file    Student_operator_new_delete.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-23 12:55:49
 ///
 
#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

void * operator new (size_t sz)	 	//即使我们不定义这个函数，系统也会自动定义的
{					                        //怎么调用的不用管 但是现在不想用系统开辟空间的方式
	cout << "void * operator new(size_t)" << endl;
	void * ret = malloc(sz);
	return ret;
}

void operator delete (void *ret)
{
	free(ret);
	cout << "void operator delete(void *)" <<endl;
}

class Student
{
	public:
		Student(int id,const char *name)
		:_id(id)
		,_name(new char[strlen(name)+1]())
		{
			cout <<"Student(int ,const char*)"<<endl;
			strcpy(_name,name);
		}
		
		void print() const
		{
			cout <<"id ="<< _id<< endl;
			cout <<"name ="<< _name<< endl;
		}

		~Student()
		{
			cout << "~Student()" << endl;
			delete [] _name;
		}
#if 0
		//重定义开辟空间的方式
        static void * operator new (size_t sz)	 	//即使我们不定义这个函数，系统也会自动定义的
		{					                        //怎么调用的不用管 但是现在不想用系统开辟空间的方式
			cout << "void * operator new(size_t)" << endl;
			void * ret = malloc(sz);
			return ret;
		}

		static void operator delete (void *ret)
		{
			free(ret);
			cout << "void operator delete(void *)" <<endl;
		}
#endif
	private:
		int _id;
		char *_name;
};

class Point
{
public:
	Point()
	{
		cout <<"Point()"<<endl;
	}
	~Point()
	{
		cout <<"~Point()"<<endl;
	}
};


int main(void)
{
	Student *pstu = new Student(1,"XiaoMing"); //自己重载operator_new 操作 才能看到那个过程
	pstu->print();    //Student 有自己的开辟空间的方式
	
	delete pstu;


	cout <<endl;

	Point *p = new Point(); //Point 对象还是调用默认的堆空间开辟的方式
	delete p;

	return 0;

 
}
