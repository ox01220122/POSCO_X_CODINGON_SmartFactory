#include <iostream>
#include <vector>
#include <string>
#include "Candy.h"
#include "Snack.h"
//using std::string;
//using std::cout;
//using std::endl;


Candy::Candy(string taste, string price, string product_name, string company) : Snack::Snack(price, product_name, company) {
	this->taste = taste;
	count++;
}
void Candy::print_Snack() {
	cout << this->product_name << "Àº" << taste << "¸À »çÅÁÀÔ´Ï´Ù" << endl;
}