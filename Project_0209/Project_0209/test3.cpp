#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

//private > protected > public
class Person {
protected:
	string name;
public:
	Person(string name) {
		this->name = name;
	}

	string get_name() {
		return name;
	}

	void print() {
		cout << "person print" << endl;
	}
	void show() {
		cout << "나는 사람이야 !\n";
	}
};

class Student : public Person { // 기본값 private
	string stu_id;
public:
	Student() : Person("aaaa") {
		cout << "Student 생성자 실행됨.\n";
		this->name = "홍길동";
	}
	Student(string name, string stu_id) : Person(name) {
		this->stu_id = stu_id;
	}
	Student(string name) : Person("ccccc") {  }
	Student(int a) : Person("bbbb") {  }

	string get_name() { //오버라이딩 (자식 클래스에서 재정의 하면 부모 클래스에서 더이상 쓸 수 없다)
		return name;
	}

	void print() {
		cout << "Student print" << endl;
	}
	void show() {
		cout << "나는 학생이야 !\n";
	}
};


int main() {
	/*
	Student s2; // 홍길동
	Student s4("성춘향"); // ccccc
	Student s3(1); // bbbb
	Student s("홍길동", "1111111"); // 홍길동
	cout << s3.get_name();
	*/

	Person p("민지");
	
	Student s2;
	s2.show();
	p.show();

	return 0;
}