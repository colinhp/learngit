 ///
 /// @file    Student_operator_new_delete_heap_only.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-23 23:46:52
 ///

//需求: 只能生成堆对象，不能生成栈对象
//解决方案: 将析构函数放在private区域

#include <stdlib.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Student
{
public:
	Student(int id,const char*name)
	:_id(id)
	,_name(new char[strlen(name)+1]())
	{
		cout<< "Student(int,const char*)" << endl;
		strcpy(_name,name);
	}
	
	void print() const
	{
		cout << "id = " << _id <<endl;
		cout << "name = " << _name <<endl;
	}

	void destroy()
	{
		//this->~Student(); 这么写不正确 没有执行operator delete 操作
		delete this;        //delete自己就可以了
	}

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
private:
	~Student()
	{
		cout << "~Student()" << endl;
		delete [] _name;
	}

private:
	int _id;
	char *_name;
};


int main(void)
{
//	Student s(10,"XiaoWang");      //不能创建栈对象 error 两种方法1：构造/析构都放private  但是构造private  new 也无法使用了 所以析构私有
//	s.print();
	
	Student *pstu = new Student(11,"Xiaoli"); //只能创建堆对象 ok
	pstu->print();
	pstu->destroy();

	//delete pstu;
	return 0;
 
}
