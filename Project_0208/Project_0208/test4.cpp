using namespace std;
#include <stdlib.h>
#include <iostream>
#include <string> 
class Rectangle {
private:
	float width=0., height=0.;

public:
	Rectangle(float width, float height) {
		this->width = width;
		this->height = height;
	}
	float area() {
		return width * height;
	}


	/*
	//getter
	float get_width() { return width;}
	float get_height() { return height; }

	//setter
	void set_width(float width) { this->width = width; }
	void set_height(float height) { this->height = height; }
	*/
};



int main(){
	float weight, height;
	cout << "가로, 세로 길이를 입력하세요" << endl;
	cout << "가로 : ";
	cin >> weight;
	cout << "세로 : ";
	cin >> height;
	
	Rectangle r(weight, height);
	float area = r.area();
	cout << area << endl;


}