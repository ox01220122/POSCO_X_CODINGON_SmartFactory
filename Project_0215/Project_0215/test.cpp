#include<iostream>
#include<string>

using namespace std;

int main() {
	int num, standard;

	while (1) {
		cout << "마방진의 행 혹은 열의 수를 자연수로 입력해주세요: ";
		cin >> num;
		if (num % 2 == 0) {
			cout << "홀수를 입력하세요\n";
		}
		else { break; }
	}
	int** num_arr = new int* [num];
	for (int i = 0; i < num; i++) {
		num_arr[i] = new int[num](); // 0으로 초기화~!
	}
	num_arr[0][num / 2] = 1;
	standard = num_arr[0][num / 2];
	int x = 0, y = num / 2;
	for (int i = 1; i < num * num; i++) {
		standard += 1;
		x -= 1;
		y += 1;
		if (x == -1) {
			x = num - 1;
		}
		if (y == num) {
			y = 0;
		}
		if (num_arr[x][y] != 0) {
			if (y == 0) {
				y = num - 1;
				if (x == num - 1) {
					x = 1;
				}
			}
			else {
				x += 2;
				y -= 1;
			}
		}
		num_arr[x][y] = standard;
	}

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			cout << num_arr[i][j] << " ";
		}
		cout << std::endl;
	}

	for (int i = 0; i < num; i++) {
		delete[] num_arr[i];
	}
	delete[] num_arr;
}