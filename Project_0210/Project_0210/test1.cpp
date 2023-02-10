#include <iostream>
using namespace std;
class Person {
protected:
	string name;
	string position;
public:
	void test() {
		cout << "Person의 테스트 함수 입니다\n";
	}
	string get_position() { return position; }
	/*
	void get_position2() {
		cout<< position;
	}
	*/
};
class Student : public Person {
	string stu_id;
public:
	Student(string position) {
		this->position = position;
	}

	void test() {
		cout << "Student의 테스트 함수 입니다\n";
	}
	void aaa() {}
};

class Instructor : public Person {
	string stu_id;
public:
	void aaa() {}
	Instructor(string position) {
		this->position = position;
	}
};


int main() {

	//Person p;
	Person p = Person(); 
	p.test();
	//Person p2 = Student();//부모클래스로 자식(하위)클래스의 인스턴스를 만들 수 있다 
	//어떠한 공간에 모여있는 여러 사람들을 저장하기 위해서 배열을 만든다.그 공간에 모여있는 사람의 위치가 다르다
	//그 위치에 있는 사람들을 한번에 묶고 싶어서 부모클래스로 자식 클래스의 인스턴스를 만드는 것 


	//p2.test(); //부모에 test가 있어서 접근하는 것 이다 
	//p2.aaa(); 

	/*
	Person* p3 = new Student(); //동적으로 메모리를 할당할 때 new사용, Student클래스로 만들어진 객체의 주소를 가져온다
	p3->test(); //포인터는 문법이 조금 달라져서 -> 로 사용
	*/

	Person p3[4] = { Instructor("강사"), Student("학생1"), Student("학생2") ,Student("학생3")};	
	for (int i = 0; i < 4; i++){ cout << p3[i].get_position() << endl; }


	return 0;
}