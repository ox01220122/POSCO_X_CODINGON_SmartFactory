/*
	* class (객체지향 프로그래밍)
	객체(object) :  모든 사물을 의미
	c++에서 객체를 의미하는 것은 각 변수들도 객체로
	취급할 수 있다. 하지만 객체지향 프로그래밍을 지원하기 위해
	제공되는 수단은 class이다
	class자체가 객체가 되는 것은아니고 하나의 변수타입일 뿐
	class는 구조체 등을 이용해 생성한 변수를 보고 인스턴스라고
	부른다. 그 인스턴스가 객체 (클래스는 객체를 만들기 위한 틀)
	객체들의 관계를 설정해주어서 부품을 조립하듯이 객체들을
	조립하여 와성된 프로그램을 만들어나가는 방식이다

	클래스 선언방법 : class 클래스명{};의 형태로 선언
	코드블럭 안에 멤버변수를 넣어줄 수 있다.
	단 함수도 멤버로 만들 수 있다 (클래스안에 소속되어있는 함수)
	클래스의 4가지 속성
	캡슐화 : 클래스 안에 속하는 여러 변수 혹은 함수를 하나의
	클래스로 묶어주는 기능
	은닉화 : 클래스 안에 속하는 변수 혹은 함수를 내가 원하는
	부분만 외부에 공개하고 외부에 공갷지 않을 수 있다
	-public : 클래스 내부와 외부에서 모두 접근가능한 방법
	-protected : 클래스 외부에서는 접근이 불가능하고
	자기자신 내부나 자식 클래스 내부에서는 접근 가능한 키워드
	-private : 자기자신 내부에서만 접근이 가능하고
	외부나 자식 내부에서는 접근이 불가능한 방법이다
	상속성 : 클래스는 클래스와 클래스간에 부모, 자식관계를
	형성할 수 있다 자식클래스는 부모클래스의 멤버를 물려받아 자신의
	것처럼 사용할 수 있다 . 단 private으로 되어있는 멤버에는 접근
	이 불가능하다
	다형성 : 부모 자식관계로 상속관계가 형성되어있는 클래스간에 서로
	형변환이 가능한 성질을 말한다

	생성자와 소멸자(클래스에서 사용하는 특수한 함수)
	생성자 : 어떤 클래스를 이용해서 객체를 생성할떄 자동으로
	호출되는 함수이기 떄문에 객체의 멤버변수를 초기화 할때
	유용하게 사용할 수 있다. 생성자를 만들어주지 않을 경우
	내부적으로 기본 생성자가 제공이 되어서 기본 생서자를 자동으로
	호출해주게 된다
	클래스명()
	{
	
	}

	소멸자 : 어떤 클래스를 이용해서 생성한 객체가 메모리에서
	해제될때 자동으로 호출되는 함수. 객체를 사용하고 난 뒤 
	마무리 작업을 해줄때 유용하게 사용할 수 있다 
	~클래스명(){
	}

	*/
using namespace std;
#include <iostream>
#include <string>
#include <vector>

class CTracer {


public: //private으로 하면 main에서 생성자,소멸자호출이 안된다 
	//접근할 수 없음(private으로 하면)
	CTracer() { //생성자 (함수이름이 클래스이름과 같다)
		cout << "Tracer 생성자" << endl;
		strcpy_s(m_strName, "트레이서");
	}
	CTracer(char* pName) {
		strcpy_s(m_strName, pName);
	}

	~CTracer() { //소멸자(함수이름이 클래스이름과 같다)
		cout << "Tracer 소멸자" << endl;
	}

	//클래스 멤버변수를 선언할 때는 m_를 붙여준다
	char m_strName[32]; //기본으로 private

public:
	int m_iAttack;
	int m_iHP;
private:
	int m_iFlash;
private:
	int m_iBack;
public:
	void Output() {
		cout << "output" << endl;
	}
};

int main() {
	CTracer tr1; //생성함과 동시에 호출되는 함수가 생성자
	tr1.Output(); 
	//tr1이 속해있는 코드블럭이 종료되는순간 메모리에서 해제
	//자동으로 소멸자를 호출해준다 
	
	
	return 0;
}