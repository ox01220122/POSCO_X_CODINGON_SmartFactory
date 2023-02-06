using namespace std;
#include <iostream>
#include <string>

int main() {

	/*
	int age;
	cout << "나이를 입력하세요";
	cin >> age;

	if (age >= 1 && age <= 7)
		cout << "유아";
	else if (age >= 8 && age <= 13)
		cout << "중학생";
	else if (age >= 17 && age <= 19)
		cout << "고등학생";
	else if (age >= 20 && age <= 200)
		cout << "성인";
	else
		cout << "나이가 너무 많습니다..!";
		*/



	int age;
	cout << "나이를 입력하세요";
	cin >> age;
	if (age <= 0)
		cout << "범위를 벗어났습니다" << endl;
	else
		if (age >= 1 && age <= 7)
			cout << "유아";
		else if (age >= 8 && age <= 13)
			cout << "중학생";
		else if (age >= 17 && age <= 19)
			cout << "고등학생";
		else if (age >= 20 && age <= 200)
			cout << "성인";
		else
			cout << "나이가 너무 많습니다..!";













}