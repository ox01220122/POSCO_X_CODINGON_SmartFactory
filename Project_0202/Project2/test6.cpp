using namespace std;
#include <iostream>
#include <string>
int main() {

	/*
	//1부터 n까지의 합 구하기
	int a;
	int add_num = 0;
	cout << "숫자(양의 정수)를 입력하세요" << endl;
	cin >> a;
	for (int i = 1; i <= a; i++)
	{
		add_num += i;
	}
	cout << add_num;
	*/

	int a;
	int add_num = 0;
	cout << "숫자(양의 정수)를 입력하세요" << endl;
	cin >> a;
	while (a!=0)
	{
		add_num += a;
		a--;
	}
	cout << add_num;





}