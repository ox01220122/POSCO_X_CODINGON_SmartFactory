using namespace std;
#include <iostream>
#include <string>
int main() {
	int grade[5];
	float avg = 0.;


	for (int i = 0; i < 5; i++)
	{
		cout << i+1 << "번 학생의 성적을 입력하세요:" << endl;
		cin >> grade[i];
		avg += grade[i];
	}

	avg = avg / (sizeof(grade)/sizeof(int));
	cout << "성적평균 : " << avg;



}