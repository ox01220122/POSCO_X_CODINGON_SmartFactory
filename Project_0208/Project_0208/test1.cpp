using namespace std;
#include <stdlib.h>
#include <iostream>
#include <string>  
struct Position  //구조체와 클래스는 한가지 다른 점이 있다 
{
	int x;
	int y;
};

int main() {
	//namespace와 차이는 namespace는 변수를 만들 수 없지만(변수가 존재 할 구역을 확실하게 정해주기 위함 - 문법 ::)
	//struct는 필요한 정보들을 집합 해 두었다고 생각 
	
	
	//선언과 할당을 따로 함 
	Position p; 
	p.x = 3;
	p.y = 4; 	
	//선언과 할당을 같이 함 (위와 같은 의미 )
	//Position p = { 3,4 };


	cout << p.x << " " << p.y <<endl;

	return 0;
}