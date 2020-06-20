 ///
 /// @file    Computer_1.h
 /// @author  hoping(stevenfok@126.com)
 /// @date    2020-06-15 13:58:11
 ///
#ifndef __COMPUTER_H__
#define __COMPUTER_H__

class Computer
{
public:
	void setBrand(const char *brand);
	void setPrice(float price);
	void print();
private:
	char _brand[20];
	float _price;

};

#endif
