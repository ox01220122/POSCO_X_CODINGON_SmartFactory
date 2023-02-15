#include "Student.h"

Student::~Student() {
	cout << "학생의 소멸자 입니다" << endl;
}
void Student::info() {
	cout << "학생 입니다" << endl;
}
void Student::test() {
	cout << "학생의 test함수" << endl;
}