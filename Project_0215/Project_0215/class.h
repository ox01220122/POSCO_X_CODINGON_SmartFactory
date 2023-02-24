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
class setting_print {
public:
	void gotoxy(float x, float y); //좌표 함수
	void GameStartFild(); //게임 시작창 출력 함수 
	void print_line();
};

class click_control : public setting_print {
public:
	HANDLE COUT = 0;    // 콘솔 출력 장치
	HANDLE CIN = 0;        // 콘솔 입력 장치
	int be_input();
	int get_input(WORD* vkey, COORD* pos);
};
