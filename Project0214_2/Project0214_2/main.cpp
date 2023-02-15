#include <iostream>
#include <vector>
#include <string>
#include "Snack.h"
#include "Candy.h"
#include "Chocolate.h";
using std::cin;
using std::cout;
using std::endl;
using std::vector;


int main() {
	string price; //가격
	string product_name; //상품이름
	string company; //제조 회사 
	string taste;//맛
	string shape;//모양
	int number;
	int size;

	vector<Snack*> snacks = {};

	while (true) {
		cout << "과자 바구니에 추가할 간식을 고르세요(1: 사탕, 2: 초콜릿, 0 : 종료)" << endl;
		cin >> number;
		if (number >= 3 || number < 0) {
			cout << "0~2사이의 숫자를 입력하세요 : " << endl;
			continue;
		}
		else if (number == 0) {
			cout << "과자 바구니에 담긴 간식의 개수는" << Snack::get_count() << "개 입니다" << endl;
			cout << "과자 바구니에 담긴 간식 확인하기!" << endl;
			break;
		}
		cout << "가격: ";
		cin >> price;
		cout << "상품 이름: ";
		cin >> product_name;
		cout << "제조 회사: ";
		cin >> company;
		if (number == 1) {
			cout << "맛: ";
			cin >> taste;
			snacks.push_back(new Candy(taste, price, product_name, company));
		}
		else if (number == 2) {
			cout << "모양: ";
			cin >> shape;
			snacks.push_back(new Chocolate(shape, price, product_name, company));
		}
	}
	size = Snack::get_count();
	for (Snack* s : snacks) { s->print_Snack(); }
	//for (int i = 0; i < size; i++) {snacks.at(i)->print_Snack();}

	for (Snack* s : snacks) { delete s; }
	//for (int i = 0; i < size; i++) {delete snacks.at(i);}
	for (int i = 0; i < size; i++) { snacks.pop_back(); }
	snacks.clear();



	return 0;
}