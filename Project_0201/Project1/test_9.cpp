using namespace std;
#include <iostream>
#include <string>
int main() {


	int num1, num2;
	char a;
	std::cout << "두개의 숫자를 입력하세요";
	std::cin >> num1 >> num2;
	std::cout << "연산자를 입력하세요";
	std::cin >> a;

	switch (a)
	{
	case 43:
		std::cout << num1 + num2;
		break;
	case 45:
		std::cout << num1 - num2;
		break;
	case 42:
		std::cout << num1 * num2;
		break;
	case 47:
		std::cout << "몫 : " << num1 / num2 << "나머지 : " << num1 % num2;
		break;



	default:
		std::cout << "연산자를 잘못 입력했습니다 : ";
		break;
	}



}
