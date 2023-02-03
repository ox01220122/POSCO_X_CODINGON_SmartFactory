using namespace std;
#include <iostream>
#include <string>
int main() {


	
	string friend1 = "홍길동";
	string friend2 = "성춘향";

	//배열 선언과 초기화 같이
	string friends[2] = { "홍길동" ,"성춘향" }; 
	//배열 선언과 초기화 따로
	string name[2];
	name[0] = "홍길동";
	name[1] = "성춘향";
	name[1] = "코딩온";  //안에 값을 바꿀 수 있다 


	//cout << name[3] << endl;  -> 쓰레기 값이 아닌 오류가 뜬다 
	
	float num[4] = { 1.5,2.6,4.7};
	num[3] = 3.1;
	

	//선언과 초기화 동시에
	string fruit[3] = { "apple", "banana","orange" };

	//하나씩 초기화
	fruit[0] = "apple";
	fruit[1] = "banana";
	fruit[2] = "orange";


	for (int i = 0; i < 3; i++) { cout << fruit[i] << endl; }
	


	string fruit1[2][3] = {
		{"apple","banana","cherry"} ,
		{"orange","strawberry",""}
	};  //1행1열, 1행2열, 2행1열, 2행2열


	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++) {
			cout << fruit[i][j] << endl;
		}
	}


	//3차원
	string fruit2[2][3][2] = { {{ " ", " "} ,{" "," "} ,{" "," "}},{{" "," "},{" "," "} ,{" "," "}} };



	return 0;
}