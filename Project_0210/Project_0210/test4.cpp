#include <iostream>
using namespace std;
class Shape {
protected:
	virtual void draw() = 0;
};
class Circle :public Shape {
public:
	void draw() {
		cout << "Circle" << endl;}
};
class Rect :public Shape {
public:
	void draw() {
		cout << "Rect" << endl;}
};
class Tria :public Shape {
public:
	void draw() {
		cout << "Tria" << endl;}
};
int main() {
	Circle c;
	c.draw();

	Rect r;
	r.draw();

	Tria t;
	t.draw();

	return 0;
}