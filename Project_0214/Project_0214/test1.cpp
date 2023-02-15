using namespace std;
#include <iostream>
#include <string>
#include "Person.h"
#include "Student.h"

class Instructor : public Person {
public:
	~Instructor() {
		cout << "강사의 소멸자입니다" << endl;
	}
	void info() {
		cout << "강사입니다" << endl;
	}
};
int main() { //모든 파일 내에서 

	//Person p1 = Student(); //여기서 p1을 다운캐스팅을 하면 에러난다 
	Person* p = new Student();  //여기서 히프영역에 메모리 사용 (p가)
	cout << p->get_name() << endl;
	Student* s = (Student*)p; //다운캐스팅(업캐스팅 했던 자료형을 그대로 가져와서 사용한다)



	s->test();
	p->set_name("홍길동");
	cout << p->get_name() << " " << s->get_name() << endl;
	s->set_name("성춘향");
	cout << p->get_name() << " " << s->get_name() << endl;

	int a = 1;
	int k = 2;
	//참조변수
	int& b = a; // b는 a의 주소값을 가리킨다 (a의 값이 b에 담긴다)->포인터를 사용하지 않고 바로 b로 a한테 접근가능
	//a의 별명이 b라고 생각 하기 
	// 한번 참조하는 주소가 절대 바뀌지 않는다 (별명입장에서는 사람이 바뀌지 않는다)


	//포인터 
	int* c = &a;
	//여기서 b가 k의 주소값을 가리키게 해서 b가 2로 바뀜. b가 바뀜으로써 a=2(b의값)이 된다 
	//a가 변했으므로 a의 주소값을 가리키던 c의 포인터는 (*c) 2로 바뀐다 

	cout << a << " " << b << " " << *c << endl;
	b = k;
	cout << a << " " << b << " " << *c << endl;
	a = 3;
	cout << a << " " << b << " " << *c << endl;
	c = &k;  //여기서 c는 더이상 a를 참조하지 않기 떄문에 이제 a랑 무관하다 
	k = 4;
	cout << a << " " << b << " " << *c << endl;

	Student& s1 = *(Student*)p;    //얘의 주소는 절대 바뀌지 않는다 
	//p가 person형의 포인터인데 왜 student형의 포인터로 바꿔주나요??? 참조변수와 형을 맞춰주기 위해서?? 질문
	//person포인터를 student 포인터로 먼저 바꾸고 (여기까지도 포인터) *을 붙여서 값까지 접근 
	s1.set_name("코디");
	cout << p->get_name() << " " << s1.get_name() << endl;
	//여기서 왜 .으로 접근???? 참조변수의 문법인가? 


	Student s2 = *(Student*)p;  //값이 들어가야 한다  (p의 값을 이용해서 새로운 메모리를 만든것임 )
	//s2와 p는 독립되어있다 
	s2.set_name("코양");
	cout << p->get_name() << " " << s2.get_name() << endl;







	//s1과 s는 p의 주소값을 가리키고 있다고 생각하기 


	/*
	//참조변수 사용해서 다운캐스팅 한 것
	Student& s = *(Student*)p; //값에 접근을 해서
	*/
	delete p;
	//delete를 안쓰면 다운캐스팅한거 소멸자가 호출이 안된다  return을 만나서 호출돼야한는거아닌가?(질문)


	return 0;
}