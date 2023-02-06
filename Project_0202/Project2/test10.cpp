using namespace std;
#include <iostream>
#include <string>

int add(int a, int b) {
	return a + b;
}
int minus_1(int a, int b) {
	return (a > b) ? (a - b) : (b - a);
}
int multiple(int a, int b) {
	return a * b;
}
double divide(int a, int b) {
	return (double)a / (double)b;
}



int main() {

	int num1, num2;
	cout << "¼ıÀÚ µÎ°³¸¦ ÀÔ·ÂÇÏ¼¼¿ä"<<endl;
	cin >> num1 >> num2;



	int add_num = add(num1, num2);
	int minus_num = minus_1(num1,num2);
	int multiple_num = multiple(num1, num2);
	double divide_num = divide(num1, num2);


	cout << "ÇÕ : " << add_num << endl;
	cout << "Â÷ : " << minus_num << endl;
	cout << "°ö : " << multiple_num << endl;
	cout << "³ª´°¼À : " << divide_num << endl;



}

