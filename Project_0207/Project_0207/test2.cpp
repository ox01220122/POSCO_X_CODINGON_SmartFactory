using namespace std;
#include <iostream>
#include <string>
namespace seoul {
	string number;
	string landmark;
}
namespace busan {
	string number;
	string landmark;
}
using namespace busan;
int main() {

	seoul::number = "02";
	seoul::landmark = "경복궁";
	number = "051";
	landmark = "광안대교";

	cout << "서울 지역번호 : " << seoul::number<<endl;
	cout << "서울 랜드마크 : " << seoul::landmark << endl;
	cout << "부산 지역번호 : " << number << endl;
	cout << "부산 랜드마크 : " << landmark << endl;



	return 0;
}