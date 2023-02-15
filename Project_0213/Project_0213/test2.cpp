using namespace std;
#include <iostream>
#include <string>
class Person {
protected:
	string name;
public:
	virtual ~Person() {
		cout << "사람의 소멸자 입니다" << endl;
	}
	virtual void info() {  //가상함수(자식클래스에서 재정의 할 것 이라고 기대)
		cout << "사람입니다" << endl;
	}
	virtual void test() {  //가상함수(자식클래스에서 재정의 할 것 이라고 기대)
		cout << "사람입니다테스트" << endl;
	}
};
class Student :public Person {
private:
	string stu_id;
public:
	~Student() {
		cout << "학생의 소멸자 입니다" << endl;
	}
	void info() {
		cout << "학생 입니다" << endl;
	}
	void test() {
		cout << "학생의 test함수" << endl;
	}
};

class Instructor : public Person {
public:
	~Instructor() {
		cout << "강사의 소멸자입니다" << endl;
	}
	void info() {
		cout << "강사입니다" << endl;
	}
};



int main() {

	//여기서 소멸자가 나옴(생성자를 실행만시키고 원하는 정보를 담아두고 바로소멸시킴)
	Person s = Student();
	//원하는 정보만 담아서 Person의 생성자를 다시 실행시키기 때문에 Person의 생성자도 소멸 시킬게 남아있음 
	s.info(); //정적 바인딩

	cout << "--------동적메모리,포인터 변수------------" << endl;
	Person* ss = new  Student(); //부모함수에 virtual을 써주면 사람소멸자를 호출가능
	ss->info();  //동적바인딩 (자식에 있는 것을 호출하게 된다)
	(*ss).info();	ss->test(); 
	delete ss;  //자식에 있는 소멸자를 호출해주고 싶으면 부모의 소멸자를 가상함수로 만들어줘야한다 


	cout << "----------포인터 변수-------------" << endl;

	Student stu;  //동적메모리가 아님 그래서delete안쓴다 (빌드를 할때 메모리 크기를 잡고산다 )
	Person* sss = &stu; //이 경우는 delete를 안쓴다 
	sss->info();
	//delete를 사용하게 되면 실행중에 오류가 발생한다 (런타임 에러)
	cout << "----------포인터 배열-------------" << endl;

	//부모클래스의 자료형으로 자식클래스의 인스턴스를 만든것이 업캐스팅이라고 한다 
	Person* per_arr[3] = { new Student(),new Instructor() ,new Student() };
	for (int i = 0; i < 3; i++){
		per_arr[i]->info();
	}
	for (int i = 0; i < 3; i++){
		delete[]per_arr[i];
	}
	cout << "----------end-------------" << endl;

	return 0;
}