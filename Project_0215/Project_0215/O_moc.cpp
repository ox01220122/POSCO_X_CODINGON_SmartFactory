#include "class.h";

int main(void) {

	setting_print s_p;
	click_control c_c;

	s_p.GameStartFild();
	s_p.print_line();

	DWORD mode;
	WORD key;
	COORD pos;

	int event;        // 마우스 이벤트에 이용
	int x;            // 마우스의 x좌표 저장소
	int y;            // 마우스의 y좌표 저장소

	c_c.CIN = GetStdHandle(STD_INPUT_HANDLE);
	c_c.COUT = GetStdHandle(STD_OUTPUT_HANDLE);

	// 마우스 활성화
	GetConsoleMode(c_c.CIN, &mode);
	SetConsoleMode(c_c.CIN, mode | ENABLE_MOUSE_INPUT);

	while (1) //입력 받기 무한반복
	{
		if (c_c.be_input())
		{
			if (c_c.get_input(&key, &pos) != 0)
			{
				// 마우스클릭값이 x,y변수에 저장되도록함
				MOUSE_EVENT;
				x = pos.X;    
				y = pos.Y;
				s_p.gotoxy(x, y);
				cout << "●";//검은색 돌 출력 (여기서 나중에 범위 조건 걸어주기)
			}
		}
	}
}