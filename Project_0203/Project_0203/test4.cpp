using namespace std;
#include <iostream>
#include <string>

struct _tagStudent
{
	int iKor;
	int iENG;
	int iMath;
	int iTotal;
	float fAvg;
};

int main() {
	/*
	포인터 : 일반 변수는 일반적인 값을 가짐
	하지만 포인터 변수는 메모리 주소를 저장하게 된다 . 
	모든 포인터 타입을 선언할 수 있다 
	int변수의 주소는 int포인터 변수에 저장해야한다 
	포인터는 메모리 주소를 받아놓는 변수이기 떄문에 
	x86으로 개발할때는 무조건 4byte가 나온다 x64일때는 8byte가 나온다

	포인터는 다른변수의 메모리 주소를 갖는다 
	자기 스스로 아무런 일도 할 수 없다 (값을 제어할 수 있다)
	
	
	//포인터 변수 선언하기 
	int INumber = 100;
	//변수 선언 시 *을 붙여주면 해당 타입의 포인터 변수가 선언된다 
	int* pNum = &INumber; //pNum은 INumber변수의 메모리 주소를 값으로 갖게 된다 
	//그러므로 pNum을 이용해서 INumber의 값을 제어할 수 있다 

	cout << sizeof(int*) << endl;  //int 포인터 (메모리 주소를 담아야해서 (x86))
	cout << sizeof(char*) << endl;  //char 포인터 타입
	cout << sizeof(double*) << endl;

	cout << "INumber Address : " << &INumber << endl;
	cout << "pNum value : " << pNum<< endl;
	cout << "pNum Adress : " << &pNum << endl;
	
	//pNum을 이용해서 INumber의 값을 제어 (역참조 이용)
	// 변수 선언할 떄 *을 붙이면 포인터 변수 선언이 되는 것 
	//이미 선언된 포인터 앞에 *을 붙이게 되면 역참조가 된다 

	//가리키는 대상의 값을 의미한다 
	*pNum = 1234;
	cout << INumber << endl;

	int iArray[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int* pArray = iArray;   //iArray는 배열 인덱스0의 주소 (&iArray[0]과 같다)
	cout << *pArray << endl;
		
	//이중포인터, char 포인터, void포인터
	//char 포인터  (캐릭터의 주소를 가지고 온다)
	//포인터와 배열의 관계 : 배열명은 포인터다 


	_tagStudent tStudent = {};
	_tagStudent* pStudent = &tStudent;


	//연산자 우선순위때문에 *보다 .을 먼저 인식한다 (메모리주소.은 잘못된문법)
	//그러므로 *pStudent를 괄호로 감싸준 후 .을 이용해서 가리키는 대상의
	//멤버 변수에 접근한다 
	//이런 방식으로 가리키는 구조체의 대상에 접근할 수 있다 
	(*pStudent).iKor = 50;
	cout << tStudent.iKor << endl;
	pStudent->iKor = 80;  //메모리주소 ->를 이용해서 가리키는 대상의 멤버에 접근가능
	cout << tStudent.iKor << endl;



	//void포인터 - 타입이 없다

	void* pVoid = &INumber; //역참조가 불가능하고 메모리 주소만 저장가능한 버퍼로 쓸 수 있다
	cout << pVoid << endl;
	pVoid = &tStudent;    //구조체도 저장 (간접참조는 불가능)
	cout << pVoid << endl;

	int* pConvert = (int*)pVoid; //형변환을 통해서 int포인터로 바꾸고 역참조할수있다
	*pConvert = 123456;
	cout << *pConvert << endl;

	//같은거
	*((int*)pVoid) = 999;
	cout << *pConvert << endl;
	


	//이중포인터 
	//포인터는 일반변수의 주소를 저장하고 이중포인터는
	//포인터 변수의 주소를 저장한다 (포인터의 포인터)


	int iNymber1 = 1111;
	int iNymber2 = 2222;
	int* pNum = &iNymber1;
	int** ppNum = &pNum;

	*pNum = 3333;

	cout << iNymber1 << endl;
	cout << &iNymber1 << endl;
	cout << *pNum << endl;
	cout << pNum << endl;
	cout << &pNum << endl;
	cout << *ppNum << endl;
	cout << **ppNum << endl;
	*/

	//함수
















	return 0;
}