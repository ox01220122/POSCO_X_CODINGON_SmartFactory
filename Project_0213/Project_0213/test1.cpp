using namespace std;
#include <iostream>
#include <string>
class Person {
protected:
	string name;
public:
	virtual void info() {  //가상함수(자식클래스에서 재정의 할 것 이라고 기대)
		cout << "사람입니다" << endl;
	}
	virtual void test() {  //가상함수(자식클래스에서 재정의 할 것 이라고 기대)
		cout << "사람입니다테스트" << endl;
	}
};
class Student :public Person{
private:
	string stu_id;
public:
	void info() {
		cout << "학생 입니다" << endl;
	}
	void test() {
		cout << "학생의 test함수" << endl;
	}
};
int main() {

	Person s = Student();
	s.info();
	cout << "--------동적메모리,포인터 변수------------" << endl;
	Person *ss = new  Student(); 
	//new가  Student로 주소값을 만들어서 객체에 반환해준다 
	ss->info(); //포인터일떄는 ->이 문법을 사용한다 
	(*ss).info(); //이렇게도 가능(포인터에 담긴 값의 함수 info)
	ss->test();
	//ss.test()을 호출하고 싶으면 부모 클래스에서 virtual을 정의해 줘야한다 

	//포인터로 객체 생성하게 되면 동적바인딩 할 수 있게된다 
	delete ss; //동적으로 메모리를 할당했으면 반납해줘야한다 
	//Person persons[2] = { Student(),Student() };
	cout << "----------포인터 변수-------------" << endl;

	Student stu; //빌드중에 메모리가 자동으로 할당이 된다 
	Person* sss = &stu; //이 경우는 delete를 안쓴다 
	sss->info();
	//delete를 사용하게 되면 실행중에 오류가 발생한다 (런타임 에러)

	
	return 0;
}