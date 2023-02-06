//실습. 세 개의 수를 매개변수로 받아서 그중 가장 큰 수를 반환하는 함수 작성.

using namespace std;
#include <iostream>
#include <string>


int large_num(int a, int b, int c) {

	if (a > b && a > c)  //   c>a>b
		return a;
	else if (b > a && b > c)
		return b;
	else
		return c;
	
}




int main() {

	int a, b, c;
	cout << "숫자 세개를 입력하세요";
	cin >> a >> b >> c;

	cout << "제일 큰 수 :" << large_num(a, b, c) << endl;



	return 0;
}