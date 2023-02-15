#pragma once
#include <iostream>
#include <string>
using std::string;

#ifndef __SNACK_H__  
#define __SNACK_H__ 

class Snack {
protected:
	string price; //가격
	string product_name; //상품이름
	string company; //제조회사
	Snack(string price, string product_name, string company);
public:
	static int count;
	virtual void print_Snack();
	static int get_count();
};


#endif 
