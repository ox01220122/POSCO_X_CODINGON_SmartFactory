using namespace std;
#include <iostream>
#include <string>
#include <vector>
int main() {
	//벡터 - 동적배열을 할당할 때 사용한다 (알아서 동적배열을 만들어주고 해제도 해준다 )

	//vector<int> v1(3); //크기가 3인 배열(자동으로 0으로 초기화 )
	//vector<int> v2(3, 1); // 크기가 3인 배열을 선언하고 원소를 모두 1로 초기화 
	/*
	int num;
	cout << "숫자 입력 : ";
	cin >> num;
	*/
	vector<int> v3 = { 1,2,3,4,5 }; //크기가 3인 벡터 배열 선언 및 초기화 (객체를 하나 생성했다고 생각)
	//v3.assign(num, 1); //num의 크기 , 모든 원소 1로 할당 
	//vector<int> v(num,1)과 같다 
	


	//벡터의 크기를 알 수 있는 메소드인 size가 제공된다 
	for (int i = 0; i < v3.size(); i++) {
		//cout << v3[i] << " ";
		cout << v3.at(i) << " ";  // at이라는 메소드로 인덱스에 접근할 수 있다 
	}
	cout << endl;

	v3.resize(6); //사이즈를 5였던 것을 6으로 바꾸는데 6번째 원소를 0으로 할당하고 바뀐다
	//커진 길이만큼 0으로 초기화 된다 
	v3.push_back(10); //배열의 마지막에 원하는 원소를 추가합니다  (6번째원소가 0이돼서 7번째 원소가 10으로 초기화)
	for (int i = 0; i < v3.size(); i++) { cout << v3.at(i) << " ";}
	cout << endl;
	
	
	v3.pop_back(); //마지막 원소를 삭제시킨다
	for (int i = 0; i < v3.size(); i++) { cout << v3.at(i) << " "; }
	cout << endl;

	v3.pop_back(); //마지막 원소를 삭제시킨다 (배열의 길이를 1 줄여버린다 )
	for (int i = 0; i < v3.size(); i++) { cout << v3.at(i) << " "; }
	cout << endl;

	cout << v3.back() << " ";  //front : 가장 처음 원소  back : 가장 마지막 원소 
	cout << endl;

	v3.insert(v3.begin()+1,99); //원하는 위치에 원하는 값을 넣어줄 수 있다 (2번 인덱스에 99를 추가하는 코드)
	//원래 2번인덱스에 있던 3은 뒤로 밀린다 
	//v3.begin은 배열의 가장 처음 주소를 출력한다 +1한만큼 인덱스가 바뀐다 
	for (int i = 0; i < v3.size(); i++) { cout << v3.at(i) << " "; }
	cout << endl;

	v3.erase(v3.begin() + 3,v3.begin()+5); //3번~4번(5보다 작은) 인덱스에 있는것을 삭제하겠다는 뜻 
	for (int i = 0; i < v3.size(); i++) { cout << v3.at(i) << " "; }
	cout << endl;


	//v3.clear(); //배열의 모든 원소 삭제 (배열의 크기가 0)
	//for (int i = 0; i < v3.size(); i++) { cout << v3.at(i) << " "; }
	//cout << endl;


	for (auto &a : v3) {   // 참조연산자를 사용하면 실제로 배열안의 값을 가리키게 된다(공간의 값 변경가능) 
		a += 1;
		cout << a << " ";
	} 
	// for each문을 사용해서 배열의 값을 직접적으로 바꾸려면 안에 참조 연산자를 사용(백터의 값이 바뀐다 ) 
	//&를 사용하지 않으면 a라는 변수가 하나새로 생성되어서 메모리가 아얘 다른 공간을 가리킨다 
	

	


	return 0;
}