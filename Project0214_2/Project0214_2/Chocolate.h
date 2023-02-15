#pragma once
#include <iostream>
#include <string>
#include "Snack.h"
using std::string;
using std::cout;
using std::endl;

#ifndef __CHOCOLATE_H__  
#define __CHOCOLATE_H__

class Chocolate :public Snack {
	string shape;//¸ð¾ç
public:
	Chocolate(string shape, string price, string product_name, string company);// : Snack(price, product_name, company);
	void print_Snack();
};
#endif 