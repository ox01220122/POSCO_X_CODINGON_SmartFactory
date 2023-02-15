using namespace std;
#include <iostream>
#include <string>
#include <typeinfo>
#include <vector>
class Person {
protected:
	string name;
	static int static_var;  //int형 변수를 static형으로 선언한 것  (객체와 독립적이다 )
	//static 은 일반클래스 개념이다 
	static int count; //main함수에 선언된 사람 수를 세고 싶음 
	
public:
	static int get_count() {
		return count;
	}

	static void static_method() {
		//name = 
		//name = "아무개";
		//set_name("아무개"); // static메소드 안에서는 일반 멤버에 접근할 수 없음
		cout << "스테틱 메소드 테스트" << endl;
	}
	static int get_var() {  //Person::get_var로 가져오기 위해 static을 쓴다 
		return 0;
	}
	Person() { //객체를 만들 때 생성자가 호출된다 
		this->name = "아무개";
		count++;  //사람 수 세기 위함 
	}
	virtual ~Person() {
		cout << "사람의 소멸자 입니다" << endl;
		count--; //가상함수에서도 카운터에 접근하면 static int count에 접근하는 것 
	}
	virtual void info() {  //가상함수(자식클래스에서 재정의 할 것 이라고 기대)
		cout << "사람입니다" << endl;
	}
	virtual void test() {  //가상함수(자식클래스에서 재정의 할 것 이라고 기대)
		cout << "사람입니다테스트" << endl;
	}

	void set_name(string name) { //name의 setter
		this->name = name;
	}
	string get_name() {//name의 getter
		return name;
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

int Person::static_var = 0;
int Person::count = 0;  //여기서 초기화 해줘야한다 

int main() {
	//static멤버는 모든 객체가 하나의 공간을 공유한다 
	//name은 static멤버가 아니다 -> 객체별로 공간이 따로 할당된다 
	//static_var은 static멤버이다 -> 모든 객체가 하나의 공간을 공유한다 

	Person p; //그냥 변수는 객체를 만들지 않으면 메모리를 만들지 않는다 
	p.info();
	//Person.info();
	Person::static_method(); //객체와 독립적이므로 객체를 생성하지 않아도 접근가능
	//클래스를 타고 들어갈 수 있다 (물론 객체로도 가능하다)



	Person p1;
	p1.set_name("홍길동");
	cout << p.get_count() << " " << p1.get_count() << " " << Person::get_count() << endl;

	Person p2;
	cout << p.get_count() << " " << p1.get_count() << " " << Person::get_count() << endl;

	cout << Person::get_count() <<"명" << endl;


	Person* p3[5];
	for (int i = 0; i < 5; i++)
	{
		p3[i] = new Person();
	}
	cout << Person::get_count() << "명" << endl;
	
	for (int i = 0; i < 5; i++)
	{
		delete p3[i];
	}
	cout << Person::get_count() << "명" << endl;
	//반납되면서 소멸자가 호출된다. 소멸자에 count-- 때문에 줄어든다 



	//여기서 부터 vector로 사용한다-------------------------------------------------
	vector<Person*> persons = { new Person(),new Person() };
	cout << Person::get_count() << "명" << endl;

	persons.push_back(new Person);
	cout << Person::get_count() << "명" << endl;

	int size = persons.size();
	for (int i = 0; i < size; i++){
		delete persons.at(i);
	}
	for (int i = 0; i < size; i++){
		persons.pop_back();
	}




	return 0;
}