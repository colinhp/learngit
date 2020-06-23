 ///
 /// @file    Student_operator_new_delete_heap_only.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-23 23:46:52
 ///

//需求: 只能生成栈对象，不能生成堆对象
//解决方案: 将operator new/delete放在private区域

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

	~Student()
	{
		cout << "~Student()" << endl;
		delete [] _name;
	}

private:
	static	void * operator new (size_t sz);
	static  void  operator delete (void *ret);

private:
	int _id;
	char *_name;
};


int main(void)
{
	Student s(10,"XiaoWang"); //只能创建栈对象 
	s.print();
	
//	Student *pstu = new Student(11,"Xiaoli"); //不能创建堆对象
//	pstu->print();
//	delete pstu;

	return 0;
 
}
