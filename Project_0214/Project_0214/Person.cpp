#include "Person.h"

int Person::count = 0;

int Person::get_count() {
	return count;
}
void Person::static_method() {
	cout << "스테틱 메소드 테스트" << endl;
}
Person::Person() {
	this->name = "아무개";
}
Person::~Person() {
	cout << "사람의 소멸자 입니다" << endl;
}
void Person::info() {
	cout << "사람입니다" << endl;
}
void Person::test() {
	cout << "사람입니다테스트" << endl;
}
void Person::set_name(string name) {
	this->name = name;
}
string Person::get_name() {
	return name;
}