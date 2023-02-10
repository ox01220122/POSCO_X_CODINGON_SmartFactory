#include <iostream>
using namespace std;
class Snack {
protected:
	string price ; //가격
	string product_name ; //상품이름
	string company; //제조회사
	Snack(string price, string product_name, string company) {
		this->price = price;
		this->product_name = product_name;
		this->company = company;
	}

public:
	string get_product_name() { return product_name; } 

};
class Cnady :public Snack {
	string taste; //맛
public:
	Cnady(string taste, string price, string product_name, string company) : Snack(price, product_name, company) {
		this->taste = taste;
	}	
};
class Chocolate :public Snack {
	string shape;//모양
public:
	Chocolate(string taste, string price, string product_name, string company) : Snack(price, product_name, company) {
		this->shape = shape;
	}
};
int main() {

	string price; //가격
	string product_name; //상품이름
	string company;
	for (int i = 0; i < 4; i++)
	{
		cout << "가격: ";
		cin >> price;
		cout << "상품이름: ";
		cin >> product_name;
		cout << "제조회사: ";
		cin >> company;
		Snack s[4] = { Cnady("딸기",price,product_name,company), Cnady("사과",price,product_name,company),Chocolate("네모",price,product_name,company) ,Chocolate("세모",price,product_name,company) };
		cout << s[i].get_product_name()<<endl;
	}

	return 0;
}