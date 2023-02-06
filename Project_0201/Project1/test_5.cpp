#include <iostream>
#include <string>

int main() {
	/*

	int score;
	std::cout << "성적을 입력하세요";
	std::cin >> score;
	char grade;

	switch (score/10)
	{
	case 9:
		std::cout << "성적 : A";
		grade = 'A';
		break;
	case 8:
		std::cout << "성적 : B";
		grade = 'B';
		break;
	case 7:
		std::cout << "성적 : C";
		grade = 'C';
		break;
	case 6:
		std::cout << "성적 : D";
		grade = 'D';
		break;
	case 5:case 4:case 3:case 2:case 1:case 0:
		std::cout << "성적 F";
		grade = 'F';
		break;
	default:
		std::cout << "잘못 입력";
		break;
	}


	grade == 'F' ? std::cout << "\n재수강" : std::cout << "\n참잘했어요";


	//위의 삼항연산자와 동일
	if (grade == 'F')
		std::cout << "재수강";
	else
		std::cout << "참잘했어요";
		*/



	//홀수와 짝수 구하기 
	int num;
	std::cout << "숫자를 입력하세요";
	std::cin >> num;
	if (num%2==0)
		std::cout << "짝수입니다";
	else
		std::cout << "홀수입니다";


	(num % 2 == 0) ? std::cout << "짝수입니다" : std::cout << "홀수입니다";






}