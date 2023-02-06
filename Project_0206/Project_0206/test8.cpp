using namespace std;
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
int main() {

	int x_num, y_num;
	while (true)
	{
		cout << "x : ";
		cin >> x_num;
		cout << "y : ";
		cin >> y_num;
		int a = (x_num * y_num) - 1;

		if (x_num <= 0 || y_num <= 0)
			cout << "x와 y모두 양수를 입력하세요" << endl;

		else {
			vector<vector<int>> vec_2d;
			vec_2d.assign(x_num, vector <int>(y_num));


			for (int i = 0; i < x_num; i++)
			{
				for (int j = 0; j < y_num; j++) {
					vec_2d.at(i).at(j) = ((x_num * y_num) - (a--));
					cout << vec_2d.at(i).at(j)<<" ";
				}
				cout << endl;
			}
			exit(1);
		}
	}



	return 0;
}