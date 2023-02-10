#include <iostream>
using namespace std;
class Elec {
public:
	int a;
	virtual void on() = 0; //내용이 없는 메소드(중괄호가 =0으로 대체되었다)(추상메소드 - 순수가상함수)
	virtual void off() = 0; //꼭 필요한 기능을 강제로 하위클래스에서 정의 하기 위해 만들어 놓은 것이 추상클래스 
};
class Tv : public Elec { // 부모에서 상속받은 순수 가상함수를 구현하지 않을 경우, 자식클래스도 추상 클래스가 된다 
public:
	void on() { //필수적으로 있어야 하는 기능들을 강제하고 있다
		cout << "Tv켜기" << endl;
	}; //오버라이딩이라고 한다 (만약 구현하지 않으면 자식클래스도 추상클래스가 된다 ) 그러면 안에 함수 등도 못쓰는가? 
	void off() {
		cout << "Tv끄기" << endl;
	};
	void test(){}
};
class Radio : public Elec {
	void on() { 
		cout << "라디오 켜기" << endl;
	}; 
	void off() {
		cout << "라디오 끄기" << endl;
	};
};

int main() {
	//Elec elec; //순수 가상함수가 포함되어서 추상클래스는 객체를 생성할 수 없다 
	Tv tv; // 객체를 생성하는 문법이 아니다 
	tv.test();

	return 0;
}