using namespace std;
#include <iostream>
#include <string>
int main() {

	//동적배열
	int number;
	int* p = &number;
	cout << "숫자를 입력하세요 : ";
	cin >> number;

	//int num_arr[num]을 실행시키기 위함
	int* num_arr = new int[number];  //동적 배열을 이용해서 선언(뒤에 초기화 할 때 이게 배열인지 알려주면 된다)
	

	for (int i = 0; i < number; i++) { num_arr[i] = i+1; }
	for (int i = 0; i < number; i++) { cout << num_arr[i] << endl; }



	delete[] num_arr;  //작성해주지 않아도 오류가 뜨지는 않지만 프로그램 성능상 반납해주는 것이 좋다 
	delete p;

	return 0;
}