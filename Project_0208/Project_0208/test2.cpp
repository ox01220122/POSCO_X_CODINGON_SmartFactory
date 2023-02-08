using namespace std;
#include <iostream>
struct Rectangle  //구조체와 클래스는 한가지 다른 점이 있다 
{
	float weight;
	float height;
};

int main() {
	Rectangle r;
	float a = 0.;
	cout << "가로, 세로 길이를 입력하세요"<<endl;
	cout << "가로 : ";
	cin >> r.weight;
	cout << "세로 : ";
	cin >> r.height;
	a = r.weight * r.height;
	cout << "넓이 : " << a << endl;
	return 0;
}