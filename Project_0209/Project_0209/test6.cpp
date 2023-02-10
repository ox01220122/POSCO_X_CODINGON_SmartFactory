#include <iostream>
using namespace std;
class Student {
protected:
	string name;
	string univ;
	int age;
	string stu_id;

	void lunch() {
		cout << "Á¡½ÉÀº ÇÐ½Ä" << endl;
	}
};

class Kim :public Student {
public:
	Kim() {
		this->name = "±è¹ÎÁö1";
		this->univ = "ÇÐ±³1";
		this->age = 20;
		this->stu_id = 1234;
	}
	void lunch() {
		cout << "Á¡½ÉÀº ±è°¡³× ±è¹ä" << endl;
	}
};
class Baek :public Student {
public:
	Baek() {
		this->name = "±è¹ÎÁö2";
		this->univ = "ÇÐ±³2";
		this->age = 21;
		this->stu_id = 4321;
	}
	void lunch() {
		cout << "Á¡½ÉÀº ¹éÁ¾¿ø ÇÇÀÚ" << endl;
	}
};
int main() {

	Kim k;
	cout << "KIMÅ¬·¡½º : ";
	k.lunch();

	Baek b;
	cout << "baekÅ¬·¡½º : ";
	b.lunch();

	return 0;
}