#pragma once
#include <iostream>
#include <string>
#include "Snack.h"
//using std::string;
using std::cout;
using std::endl;

#ifndef __CANDY_H__  
#define __CANDY_H__ 

class Candy :public Snack {
	string taste; //¸À
public:
	Candy(string taste, string price, string product_name, string company);// : Snack(price, product_name, company) {};
	void print_Snack();
};
#endif 