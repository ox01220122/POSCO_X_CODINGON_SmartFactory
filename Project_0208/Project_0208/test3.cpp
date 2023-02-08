using namespace std;
#include <stdlib.h>
#include <iostream>
#include <string> 
struct Pos{ //디폴트가 public이고 calss는 디폴트가 private이다 (구조체는 정보은닉을 기본적으로 하지 않는다 )
	int x;
	int y;
};
class Cat {   //사물에 대해 모든것을 표현할 수 있다 (실생활에 존재하는것을 프로그래밍적으로 정의한다 )
public:
	string name;
	string breed;
	int age = 0;


	//클래스의 변수를 선언할 때 생성되는 함수가 생성자  (생성자의 내용을 수정하면 public안에 있어야 한다 )
	//생성자는 여러개 있어도 된다 
	Cat() {
		name = "모름";
		breed = "모름";
		age = 1;
	}; 

	//생성자도 함수라서 여러개 선언할 수 있음. 단, 매개변수를 같게 하면 안된다 (어느것을 불러올지 모름)
	Cat(string name) {
		this->name = name;   //this사용하면 이 클래스 자체를 의미한다 (클래스 바로 하위에 있는 name을 의미한다 )
		breed = "모름";
		age = 1;
		cout << name << endl;
	};


	~Cat() {
		cout << "Cat의 인스턴스 소멸" << endl;
	}; //클래스의 변수를 소멸할 때 생성되는 함수가 소멸자 

	

	void mew() { //메소드
		cout << "야옹" << endl;
	}
	void eat() {
		cout << "생선을 먹는다" << endl;
	}
private: //정보 은닉(보안)

};


//Cat클래스의 인스턴스를 만듦
//c는 객체 라고 분리해서 설명하기도 한다 
int main() {
	Pos p = { 2,6 }; //클래스는 이런 방식이 안된다 
	
	//객체를 만들어서 생성자가 실행 된다 
	//매개변수가 있는 생성자를 사용하기 위해 문자열을 넣어주었다 
	Cat c("나비"); //정의한 cat은 객체다(클래스 틀을 이용해 만든 변수는 객체(인스턴스))
	//Cat c = Cat("나비");  //생성자를 호출한것임(위의 코드를 풀어서 쓴 것)
	//생성자는 한번만 실행된다 

	c.age = 5;

	//객체를 만들어서 생성자가 실행 된다 
	Cat c2;
	//c2.age = 3;

	//cout << c.age << " " << c2.age << endl;


	return 0;
}