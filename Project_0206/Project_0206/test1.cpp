using namespace std;
#include <iostream>
#include <string>
int main() {
	//포인터


	int number = 5;
	int i=10;
	int* pNumber;
	pNumber = &number;

	cout << "number : " << number << endl; //변수의 값
	cout <<"pNumber value : "<< *pNumber << endl;  //포인터가 가리키는 주소안의 값(변수의 값)
	cout << "number adress(pNumber): " << pNumber << endl;  //포인터가 가리키는 주소
	cout << "number adress: " << &number << endl; //변수의 주소(위와 같음)
	cout << "pNumber adress: " << &pNumber << endl;// 포인터의 주소 


	*pNumber = 20;
	cout << "number : " << number << endl; //변수의 값
	cout << "pNumber value : " << *pNumber << endl;


	pNumber = &i;
	cout << "pNumber value : " << *pNumber << endl;













	return 0;
}