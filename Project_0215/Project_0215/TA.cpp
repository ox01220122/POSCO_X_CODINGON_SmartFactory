#include <iostream>
#include <ctime>
#include <vector>
#include <string>
using namespace std;
int main() {	
	vector <string> save_word = {"egg"};
	string input_word;
	double count_time = 0;
	clock_t startTime = clock();
	int temp;

	cout << save_word.front() << endl;
	while (count_time <= 30000) {
		char change_word = save_word.back().back();
		cout << "다음 단어를 입력하세요 : ";
		cin >> input_word;
		cout << change_word << endl;
		cout << input_word[input_word.size() - 1] << endl;		
		clock_t endTime = clock();
		count_time = endTime - startTime; //입력 했을 때 30초 초과 시 반복문 탈출

		if (input_word[0] == change_word) {
			save_word.push_back(input_word);
			temp = 2;
		}

		else {
			cout << "틀렸습니다" << endl;
			temp = 1;
		}
	}


	cout << "시간이 초과 되었습니다!" << endl;
	cout << "입력한 단어의 개수는 : " << save_word.size() - temp << "입니다"; 
	
}