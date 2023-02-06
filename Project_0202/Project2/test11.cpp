//실습. 하나의 정수를 매개변수로 받아서 그 수가 짝수이면 "짝수", 홀수이면 "홀수" 라고 출력하는 함수 작성
using namespace std;
#include <iostream>
#include <string>

std::string even_odd_numbers(int num) {
	return (num % 2 == 0) ? "짝수" : "홀수";
}

int main() {
	int num;
	cout << "숫자를 입력하세요";
	cin >> num;
	string a = even_odd_numbers(num);
	cout << a << endl;

	return 0;
}