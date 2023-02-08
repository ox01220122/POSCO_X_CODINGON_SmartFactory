using namespace std; 
#include <stdlib.h>
#include <iostream>
#include <string>  //getline쓰기 위해서
#include <fstream> //파일을 다루기 위한 기능 제공
int main() {

	ofstream file("test2.txt",ios::out | ios::app); //파일 오픈하는 방법 두가지
	//file.open("test2.txt");
	if (file.fail())
	{
		cout << "파일 열기 실패!";
		return -1;
	}
	file << "hello world!\nhihi"; //덮어쓰기만 가능
	//ifstream : 파일 -> 프로그램
	//ofstream : 프로그램 -> 파일


	//for (int i = 1; i <= 5; i++) { file << i << endl; }
	
	
	
	file.close();
	return 0;
}
