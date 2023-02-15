#include <iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int main() {
	int rand_num;

	time_t t;
	srand(time(&t));
	//srand(time(NULL));
	rand_num = (rand() % 45) + 1;
	cout << rand_num << endl;



	return 0;
}