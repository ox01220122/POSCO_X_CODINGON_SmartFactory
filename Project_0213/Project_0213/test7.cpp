#include <iostream>
#include <vector>
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
	static int count;
	virtual void print_Snack() {}
	static int get_count() {
		return count;
	}
};
class Candy :public Snack {
	string taste; //맛
public:
	Candy(string taste, string price, string product_name, string company) : Snack(price, product_name, company) {
		this->taste = taste;
		count++;
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
		count++;
	}
	void print_Snack() {
		cout << this->product_name << "은" << shape << "모양 초콜릿 입니다" << endl;
	}
};

int Snack::count = 0;

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
	for (Snack* s : snacks) {s->print_Snack();}			
	//for (int i = 0; i < size; i++) {snacks.at(i)->print_Snack();}
		
	for (Snack* s : snacks) { delete s; }
	//for (int i = 0; i < size; i++) {delete snacks.at(i);}
	for (int i = 0; i < size; i++) {snacks.pop_back();}
	snacks.clear();
	


	return 0;
}