#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
	int input_odd_num = 0;

	while (input_odd_num==0) { //홀수를 입력받기!
		cout << "마방진 행, 혹은 열의 수를 자연수로 입력해 주세요(홀수 입력) : ";
		cin >> input_odd_num;
		if (input_odd_num % 2 == 0 || input_odd_num <= 0) {
			cout << "0 이상의 홀수를 입력하세요" << endl;
			input_odd_num = 0;
		}
	}


	vector<vector<int> > magic_square(input_odd_num, vector<int>(input_odd_num, 0));
	int row = 0;
	int col = floor(input_odd_num / 2.0);
	magic_square[row][col] = 1;  //첫번째 행 가운데 1을 넣어주고 시작
	
	for (int i = 2; i <= pow(input_odd_num, 2); i++) {//2부터 숫자 넣어주기
		if (col + 1 == input_odd_num && row - 1 < 0) {//행과 열이 범위를 벗어났을 경우
			if (row - 1 < 0) { row = input_odd_num - 1; }
			else { row -= 1; }
			if (col + 1 == input_odd_num) { col = 0; }
			else { col += 1; }

			magic_square[row][col] = i;

			if (magic_square[row][col] != 0) {
				row = 1;
				col = input_odd_num - 1;
				magic_square[row][col] = i;
			}
			else {	magic_square[row][col] = i;	}
		}

		else if (col + 1 == input_odd_num) {//열이 범위를 벗어났을 경우 
			row -= 1;
			col = 0;
			magic_square[row][col] = i;
		}

		else if (row - 1 < 0) {//행이 범위를 벗어났을 경우
			row = input_odd_num - 1;
			col += 1;
			magic_square[row][col] = i;
		}

		else if (magic_square[row - 1][col + 1] != 0) {//채워넣으려는 곳에 이미 값이 있을 경우
			row += 1;
			magic_square[row][col] = i;
		}
		else {//오른쪽 한칸 ,위로 한칸 가서 값 넣어주기 
			row -= 1;
			col += 1;
			magic_square[row][col] = i;
		}
	}
		
	for (int j = 0; j < input_odd_num; j++) {//마방진 출력
		for (int k = 0; k < input_odd_num; k++) {
			cout << magic_square[j][k] << " ";
		}
		cout << endl;
	}
}