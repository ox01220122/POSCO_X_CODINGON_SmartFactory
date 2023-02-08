/*using namespace std;
#include <iostream>
#include <string>  //getline쓰기 위해서
#include <fstream>
#include <vector>
#include <cstdlib>
int main() {

	string name, number; //이름, 비번 입력받기 
	string tel;  //전화번호 입력받기 
	string str, str2;
	string member_tel = " "; //전화번호 저장위함 


	while (true)
	{
		int a = 1;
		cout << "이름을 입력하세요 : " << endl;
		cin >> name;
		cout << "비밀번호를 입력하세요 : " << endl;
		cin >> number;

		ifstream file_r("member.txt");
		ofstream file_w("member_tel.txt", ios::out | ios::app);


		while (file_r >> str >> str2) {
			if (str == name) {
				if (str2 == number)
				{
					cout << "로그인 성공" << endl;
					cout << "전화번호를 입력해주세요 : (***-****-****)" << endl;
					cin >> tel;
					member_tel = str + " " + tel;
					file_w << member_tel << "\n";
					a = 0;
				}
			}
		}
		if (a) { cout << "로그인 실패" << endl; }
	}
	return 0;
}

*/

using namespace std;
#include <iostream>
#include <string> 
#include <fstream>
#include <vector>
#include <cstdlib>
int main() {

	string name;
	string number;
	string tel;
	string str, str2, str3, str4;
	string member_tel = " ";
	string temp_line = "";  //임시 정보 저장

	//in.seekg(0, std::ios::beg);


	while (true)
	{
		int a = 1;
		cout << "이름을 입력하세요 : " << endl;
		cin >> name;
		cout << "비밀번호를 입력하세요 : " << endl;
		cin >> number;

		ifstream file_r("member.txt"); 
		ifstream file_tel("member_tel.txt");
		ofstream file_w("member_tel.txt", ios::out | ios::app);

		while (file_r >> str >> str2) {
			if (str == name && str2 == number) {
				cout << "로그인 성공" << endl;
				cout << "전화번호를 입력해주세요 : (***-****-****)" << endl;
				cin >> tel;
				member_tel = name + " " + tel;
				if (file_r.fail()) {file_w << member_tel << "\n";
				a = 0;
				}
				else { //잘 열렸을 경우 
					//검사시작
					while (file_tel >> str3 >> str4) { //tel에 쓰여져 있는 
						if (name == str3) 
							temp_line += member_tel + "\n"; //새로입력한거 써주기 
						else { temp_line += str3 + " " + str4 + "\n"; }
						}
	
					}	
				}//여기까지 로그인 성공했을 경우
			}





		file_w.clear();
		file_w << temp_line << "\n";
		temp_line = "";
		if (a) { cout << "로그인 실패" << endl; }
		}
	return 0;
}
