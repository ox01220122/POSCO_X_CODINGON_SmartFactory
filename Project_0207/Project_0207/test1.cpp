using namespace std;  
//std namespace 내에 있는 모든 요소에 대한 접근을 풀어준다 (main문 안에서 풀어주면 main안에서만 사용가능)
#include <iostream>
#include <string>

namespace ns_test {  //식별자를 더 잘 구분하여 오류를 최소화 하기 위한 기능
	namespace ns_test2 { //namespace안에 namespace쓸 수 있다 
		int num1 = 0;
	}
	int num = 0;
	void test() {
		cout << num << endl;
		cout << "hello world" << endl;
	}
}
using namespace ns_test; //여기서 풀어주면 여기보다 밑의 코드에서만 test함수 접근을 풀어준다 
void aaa() {
	num = 7;
	cout << "aaa" << endl;
}
//using namespace ns_test; 이렇게 사용하면 식별자가 충돌한다
using std::cout;  //개별로 접근을 풀어줄 때 사용한다
int main() {

	int num = 0;
	ns_test::num = 5; //여기서 ns_test의 num을 5로 바꿔놔서 test()함수의 num출력이 5가 된다 
	test();
	aaa();

	cout << num << endl;
	cout << num << endl;


	return 0;
}