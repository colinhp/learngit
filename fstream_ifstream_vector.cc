 ///
 /// @file    fstream_ifstream.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-26 22:59:04
 ///


#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::vector;


void test()
{
	ifstream ifs("iostream_cin_getline.cc");
	if(!ifs)
	{
		cout << "ifstream open error!"<<endl;
		return;
	}


	vector<string> file;
	string line;
	while(getline(ifs,line))
	{
		file.push_back(line);
		cout << line <<endl; 
	}

	for(auto &line :file)//这个line与上面那个line没有关系auto 自动推断类型
	{
		cout << line << "\n";
	}


	ifs.close();
}

int main(void)
{
    test();
	return 0;
}
