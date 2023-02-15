#include <vector>
#include <string>
#include "Snack.h";
//using std::string;

int Snack::count = 0;

Snack::Snack(string price, string product_name, string company) {
	this->price = price;
	this->product_name = product_name;
	this->company = company;
}
void Snack::print_Snack() {};
int Snack::get_count() {
	return count;
}