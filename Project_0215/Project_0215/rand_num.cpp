using namespace std;
#include <iostream>
#include <ctime>
#include <vector>
#include <string>

void print_result(vector <int> com_num, int result_num) { //결과 출력 함수 
	cout << "당첨번호 공개!" << endl;
	for (int c : com_num) { cout << c << " "; } //출력
	cout << endl << "-----------------------------------------" << endl;
	cout << "결과 : " << result_num << "등 입니다" << endl;
}

int main() {
	srand(time(NULL));
	int rand_num = 0;
	vector <int> com_num;
	vector <int> user_num;
	int count = 0;
	int result_num = 7;


	while (count != 6) {//랜덤 숫자 생성(중복제거)
		int temp = 0;
		rand_num = (rand() % 25) + 1;  //1~25 숫자 
		if (com_num.size() != 0) {
			for (int j = 0; j < com_num.size(); j++) {
				if (com_num[j] == rand_num) { temp = 1; }
			}
		}
		if (!temp) {
			com_num.push_back(rand_num);
			count++;
		}
	}
	cout <<"랜덤 숫자가 생성되었습니다! "<<endl;

	count = 0;
	while (count != 6) {
		int temp = 0;
		cout <<count+1<< "번 숫자를 입력하세요 : ";
		cin >> rand_num;
		if (rand_num >= 1 && rand_num <= 25) {
			for (int j = 0; j < user_num.size(); j++) {
				if (user_num[j] == rand_num) {
					cout << "숫자 중복. 다시 입력하세요 !" << endl;
					temp = 1;
				}
			}
			if (!temp) {
				user_num.push_back(rand_num);
				count++;
			}
		}
		else { cout << "범위를 벗어났습니다. 다시입력" << endl; };
	}


	for (int i = 0; i < 6; i++){
		for (int j = 0; j < 6; j++) {
			if (com_num[i] == user_num[j]) { --result_num; }
		}
	}
	print_result(com_num, result_num);


	return 0;
}