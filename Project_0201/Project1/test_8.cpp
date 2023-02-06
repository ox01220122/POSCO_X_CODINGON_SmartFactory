using namespace std;
#include <iostream>
#include <string>

int main() {

	int num;
	std::cout << "숫자를 입력하세요";
	std::cin >> num;


	
	(num % 5 == 0)? std::cout << num << "는 5의 배수 입니다": std::cout << num << "는 5의 배수가 아니네요";

}