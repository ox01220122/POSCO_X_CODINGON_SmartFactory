#include <iostream>
using namespace std;
//필드(변수), 메소드(함수), 생성자(메소드의 일종), 소멸자(메소드의 일종)
class Person {
	int age;
	int name;
	int* p = new int[3]; //클래스 내에서 동적 메모리를 사용하면 소멸자에서 반납하는 코드를 쓴다 
public:
	Person(){ cout << "Person 생성자 실행" << endl; }//생성자
	Person(string name) { cout << "생성자 실행" << endl; }

	void test() { cout << "test" << endl; } //메소드

	~Person() { //자동으로 호출이 된다 
		delete p;
		cout << "Person 소멸자 실행" << endl;
	} //소멸자
};
class Student : public Person {
public:
	Student() {
		cout << "Student 생성자 실행" << endl;
	}
	~Student() {
		cout << "Student 소멸자 실행" << endl;
	}
};

int main() {
	/*
	Person p("aaa");
	p.test();
	Person p2;
	//p.~Person();  ->에러남 그래서 main 안에서 호출을 하면 소멸자가 두번 호출 된다 (반납할 메모리 없어서 에러)
	*/
	Person* p1 = new Person; //Person의 인스턴스를  
	delete p1; //p1에 대한 소멸자가 이 순간에 호출이 된다 
	Student s;



	return 0;
}