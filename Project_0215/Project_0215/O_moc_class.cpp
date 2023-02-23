class default_setting {

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