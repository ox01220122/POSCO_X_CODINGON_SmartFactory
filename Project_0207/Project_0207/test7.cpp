using namespace std;
#include <iostream>
#include <string>  //getline쓰기 위해서
#include <fstream>
#include <vector>
int main() {

	string name;
	string number;
	string str, str2;

	cout << "이름을 입력하세요 : " << endl;
	cin >> name;
	cout << "비밀번호를 입력하세요 : " << endl;
	cin >> number;

	ifstream file_r("member.txt");

	
while (file_r >> str >> str2) {
	if (str == name ) {
		if (str2 == number){
			cout << "로그인 성공";
			exit(1);
		}
		else
			cout << "로그인 실패";
	}	
}
cout << "로그인 실패";



/*
string name_in, pw_in;
	string name, pw;
	bool is_login = false;

	cout << "이름입력 :";
	cin >> name_in;
	cout << "비밀번호입력 :";
	cin >> name_in;

	ifstream file("member.txt");

	while (file>>name>>pw)
	{
		if (name_in == name && pw_in == pw) {
			is_login = true;
			break;
		}
	}
	if (is_login == true) { cout << "로그인 성공" << endl; }
	else   cout << "로그인 실패" << endl;

*/

	return 0;
}