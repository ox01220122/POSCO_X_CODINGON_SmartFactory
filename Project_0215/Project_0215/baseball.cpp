#include <iostream>
#include <string>
#include <ctime>
using namespace std;
//사용자는 1부터 9 까지 중 3개의 숫자를 뽑아 컴퓨터가 랜덤으로 뽑은 숫자 3개와 비교(중복x)
//숫자의 자리와 값이 모두 같으면 strike
//자리는 다르지만 3개의 숫자 중 포함되어 있으면 ball
int main() {

	srand(time(NULL));
	int com_num = 0;
	int com_arr[3], user_arr[3];
	int strike_count = 0, ball_count;
	
	for (int i = 0; i < 3; i++){//컴퓨터 랜덤숫자 생성 
		com_num = (rand() % 3) + 1;
		for (int c : com_arr) {
			if (c == com_num) { i--; continue; }
		}
		com_arr[i] = com_num;
	}



	//스트라이크가 볼보다 클 경우 (스트라이크 - 볼)
	while (true){
		cout << "1~9사이의 숫자 3개를 입력하시오 (이외의 숫자: 종료) " << endl;
		cin >> user_arr[0] >> user_arr[1] >> user_arr[2];

		for (int i = 0; i < 3; i++){//strike 검사 
			if (com_arr[i] == user_arr[i]){	strike_count++;	}
			for (int j = 0; j < 3; j++) {//ball 검사 
				if(com_arr[i] == user_arr[j])
			}
		}

		


	}











	return 0;
}