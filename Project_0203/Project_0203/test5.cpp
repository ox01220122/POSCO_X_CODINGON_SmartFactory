using namespace std;
#include <iostream>
#include <string>
#include <stdlib.h>




enum AI_MODE  //enum은 상수화 집합을 사용자 정의 형태로 관리하는 방법
{
	AM_EASY = 1,
	AM_HARD  //2의 값을 가지게 된다 
};
enum LINE_NUMBER
{
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
};

void setNumber(int* pArray);
void Shuffle(int* pArray);
AI_MODE SelectAIMode();
void OutputNumber(int *pArray, int iBingo);
bool ChangeNumber(int *pArray, int input);



int main() {

	/*
	//함수 : 일종의 사용할 수 있는 부품들을 만들어준다
	//반환타입은 함수가 기능을 수행하고 기능의 결과를 반환해야 할 경우 지정
	//함수의 오버로딩 : 같은 이름의 함수지만 기능이 다르던가 인자가 다른 함수
	//조건 : 함수이름이 무조건 같아야한다. 단 인자개수, 타입이 달라야 오버로딩
	//반환타입은 오버로딩에 영향을 주지 않는다
	//함수의 디폴트 인자 : 인자에 기본적으로 값을 대입해두면 인자를 안넘길경우
	//그 값이 대입되고 넘길경우 넘긴 값으로 대입이 된다
	//디폴트 인자는 가장 오른쪽부터 지정해 주어야한다

	int num = 5;
	cout << num << endl;
	changeNum(&num);
	cout << num << endl;
	 */

	 //빙고게임
	srand((unsigned int)time(0));
	//배열 선언
	int iNumber[25] = {};
	int iAINumber[25] = {};

	//1부터 25까지의 숫자를 넣어준다 (배열의 이름이 주소임)
	setNumber(iNumber);
	setNumber(iAINumber);

	//배열을 섞어준다 
	Shuffle(iNumber);
	Shuffle(iAINumber);


	//난이도를 선택한다 
	int iBingo = 0, iAIbingo=0;
	int iAIMode = SelectAIMode();  //난이도가 선택되어 return된다 

	//선택 안된 목록 배열을 만들어준다 
	int iNoneSelect[25] = {};
	//선택 안된 숫자 개수를 저장한다 
	int iNoneSelectCount = 0;



	while (true)
	{
		system("cls");
		//숫자를 5*5로 출력한다 
		cout << "============== Player ==============" << endl;
		OutputNumber(iNumber, iBingo);
		//AI빙고판을 출력한다
		cout << "============== AI Player ==============" << endl;
		switch (iAIMode)
		{
		case AM_EASY:
			cout << "AI Mode : Easy" << endl;
		case AM_HARD:
			cout << "AI Mode : Hard" << endl;
			break;
		}
		OutputNumber(iAINumber, iAIbingo);


		//줄수가 5이상일 경우 게임을 종료한다 
		if (iBingo >=5)
		{
			cout << "Player승리" << endl;
			break;
		}
		else if (iAIbingo >= 5) {
			cout << "Player승리" << endl;
			break;
		}

		cout << "숫자를 입력하세요 (0 : 종료)";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;
		else if (iInput < 1 || iInput>25)
			continue;

		//중복입력을 체크하기 위한 변수이다. 기본적으로 중복되었다 라고 
		//하기 위해 true로 잡아주었다 
		bool bAcc = ChangeNumber(iNumber, iInput);

		if (bAcc)
			continue;

		//AI숫자 바꾸기 
		ChangeNumber(iAINumber, iInput);
	}
}






void setNumber(int* pArray) {
	for (int i = 0; i < 25; i++) {
		pArray[i] = i + 1;
	}
}

void Shuffle(int* pArray) {

	int iTemp, idx1, idx2;

	for (int i = 0; i < 100; i++)
		idx1 = rand() % 25;  //1~25까지의 숫자를 넣어준다 
		idx2 = rand() % 25; //1~25까지의 숫자를 넣어준다 

		iTemp = pArray[idx1];
		pArray[idx1] = pArray[idx2];
		pArray[idx2] = iTemp;
}

AI_MODE SelectAIMode() {

	int iAIMode;
	while (true)
	{
		system("cls");  //화면클리어 
		cout << "1 : Easy" << endl;
		cout << "2 : Hard" << endl;
		cout << "AI모드를 선택하세요 : ";
		cin >> iAIMode;
		if (iAIMode >= AM_EASY && iAIMode<=AM_HARD)
			break; //제대로 선택했으면 break가된다 
	}

	return (AI_MODE)iAIMode;  //함수 타입으로 형변환해서 return 한다 
}


//빙고 카운트 출력
void OutputNumber(int* pArray, int iBingo) {

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) {
			if (pArray[i * 5 + j] == INT_MAX)
			{
				cout << "*\t";
			}
			else
				cout << pArray[i * 5 + j] << "*\t";
		}
		cout << endl;
	}	
	cout << "Bingo Line : " << iBingo << endl << endl;

}

bool ChangeNumber(int* pArray, int input) {
	for (int i = 0; i < 25; i++)
	{
		if (pArray[i] == input) {
			pArray[i] == INT_MAX;
			return false;
		}
	}
	//여기까지 오게 되면 return false가 동작안된것이므로 중복된 숫자를 입력한것
	return true;
}
