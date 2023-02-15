#include <iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
using namespace std;
int main() {
	int rand_num; 
	srand(time(NULL));
	vector<int> Lotto = {};
	int count = 0;
	while (count != 6) {
		int temp = 0;
		rand_num = (rand() % 45) + 1;
		if (Lotto.size() != 0){
			for (int j = 0; j < Lotto.size(); j++) {
				if (Lotto[j] == rand_num) {temp = 1;}
			}
		}
		if (!temp){
			Lotto.push_back(rand_num);
			count++;
		}	
	}
	cout << "로또 번호는 : ";
	for (int s : Lotto) { cout << s<<" "; }
}