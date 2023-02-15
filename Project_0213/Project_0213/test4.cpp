#include <iostream>
using namespace std;
class Snack {
protected:
	string price; //가격
	string product_name; //상품이름
	string company; //제조회사
	Snack(string price, string product_name, string company) {
		this->price = price;
		this->product_name = product_name;
		this->company = company;
	}
public:
	virtual void print_Snack() {}
};
class Candy :public Snack {
	string taste; //맛
public:
	Candy(string taste, string price, string product_name, string company) : Snack(price, product_name, company) {
		this->taste = taste;
	}
	void print_Snack() {
		cout << this->product_name << "은" << taste << "맛 사탕입니다" << endl;
	}
};
class Chocolate :public Snack {
	string shape;//모양
public:
	Chocolate(string shape, string price, string product_name, string company) : Snack(price, product_name, company) {
		this->shape = shape;
	}
	void print_Snack() {
		cout << this->product_name << "은" << shape << "모양 초콜릿 입니다"<<endl;
	}
};
int main() {
	string price[4]; //가격
	string product_name[4]; //상품이름
	string company[4]; //제조 회사 
	//Snack* snackBasket[4];
	for (int i = 0; i < 4; i++){
		cout << "가격: ";
		cin >> price[i];
		cout << "상품 이름: ";
		cin >> product_name[i];
		cout << "제조 회사: ";
		cin >> company[i];

	}
	Snack*  snackBasket[4] = { new Candy("딸기",price[0],product_name[0],company[0]),new Candy("사과",price[1],product_name[1],company[1]),new Chocolate("네모",price[2],product_name[2],company[2]) ,new Chocolate("세모",price[3],product_name[3],company[3])};
	
	for (int i = 0; i < 4; i++){
		snackBasket[i]->print_Snack();
	}


	//여기서 for문 사용해서 반납하면 런타임 에러났음 
	for (int i = 0; i < 4; i++) {
		delete snackBasket[i];
	}


	return 0;
}