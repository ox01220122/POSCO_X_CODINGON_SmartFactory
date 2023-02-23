using namespace std;
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include <algorithm>
#include <conio.h>
#include <stdio.h>
#include <windowsx.h>
#define FIELD_WIDTH 60 // 게임창 사이즈 폭
#define FIELD_HEIGHT 30 // 게임창 사이즈 높이


HANDLE COUT = 0;    // 콘솔 출력 장치
HANDLE CIN = 0;        // 콘솔 입력 장치





class default_setting{

public:
	void gotoxy(float x, float y)
	{
		COORD Pos = { 0,0 };        //x, y를 가지고 있는 구조체
		Pos.X = x;
		Pos.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
	}
	void GameStartFild_test() {
		//게임창
		system("mode con cols=80 lines=80 | title 오목 게임"); //80,80이 최대
		//GameStartFild_test();

		//오목 글자 출력
		gotoxy(25, 10);
		cout << "오목 게임!";


		for (int i = 1; i < FIELD_WIDTH; i++) //여기서는 x값 그대로 넣어주기 
		{
			gotoxy(i, 0);
			cout << "─";
			gotoxy(i, 60);
			cout << "─";
		}
		for (int i = 1; i < FIELD_HEIGHT - 1; i++) {
			gotoxy(0, i);
			cout << "│";
			gotoxy(60, i);
			cout << "│";
		}
		gotoxy(0, 0);
		cout << "┌";
		gotoxy(FIELD_WIDTH, 0);
		cout << "┐";
		gotoxy(FIELD_WIDTH, FIELD_HEIGHT);
		cout << "┘";
		gotoxy(0, FIELD_HEIGHT);
		cout << "└";


		//Start 사각형
		for (int i = 20; i < 40; i++)//x축
		{
			gotoxy(i, 11);
			cout << "─";
			gotoxy(i, 15);
			cout << "─";
		}
		for (int i = 11; i < 15; i++) //y축
		{
			gotoxy(20, i);
			cout << "│";
			gotoxy(40, i);
			cout << "│";
		}

		gotoxy(20, 11);
		cout << "┌";
		gotoxy(20, 15);
		cout << "└";
		gotoxy(40, 11);
		cout << "┐";
		gotoxy(40, 15);
		cout << "┘";

		//왼쪽 위 별 출력하기 
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);   //글자 색 바꿔주는 함수 (노랑색)
		gotoxy(1, 1);
		for (int i = 1; i <= 15; i++)
		{
			for (int j = 15; j > i; j--) { cout << "＊"; }
			for (int k = i; k < 15; k++) { cout << " "; }
			cout << "\n";
			gotoxy(1, i);
		}
		//윗 별 출력하기 (가로)
		gotoxy(1, 1);
		for (size_t i = 1; i < 30; i++) { cout << "* "; }
		//아래 별 출력하기 (가로)
		gotoxy(1, 28.5);
		for (size_t i = 1; i < 30; i++) { cout << "* "; }


		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //글자 색 바꿔주는 함수 (빨강색)
		gotoxy(24, 13);
		cout << "★  Game Start";

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);  	//글자 색 바꿔주는 함수 (흰색)
		gotoxy(16, 16);
		cout << "시작하려면 Enter를 눌러주세요.";

		int enter;
		gotoxy(30, 25);
		enter = _getch();
		cin.ignore();
		cout << endl << endl << endl << endl;
	}

	void print_line() {
		system("cls");
		for (int i = 1; i < FIELD_WIDTH; i++) //여기서는 x값 그대로 넣어주기 
		{
			gotoxy(i, 0);
			cout << "─";
			gotoxy(i, 60);
			cout << "─";
		}
		for (int i = 1; i < FIELD_HEIGHT - 1; i++) {
			gotoxy(0, i);
			cout << "│";
			gotoxy(60, i);
			cout << "│";
		}
		gotoxy(0, 0);
		cout << "┌";
		gotoxy(FIELD_WIDTH, 0);
		cout << "┐";
		gotoxy(FIELD_WIDTH, FIELD_HEIGHT);
		cout << "┘";
		gotoxy(0, FIELD_HEIGHT);
		cout << "└";


	}
};
class click_control :public default_setting {
public:

	HANDLE COUT = 0;    // 콘솔 출력 장치
	HANDLE CIN = 0;        // 콘솔 입력 장치

	int be_input()
	{
		INPUT_RECORD input_record;
		DWORD input_count;

		PeekConsoleInput(CIN, &input_record, 1, &input_count);
		return input_count;
	}

	int get_input(WORD* vkey, COORD* pos)
	{
		INPUT_RECORD input_record;
		DWORD input_count;

		ReadConsoleInput(CIN, &input_record, 1, &input_count);
		switch (input_record.EventType) {
		case MOUSE_EVENT:
			if (pos && (input_record.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)) {
				CONSOLE_SCREEN_BUFFER_INFO csbi;

				GetConsoleScreenBufferInfo(COUT, &csbi);

				*pos = input_record.Event.MouseEvent.dwMousePosition;
				pos->X -= csbi.srWindow.Left;
				pos->Y -= csbi.srWindow.Top;

				return MOUSE_EVENT;
			}
			break;

		}

		//    FlushConsoleInputBuffer(CIN);
		return 0;
	}

	void gotoxy(int x, int y)      // 좌표 보내기 gotoxy
	{
		COORD Cur;
		Cur.X = x;
		Cur.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
	}
};





int main(void) {

	default_setting d_s;
	click_control c_c;

	d_s.GameStartFild_test();
	d_s.print_line();

	DWORD mode;
	WORD key;
	COORD pos;

	int event;        // 마우스 이벤트에 이용
	int x;            // 마우스의 x좌표 저장소
	int y;            // 마우스의 y좌표 저장소

	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// 마우스 활성화
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	while (1)
	{
		if (c_c.be_input())
		{
			if (c_c.get_input(&key, &pos) != 0)
			{
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				y = pos.Y;
				c_c.gotoxy(x, y);
				printf("*");
			}
		}
	}




}