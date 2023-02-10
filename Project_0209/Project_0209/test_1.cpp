#include <iostream>
using namespace std;

class Person {
protected:
	string name;
	string gender;
	int age = 0;
private:
public:
	Person() { //부모클래스에서 두개 이상의 생성자를 만들면 자식클래스가 호출될때 부모클래스 기본생성자가 호출
		cout << "Person 생성자 실행됨" << endl;
	}
	Person(string name) {
		this->name = name;
		cout << "Person 생성자222 실행됨" << endl;
	}

	void talk() {
		gender = "남자";
		cout << "말하기\n";
	}
	void eay() {
		cout << "먹기\n";
	}
	void sleep() {
		cout << "잠자기\n";
	}
};
class Student : public Person { //자식클래스의 생성자보다 부모클래스의 생성자가 먼저 실행이 된다 
	string stu_id;
public:
	Student() : Person("aaa") { //자식클래스의 생성자에서 부모클래스의 생성자를 선택해줄 수 있다 
		cout << "Student 생성자 실행됨" << endl;
	}

	Student(string stu_id) {
		this->stu_id = stu_id;
	}

	void study() {
		name = "학생1";
		age = 20;
		cout << "공부하기\n";
	}
	void test() {
	}
};
//상속때 퍼블릭은 한계를 지정해준다 
//보안성  pricate > protected > public
//상속의 디폴트값은 private이다 
int main() {
	Student s;
	//protected 접근제어자는 그 클래스와 클래스를 상속받은 클래스 내에서만 접근이 가능하다


	return 0;
}