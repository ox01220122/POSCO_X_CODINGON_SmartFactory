using namespace std;
#include <iostream>
#include <string>
#include <vector>
int main() {
	//2차원 벡터 
	
	vector<vector<int>> vec_2d;  //2차원 벡터
	vector <int> vec1;
	vector <int> vec2;
	
	

	//3*2행렬을 만든다  (다 0으로 초기화 되어있음) (3행2열)
	vec_2d.assign(3, vector <int>(2,1)); //변수이름 안쓰고 바로 사용할 수 있다 (3으로 2개의 원소 할당-1을 넣어줌)
	//(3크기) , (모든원소가 1,크기 2짜리 벡터로 할당 )
	for (int i = 0; i < vec_2d.size(); i++) //vec_2d.size()는 행을 의미한다 
	{
		for (int j = 0; j < vec_2d.at(i).size(); j++) {  
			//vec_2d.at(i).size()는 {{,},{,},{,}}에서 배열[i]의 크기
			//cout << vec_2d[i][j] << " ";
			cout << vec_2d.at(i).at(j)<<" ";
		}
		cout << endl;
	}
	cout << endl;
	cout << endl;
	
	//for each로 출력한다 
	for (vector<int> vv2 : vec_2d) //auto도 많이 사용한다 
	{
		for (int vvv2 : vv2) {
			cout << vvv2 << " ";
		}
		cout << endl;
	}


	










	return 0;
}