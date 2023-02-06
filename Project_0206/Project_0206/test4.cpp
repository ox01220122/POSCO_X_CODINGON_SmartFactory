using namespace std;
#include <iostream>
#include <string>
#include <stdlib.h>
int main() {


	int x_num, y_num;
	
	while (true)
	{
		cout << "x : ";
		cin >> x_num;
		cout << "y : ";
		cin >> y_num;
		int a = (x_num*y_num)-1;

		if (x_num<=0 || y_num <= 0)
			cout << "x와 y모두 양수를 입력하세요" << endl;
		

		else {
			int** num_arr = new int* [x_num];
			for (int i = 0; i < x_num; i++)   //여기 조심
				num_arr[i] = new int[y_num];

			
			for (int i = 0; i < x_num; i++)
			{
				for (int j=0; j < y_num; j++) {
					num_arr[i][j] = ((x_num*y_num) - (a--));
					cout << num_arr[i][j] << " ";
				}
				cout << endl;
			}


			for (int i = 0; i < x_num; i++) { delete[] num_arr[i]; }
			delete[] num_arr;
			exit(1);
		}
	}








	return 0;
}


