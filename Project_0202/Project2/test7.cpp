using namespace std;
#include <iostream>
#include <string>
int main() {


	//사용자가 입력하는 숫자를 계속 더하기 

	/*

	int num=1;
	int add_num=0;

	while (num!=0)
	{
		cout << "숫자를 입력하세요";
		cin >> num;
		if (num == 0)
			break;
		else
			add_num += num;
	}

	cout << "사용자가 입력한 숫자의 합은 : " << add_num;
	*/




	int num = 1;
	int add_num = 0;

	while (num != 0)
	{
		cout << "숫자를 입력하세요";
		cin >> num;
		add_num += num;
	}
	cout << "사용자가 입력한 숫자의 합은 : " << add_num;







	return 0;
}