 ///
 /// @file    fstream_ofstream.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-27 12:20:51
 ///

#include <string.h>
#include <vector> 
#include <fstream>
#include <string>
#include <iostream>
using std::cout;
using std::endl; 
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;

using std::cin;
using std::fstream;

vector<string> file;

void test(void)
{
	ifstream ifs("fstream_ifstream.cc"); //默认in
	if(!ifs)
	{
		cout << "open faile!"<<endl;
		return;
	}
	string line;
	while(std::getline(ifs,line))
	{
		file.push_back(line);
	}

	for(auto &line :file)
	{
		cout <<line <<endl;
	}
	
	ifs.close();

}

//1、默认out 模式  清空写入
void test0(void)
{
	test();

	//c++ 11
	string filename = "test.txt"; //文件不存在直接创建 存在清空在写入
	ofstream ofs(filename);

	if(!ofs)
	{
		cout<< "ofstream open error !"<<endl;
		return;
	}

	for(auto &line :file)
	{
		ofs<<line <<"\n";
	}


}

//2、std::ios::app 模式打开文件 追加写入方式
void test1(void)
{
	test();

	string filename = "test.txt";
	ofstream ofs(filename,std::ios::app);
	if(!ofs)
	{
		cout << "ofstream open error !"<<endl;
		return;
	}

	
	cout<< "pos = "<< ofs.tellp() <<endl;  //测试发现游标的位置是偏移到最后了
	string line = "this is a new line";
	ofs << line;
	cout<< "pos = "<< ofs.tellp() <<endl;
}

//3、测试下文件输入输出流   终端写入到---->文件　　　在从从文件读出到---->终端
void test2(void)
{
	fstream fs;
	fs.open("test2.txt"); //测试发现不再出错　所以要给一个存在的文件参数

	if(!fs)
	{
		cout << "fstream open error !"<<endl;
		return;
	}
	
	int number;
	for(int idx =0;idx != 5;++idx)  //１２３４５输出到　test2.txt 文件文件中
	{
		cin >>number;
		fs << number <<" ";
	}

	cout <<"pos ="<<fs.tellp()<<endl;

	fs.seekg(std::ios::beg);//偏移到文件开头　0是开头  fs.seekg(0);效果相同

	for(int idx= 0;idx != 5;++idx) // test2.text 文件中的内容　输入到终端
	{
		fs >> number;
		cout <<number << " "<<endl;
	}

	fs.close();

}

//3、测试下文件输入流ifstream的read()函数用法 将文件的信息一次性都放到字符串中
void test3(void)
{
//	ifstream ifs("test2.txt");
//	if(!ifs)
//	{
//		cout << "ifstream open fail!" <<endl;
//		return;
//	}
//
//	size_t pos = ifs.tellg();
//	cout <<pos <<endl;  // 0
//	
//	ifs.seekg(std::ios::end);
//	pos = ifs.tellg();
//
//	cout <<pos <<endl;  // 2
//
//
//	char buff[pos+1];
//	ifs.read(buff,pos+1);  //read 读取文件所有内容
//	string content(buff);  //char * 转换成ｃ++ 字符串类型
//	cout << content <<endl;
//
//	ifs.close();

	ifstream ifs("test2.txt",std::ios::ate);   //ate	seek to the end of stream immediately after open
	if(!ifs)
	{
		cout << "ifstream open fail!" <<endl;
		return;
	}

	size_t pos = ifs.tellg();
	cout <<pos <<endl;  // 10

	ifs.seekg(std::ios::beg);  //必须要回到beg才能读到数据
	cout << ifs.tellg() << endl; //0


	char buff[pos+1];
	memset(buff,0,pos+1); //不初始化后会有乱码
	ifs.read(buff,pos+1);  //read 读取文件所有内容
	string content(buff);  //char * 转换成ｃ++ 字符串类型
	cout << content <<endl;

	ifs.close();
}

int main(void)
{
	//test0();
	//test1();
	//test2();
	test3();
	return 0;
}
