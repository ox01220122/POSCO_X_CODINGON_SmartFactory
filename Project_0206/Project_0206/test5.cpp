using namespace std;
#include <iostream>
#include <string>
int main() {

	int num;
	float avg=0.;
	cout << "학생 수를 입력하세요 : ";
	cin >> num;

	int* num_arr = new int[num];
	for (int i = 0; i < num; i++)
	{
		cout << i + 1 << "번째 학생의 성적을 입력하세요 : " << endl;
		cin >> num_arr[i];
		avg += num_arr[i];
	}

	avg = avg / (float)num;
	cout << "평균 : " << avg << endl;

	delete[] num_arr;

}