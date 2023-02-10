#include <iostream>
using namespace std;

//private > protected > public
class Person {
protected:
	string name;
public:
	Person(string name) {
		this->name = name;
		cout << "부모클래스 생성자에서 초기화 된 이름 " << this->name << endl;
	}
};


class Student : public Person { // 기본값 private
	string stu_id;
public:
	Student() : Person("aaaa") { //name의 값을 aaaa로 초기화 해줬음 
		cout << "Student 생성자 실행됨.\n";
	}
	Student(string name ,string stu_id) : Person(name) { //여기서 받아온 name변수를 person생성자 호출되고 name이 바뀜
		this->stu_id = stu_id; //생성자 사용할때 name도 초기화 하고싶음 하지만 그 생성자는 부모에 있다. 부모에꺼
		//초기화 시켜주기위해 (받아온 변수를 부모클래스 생성자에 넘겨줌)
		cout << "자식클래스 생성자에서 초기화 된 학번 " << this->stu_id << endl;
	}
};
int main() {
	Student s("홍길동","1111");  //이름, 학번 받아옴


	return 0;
}