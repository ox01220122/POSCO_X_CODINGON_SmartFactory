using namespace std;
#include <iostream>
#include <string>
#include <ctime>
void F_print_user(int* pNum_count, bool* pInput_end,int* pInput_num) {
	for (int i = *pNum_count+1; i <= *pNum_count + *pInput_num; i++){
		if (i == 32) {
			*pInput_end = 1;
			break;
		}
		else { cout << i << endl; }
	}
	*pNum_count += *pInput_num;
	if (*pNum_count ==32){ *pInput_end = 1;}
}

void F_print_com(int* pNum_count, bool* pCom_end, int* pCom_num) {
	for (int j = *pNum_count + 1; j <= *pNum_count + *pCom_num; j++) {
		if (j == 31) {
			*pCom_end = 1;
			break;
		}
		else { cout << j << endl; }
	}
	*pNum_count += *pCom_num;
	if (*pNum_count == 31) { *pCom_end = 1; }
}
void F_input_user(int *input_num) {
	cout << "개수를 입력하세요";
	cin >> *input_num;
	cout << *input_num << "을 입력하셨습니다" << endl;
}
void F_input_com(int *com_num) {
	*com_num = (rand() % 3) + 1;  //숫자 바뀔 때 수정
	cout << "컴퓨터가 부른 숫자 : " << *com_num << endl;
}

int main() {

	srand(time(NULL));
	int input_num=0, com_num=0;
	int* pInput_num = &input_num, * pCom_num = &com_num;

	bool input_end=0, com_end=0;
	bool* pInput_end = &input_end, * pCom_end = &com_end;

	int num_count = 0;
	int *pNum_count = &num_count;
	

	while (true)
	{
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
			F_print_user(&num_count, &input_end, &input_num);
		}
		else {
			cout << "범위를 벗어났습니다. 다시입력하세요" << endl;
			continue;
		}

		if (input_end) { continue; }  //사용자가 바뀔 경우에 수정해주기 
		F_input_com(&com_num);
		F_print_com(&num_count, &com_end, &com_num);
	}
	return 0;
}