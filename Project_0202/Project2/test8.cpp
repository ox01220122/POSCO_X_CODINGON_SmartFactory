using namespace std;
#include <iostream>
#include <string>
int main() {



	int num;
	cout << "숫자를 입력하세요 : ";
	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= i; j++)
			cout << "*";
		cout << endl;
	}



}