#include <iostream>
using namespace std;

class Shape {
protected:
	int side_num; //변의 개수
	int length; //길이
public:
	Shape(int side_num, int length) {
		this->side_num = side_num; //변의 개수
		this->length = length; //밑변
	}
	void printInfo() {
		cout << "변의 개수 : " << side_num << " 밑변의 길이 : " << length << endl;
	}
};
class Rectangle : public Shape {
protected:
	int vertical_length; //세로길이
public:
	Rectangle(int vertical_length, int length) :Shape(4, length) {//변의 개수, 밑변의 길이
		this->vertical_length = vertical_length;
	}
	void area() {cout << "넓이 : " << this->vertical_length * length << endl;}
};
class Triangle : public Shape {
protected:
	int height; //높이 길이
public:
	Triangle(int height, int length) :Shape(3, length) { //변의 개수, 밑변의 길이
		this->height = height;
	}
	void area() {cout << "넓이 : " << (float)(this->height * length)/2.0 << endl;}
};


int main() {

	int height; //높이길이
	int vertical_length; //세로길이
	int length;


	cout << "Rectangle의 세로길이 입력 : " << endl;
	cin >> vertical_length;
	cout << "밑변의 길이 : " << endl;
	cin >> length;

	Rectangle r(vertical_length, length);
	cout << "Rectangle" << endl;
	r.area();
	r.printInfo();


	cout << "Triangle의 높이길이 입력 : " << endl;
	cin >> height;
	cout << "밑변의 길이 : " << endl;
	cin >> length;

	Triangle t(height, length);
	cout << "Triangle" << endl;
	t.area();
	t.printInfo();


	return 0;
}