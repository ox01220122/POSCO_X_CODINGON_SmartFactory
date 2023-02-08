using namespace std;
#include <iostream>
#include <string>  //getline쓰기 위해서
#include <fstream> //파일을 다루기 위한 기능 제공

bool OpenFile(ifstream &file) { //참조타입을 class로 받으면 &를 붙여줘야한다 
	if (file.fail()) {
		cout << "파일 없음 " << endl;
		return false;
	}	
	else
		return true;
}


int main() {
	string line,file_content;
	ifstream file_r("test.txt");
	ofstream file_w("test1.txt");

	if (!OpenFile(file_r)) return -1;
	while (getline(file_r,line))
	{
		file_content += line + "\n";
	}

	cout << file_content;
	file_w << file_content;


	return 0;
}