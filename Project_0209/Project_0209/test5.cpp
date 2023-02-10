/*
추상화(중복되는 부분 추출)도 해보고,
캡슐화(정보 은닉. 보안)도 고려해보고,
오늘 배운 상속까지 고려해보면서
*/

#include <iostream>
using namespace std;
class Animal {
protected:
	string breed;
	string color;
	int age;
public:
	Animal() {
		color = "black";
		age = 2;
	}
	Animal(string breed) {
		this->breed = breed;
		color = "black";
		age = 2;
	}
	 
};
class Dog :public Animal {
protected:
	int size; // 대형견, 소형견

public:
	Dog(int size) : Animal() {
		this->size = size;

	}
	Dog(int size, string breed) : Animal(breed) {


	}
};
class Cat :public Animal {
protected:

public:
};

class bird :public Animal {
protected:

public:
};

int main() {

	string breed;
	string color;
	int age;

	cout << "동물의 종을 입력하세요 : ";
	cin >> breed;
	cout << "동물의 색을 입력하세요 : ";
	cin >> color;
	cout << "동물의 나이를 입력하세요 : ";
	cin >> age;

	return 0;
}