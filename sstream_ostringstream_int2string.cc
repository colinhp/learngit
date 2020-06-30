 ///
 /// @file    sstream_ostringstream_int2string.cc
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-30 20:03:16
 ///
 
#include <iostream>
#include <sstream>
#include <string>
using std::cout;
using std::endl;
using std::stringstream;
using std::ostringstream;
using std::string;

string int2string(int num)
{
	ostringstream oss;
    oss << num;
	return oss.str();
}

int main(void)
{
	int num =10;
	cout << int2string(num) << endl;
	return 0;
}
