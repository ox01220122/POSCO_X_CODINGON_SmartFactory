using namespace std;
#include <iostream>
#include <string>
int main() {
	//이차원 동적 배열
	//n*n의 배열을 동적배열을 이용해서 만들어주기 
	int num;
	cout << "숫자를 입력하세요 :" << endl;
	cin >> num;

	//배열의 크기 잡아주기
	int** num_arr = new int* [num]; //num_arr를 동적배열로 초기화시킨거 (이중포인터)
	for (int i = 0; i < num; i++)
		num_arr[i] = new int[num]; //여기서도 동적배열 생성 


	//동적배열에서는 for each문을 사용할수 없다 

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++) {
			num_arr[i][j] = 1;
			cout << num_arr[i][j] << " ";
		}
		cout << endl;
	}



	for (int i = 0; i < num; i++) { delete[] num_arr[i]; }//for문으로 생성한 배열  
	delete[] num_arr; //겉에 있는 배열을 해제해준다(int** num_arr = new int* [num]; 이부분)





	//3차원일 경우 : int*** num_arr = new int** [num];
	// 2*2배열  :  {{1,2},{3,4}}





	return 0;
}