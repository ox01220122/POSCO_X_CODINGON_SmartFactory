using namespace std;
#include <iostream>
#include <string>
#include <vector>
int main() {

	int number=1;
	int add_ = 0;
	vector <int> add_num;

	while (number!=0)
	{
		cout << "숫자를 입력하세요 : ";
		cin >> number;
		add_num.push_back(number);
	}

	for (int i = 0; i < add_num.size(); i++)
		add_ += add_num.at(i);

	cout << "사용자가 입력한 수의 합은 : " << add_ << endl;
}