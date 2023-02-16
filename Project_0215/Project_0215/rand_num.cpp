using namespace std;
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
int main() {

	srand(time(NULL));
	int rand_num = 0;
	vector <int> com_num;
	vector <int> user_num;
	int count = 0;
	int true_num = 0, result_num = 0;


	while (count != 6) {
		int temp = 0;
		rand_num = (rand() % 25) + 1;
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
		if (rand_num>=1 && rand_num<=25){
			if (user_num.size() != 0) {
				for (int j = 0; j < user_num.size(); j++) {
					if (user_num[j] == rand_num) {
						cout << "숫자 중복. 다시 입력하세요 !" << endl;
						temp = 1;
					}
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
			if (com_num.at(i) == user_num.at(j)) { ++true_num; }
		}
	}

		switch (true_num)
		{
		case 0: {result_num = 7;break;}
		case 1: {result_num = 6;break;}
		case 2: {result_num = 5;break;}
		case 3: {result_num = 4;break;}
		case 4: {result_num = 3;break;}
		case 5: {result_num = 2;break;}
		case 6: {result_num = 1;break;}
		}


		cout << "당첨번호 공개!" << endl;
		for (int c : com_num) { cout << c << " "; } //출력
		cout << endl << "-----------------------------------------" << endl;
		cout << "결과 : " << result_num << "등 입니다" << endl;

	return 0;
}