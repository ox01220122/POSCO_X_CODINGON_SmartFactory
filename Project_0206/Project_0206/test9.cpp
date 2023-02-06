using namespace std;
#include <iostream>
#include <string>
#include <vector>
int main() {

	int num;
	float avg = 0.;
	cout << "학생 수를 입력하세요 : ";
	cin >> num;

	vector <int> vec(num);
	for (int i = 0; i < num; i++)
	{
		cout << i + 1 << "번째 학생의 성적을 입력하세요 : " << endl;
		cin >> vec[i];
		avg += vec[i];
	}

	avg = avg / (float)num;
	cout << "평균 : " << avg << endl;

}