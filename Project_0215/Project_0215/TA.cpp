using namespace std;
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
int main() {	
	vector <string> save_word = {"egg"};
	string input_word;
	double count_time = 0;
	clock_t startTime = clock();
	

	cout << save_word.front() << endl;
	while (count_time <= 5000) {
		cout << "다음 단어를 입력하세요 : ";
		cin >> input_word;
		cout << input_word[input_word.size() - 1] << endl;
		cout << save_word.back().back() << endl;
		clock_t endTime = clock();
		count_time = endTime - startTime;

		if (input_word[0] == save_word.back().back()) {
			save_word.push_back(input_word);
			
		}
		else {
			cout << "틀렸습니다" << endl;
		}
	}
	cout << "시간이 초과 되었습니다!" << endl;
	cout << "입력한 단어의 개수는 : "<< save_word .size()-2 << "입니다";
}