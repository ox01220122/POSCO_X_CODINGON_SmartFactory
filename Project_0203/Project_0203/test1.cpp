using namespace std;
#include <iostream>
#include <string>
int main() {


	/*
	string friend1 = "홍길동";
	string friend2 = "성춘향";

	//배열 선언과 초기화 같이------------------------------------------------------------
	string friends[2] = { "홍길동" ,"성춘향" }; 
	//배열 선언과 초기화 따로
	string name[2];
	name[0] = "홍길동";
	name[1] = "성춘향";
	name[1] = "코딩온";  //안에 값을 바꿀 수 있다 


	//cout << name[3] << endl;  -> 쓰레기 값이 아닌 오류가 뜬다 
	
	float num[4] = { 1.5,2.6,4.7};
	num[3] = 3.1;
	

	//선언과 초기화 동시에------------------------------------------------------------
	string fruit[3] = { "apple", "banana","orange" };

	//하나씩 초기화------------------------------------------------------------
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
	


	//3차원------------------------------------------------------------
	string fruit2[2][3][2] = { 
		{{ " ", " "} ,{"aaa"," "} ,{" "," "}},
		{{" "," "},{" "," "} ,{" "," "}} };
	cout << fruit2[0][1][0] << endl;

	cout << fruit2 << endl; //주소값이 나온다 
	




	//for문 사용------------------------------------------------------------
	string friends[2][3] = { {"홍길동1" ,"홍길동2","홍길동3"},{"김민지1","김민지2","김민지3"}};

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++) 
			cout << friends[i][j] << endl;
	
	
	string friends[3] = { "홍길동1" ,"홍길동2","홍길동3" };


	//파이썬 for i in 배열이름 -> 이랑 같은 기능인듯
	for (string hello : friends) {  //인덱스를 안써도 되고 각각의 배열을 hello로 접근할 수 있다 
		cout << hello << endl;
	}
	

	string friends[2][3] = { {"홍길동1" ,"홍길동2","홍길동3"},{"김민지1","김민지2","김민지3"} };



	//2차원 배열 for each문 ------------------------------------------------------------
	for (auto &f1 : friends){
		for (string f2 : f1) {  //f1변수가 배열로 인식하지 못해서 주소값을 지정해줬다  (결국 출력해야 할것은 f2)
			cout << f2 << endl;
		}
	} //안에 있는 마지막 for문이 값에 접근한다 (그냥 외우기 - 2차원 이상에서 이렇게 쓴다 )
	*/

	//sizeof() : sizeof안에 변수 or type을 인자로 넘겨줌. 크기를 byte단위로 구함 

	string friends[3] = {"홍길동1","홍길동2","홍길동3"};
	for (int i = 0; i < sizeof(friends)/sizeof(string); i++)  // 4byte(string)가 3개 있으니까 12byte가 나오므로 연산필요
		//(string의 size로 나눠줌)
		cout << friends[i] << endl;
	




	return 0;
}