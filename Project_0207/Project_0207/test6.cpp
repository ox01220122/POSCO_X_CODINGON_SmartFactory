using namespace std;
#include <iostream>
#include <string>  //getline쓰기 위해서
#include <fstream>
#include <vector>
int main() {
	

	string name[3];
	string num[3];
	
	ofstream file_w("member.txt");
	string members = " ";
	string line;

	for (int i = 0; i < 3; i++){
		cout << i + 1 << "번째 회원 이름, 비밀번호를 순차적으로 입력 : " << endl;
		cin >> name[i]>>num[i];
	}
	
	for (int i = 0; i < 3; i++){
		members = name[i] +" "+ num[i];
		file_w << members <<"\n";
	}
	file_w.close();

	ifstream file_r("member.txt");
	
	while (getline(file_r, line)) {cout << line << endl;}
	



	
	
	


	return 0;
}