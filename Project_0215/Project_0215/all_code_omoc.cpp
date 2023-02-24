#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
#include <algorithm>
#include <stdio.h>
#include <conio.h>
#include <windowsx.h>
#define FIELD_WIDTH 60 // 게임창 사이즈 폭
#define FIELD_HEIGHT 30 // 게임창 사이즈 높이
using namespace std;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);




HANDLE COUT = 0;    // 콘솔 출력 장치
HANDLE CIN = 0;        // 콘솔 입력 장치


void gotoxy(float x, float y)
{
	COORD Pos = { 0,0 };        //x, y를 가지고 있는 구조체
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}


void GameStartFild_test() {
	//게임창 크기조절
	system("mode con cols=80 lines=80 | title 오목 게임");

	//"오목게임" 글자 출력
	gotoxy(25, 10);
	cout << "오목 게임!";

	for (int i = 1; i < FIELD_WIDTH; i++) //기본 창 출력
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
	/*
	for (size_t j = 0; j < 15; j++)
	{
		for (int i = 1; i < FIELD_HEIGHT - 1; i++) {
			gotoxy(0, i);
			cout << "│";
	}


	*/





}
/*
int be_input()
{
	INPUT_RECORD input_record;
	DWORD input_count;

	PeekConsoleInput(CIN, &input_record, 1, &input_count);
	return input_count;
}

int get_input(WORD* vkey, COORD* pos) {
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



int main() {
	
	DWORD mode;
	WORD key;
	COORD pos;

	int event;        // 마우스 이벤트에 이용
	int x;            // 마우스의 x좌표 저장소
	int y;            // 마우스의 y좌표 저장소
	//GameStartFild_test();
	CIN = GetStdHandle(STD_INPUT_HANDLE);
	COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// 마우스 활성화
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);

	
	while (1){
		if (be_input()){
			if (get_input(&key, &pos) != 0){
				MOUSE_EVENT;
				x = pos.X;    // 마우스클릭값이 x,y변수에 저장되도록함
				y = pos.Y;
				gotoxy(x, y);
				printf("여기!");
			}
		}
	}



	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	

	POINT a;
	HWND hWnd;
	int width = 0;
	RECT window_size;

	a.x = 0;
	a.y = 0;


	while (1)
	{


		GetCursorPos(&a);
		hWnd = WindowFromPoint(a);
		ScreenToClient(hWnd, &a);
		GetWindowRect(hWnd, &window_size);
		width = (window_size.right - window_size.left);

		if ((0 < a.x) && (a.x < (int)(width / 2)))
		{
			gotoxy(1, 30);
			printf("X point = %d, Y point = %d\n\r", a.x, a.y);
		}

		else if (((int)(width / 2) < a.x) && (a.x < (int)width))
		{
			gotoxy(1, 30);
			printf("Y point = %d, X point = %d\n\r", a.y, a.x);
		}
	}
	Sleep(500);

}

int main(int argc, char* argv[]) {
	INPUT_RECORD rc;
	DWORD        dw;
	int mouse_XY[2];
	COORD pos = { 0,0 };

	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	while (1) {

		ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rc, 1, &dw); //핸들정보 
		mouse_XY[0] = rc.Event.MouseEvent.dwMousePosition.X; //X좌표 
		mouse_XY[1] = rc.Event.MouseEvent.dwMousePosition.Y; //Y좌표 

		FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 100, pos, &dw); //화면 지우기         
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); //콘솔좌표이동 
		printf("%d, %d\n", mouse_XY[0], mouse_XY[1]);

	}
	return 0;
}


#include <windows.h>
#include <stdio.h>

INPUT_RECORD rec;
DWORD dwNOER;
HANDLE CIN = 0;

void click(int* xx, int* yy, int* lr) {
	while (1)
	{
		ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // 콘솔창 입력을 받아들임.
		if (rec.EventType == MOUSE_EVENT) {// 마우스 이벤트일 경우

			if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) { // 좌측 버튼이 클릭되었을 경우
				int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X값 받아옴
				int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y값 받아옴

				*xx = mouse_x; //x값을 넘김
				*yy = mouse_y; //y값을 넘김
				*lr = 1; //마우스 클릭상태를 넘김

				break;
			}
			else if (rec.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED) { // 우측 버튼이 클릭되었을 경우
				int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X값 받아옴
				int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y값 받아옴

				*xx = mouse_x; //x값을 넘김
				*yy = mouse_y; //y값을 넘김
				*lr = 2; //마우스 클릭상태를 넘김

				break;
			}
		}
	}
}

int main() {
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	//마우스 입력모드로 바꿈

	int xx, yy, lr;
	while (1) {

		click(&xx, &yy, &lr);
		cout << xx << " " << yy << " " << lr << endl;

	}

}



INPUT_RECORD rec;
DWORD        dwNOER;

void CheckMouse()
{
	while (true)
	{
		ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // 콘솔창 입력을 받아들임.
		if (rec.EventType == MOUSE_EVENT) // 마우스 이벤트일 경우
		{
			if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) // 좌측 버튼이 클릭되었을 경우
			{
				int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X값 받아옴
				int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y값 받아옴
				COORD Coor = { 0, 0 };
				DWORD dw;
				FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', 80 * 25, Coor, &dw); // 콘솔창 화면을 지운다.
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Coor); // 커서를 0, 0으로 이동시킨다.
				printf("%d, %d", mouse_x, mouse_y); // 좌표를 출력한다.
				return;
			}
		}
	}
}

void main()
{
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	while (true)
	{
		CheckMouse();
	}
}
*/


int main() {
	GameStartFild_test();
}