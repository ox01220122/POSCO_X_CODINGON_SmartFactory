#include <iostream>
#include <ctime>
using namespace std;
void F_print(int* num_counter, bool* bool_end, int creat_num , int range) { //user, 컴퓨터 숫자출력 & 숫자 카운트 
	for (int j = *num_counter + 1; j <= *num_counter + creat_num; j++) {
		cout << j << endl;
		if (j == range) {
			*bool_end = 1; //결국 32에 종료한다 
			break;
		}
	}
	*num_counter += creat_num;
}

void F_input_user(int *input_num) {//user 개수 입력받기 
	cout << "개수를 입력하세요";
	cin >> *input_num;
	cout << *input_num << "을 입력하셨습니다" << endl;
}

void F_input_com(int *com_num) {//컴퓨터 랜덤 번호 생성 
	*com_num = (rand() % 3) + 1; 
	cout << "컴퓨터가 부른 숫자 : " << *com_num << endl;
}

int main() {
	srand(time(NULL));
	int input_num = 0, com_num = 0, num_counter = 0;
	bool input_end=0, com_end=0;

	while (true){
		if (com_end) {
			cout << "사용자가 이겼습니다!";
			exit(1);
		}
		else if (input_end) {
			cout << "컴퓨터가 이겼습니다!";
			exit(1);
		}

		F_input_user(&input_num);

		if (input_num <= 3 && input_num > 0){
			F_print(&num_counter, &input_end, input_num, 32);
		}
		else {
			cout << "범위를 벗어났습니다. 다시입력하세요" << endl;
			continue;
		}
		if (input_end) { continue; } 
		F_input_com(&com_num);
		F_print(&num_counter, &com_end, com_num,32);
	}
	return 0;
}