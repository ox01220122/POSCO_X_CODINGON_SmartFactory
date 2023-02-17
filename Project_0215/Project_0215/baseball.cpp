#include <iostream>
#include <string>
#include <ctime>
using namespace std;
int main() {

	srand(time(NULL));
	int com_num = 0, user_num=0;
	int com_arr[3], user_arr[3];
	int strike_count=0, ball_count=0;
	
	for (int i = 0; i < 3; i++){//컴퓨터 랜덤숫자 생성 
		com_num = (rand() % 3) + 1;
		for (int c : com_arr) {
			if (c == com_num) { i--; continue; }
		}
		com_arr[i] = com_num;
	}

	int repeat=0;
	while (strike_count != 3 ) {
		strike_count = 0, ball_count = 0;
		cout << "1~9사이의 숫자 3개를 입력하시오 (이외의 숫자: 종료) " << endl;
		cin >> user_arr[0] >> user_arr[1] >> user_arr[2];

		for (int i = 0; i < 3; i++){//strike 검사 
			if (user_arr[i] <= 0 || user_arr[i] >= 10) { exit(1); } //범위 외의 숫자를 입력 시 종료

			if (com_arr[i] == user_arr[i]){	strike_count++;	}
			for (int j = 0; j < 3; j++) {//ball 검사 
				if (com_arr[i] == user_arr[j]) { ball_count++; }
			}
		}
		ball_count -= strike_count;
		cout << "strike : " << strike_count << "ball : " << ball_count << endl;
		repeat++;
	}
	cout << repeat << "만에 맞췄습니다!" << endl;


	return 0;
}