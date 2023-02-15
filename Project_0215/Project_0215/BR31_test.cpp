using namespace std;
#include <iostream>
#include <string>
#include <ctime>
int main() {

	srand(time(NULL));

	int input_num, com_num;
	int num_add=0;
	bool input_end = 0, com_end = 0;
	//사용자 , 컴퓨터 순서 바뀔 때 input_num, com_num바꿔주기
	while (true)
	{
		if (com_end){
			cout << "사용자가 이겼습니다!";
			exit(1);
		}
		else if(input_end) {
			cout << "컴퓨터가 이겼습니다!";
			exit(1);
		}
		cout << "개수를 입력하세요";
		cin >> input_num;
		cout << input_num << "을 입력하셨습니다" << endl;

		if (input_num<=3 && input_num > 0)  //숫자 바뀔 때 수정
		{
			cout << "사용자가 부른 숫자"<<endl;
			for (int i = num_add + 1; i <= num_add + input_num; i++) {
				
				if (i == 31) {
					input_end = 1;
					break;
				}
				else { cout << i << endl; }
			}
			num_add += input_num;
		}
		else { 
			cout << "범위를 벗어났습니다. 다시입력하세요" << endl;
			continue; }

		if (input_end) { continue;}
		
		com_num = (rand() % 3) + 1;  //숫자 바뀔 때 수정
		cout << "컴퓨터가 부른 숫자 : " << com_num << endl;
		for (int j = num_add+1; j <= num_add+com_num; j++){
			if (j == 31) {
				com_end = 1;
				break;
			}
			else { cout << j << endl; }	
		}
		num_add += com_num;
	}
	return 0;
}