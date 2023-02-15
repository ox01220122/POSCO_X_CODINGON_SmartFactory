using namespace std;
#include <iostream>
#include <string>
class Person {
protected:
	string name;
public:
	virtual ~Person() {
		cout << "사람의 소멸자 입니다" << endl;
	}
	virtual void info() {
		cout << "사람입니다" << endl;
	}
	virtual void test() {
		cout << "사람입니다테스트" << endl;
	}
};
class Student :public Person {
private:
	string stu_id;
public:
	~Student() {
		cout << "학생의 소멸자 입니다" << endl;
	}
	void info() {
		cout << "학생 입니다" << endl;
	}
	void test() {
		cout << "학생의 test함수" << endl;
	}
};
int main() {
	Person s = Student();
	s.info(); 
	return 0;
}