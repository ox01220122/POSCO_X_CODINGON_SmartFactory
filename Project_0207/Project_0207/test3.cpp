using namespace std; 
#include <iostream>
#include <string>  //getline쓰기 위해서
#include <fstream> //파일을 다루기 위한 기능 제공
int main() {
	//파일 입출력
	
	ifstream file;  // 파일 열기 class
	file.open("test2.txt"); //파일 명에 해당하는 파일 열기 
	string str, str2,line;

	if (file.fail()){
		cout << "파일 열기 실패 ~ ^^";
		return -1;
	}
		
	//file >> str>> str2; //파일 안 내용을 string형 변수에 저장
	
	/*
	while (file >> str >> str2){ 
		//file에서 프로그램으로 한번씩 읽으면 더 읽지 않음. 마지막까지 갔을 때 읽을게 없으면 종료
		cout << str << " " << str2<<endl;
	}
	
	getline(file, line); //file의 내용을 한 줄씩 읽어온다 (\n)기준으로 맨 앞줄 읽어왔음 
	cout << line;
	*/
	while (getline(file, line))//파일은 한번 읽으면 이전거 안읽는다 
	{
		cout << line<<endl;
	}
	
	file.close();  //가시적으로 파일을 끝났다라는 것을 알리기 위해 써준다(안써줘도 큰 문제는 없다)

	








	return 0;
}