using namespace std;
#include <iostream>
#include <string>
#include <math.h>
int functionTestInt();
double functionDouble();
string functionStr();
int functionTestSum(int, int);
void functionTestVoid();
int result(int, int);
int result2(int, int);
void resultVoid(int, int);


int main() {
	/*
	int n = functionTestInt();
	double dou = functionDouble();

	int num = functionTestSum(2, 3);  //5
	cout << functionTestSum(2, 3)<< endl;
	cout << functionTestSum(2, 3)<< endl;

	functionTestVoid();
	


	int num1 = result(1, 2);//변수가 들어가도 되는데 int 형이어야 한다 
	int num2 = result(2, 3);
	cout << num1 + num2 << endl;
	*/

	resultVoid(1, 2);  //void형식일때는 이렇게 반환값ㅇ르 변수에 넣을 수 없다 





	return 0;
}




int functionTestInt() {
	return 5;
}
double functionDouble() {
	return 5.4;
}
string functionStr() {
	return "hello";
}


int functionTestSum(int a, int b) {
	return a + b;   //return은 반환값을 만들어 주는 것 
}


void functionTestVoid() {  //반환값이 없다 

	cout << "안녕하세요";
}
int result(int a, int b) {
	return a + b;
}
int result2(int a, int b) {
	return a + b;
}

void resultVoid(int a, int b) {
	cout << a + b << endl;
}
