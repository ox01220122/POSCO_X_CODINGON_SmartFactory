using namespace std;
#include <stdlib.h>
#include <iostream>
#include <string> 
class Character {
private:
	string name;
	int level;
	int item_num;
public:
	Character(string name) {
		this->name = name;
		level = 0;
		item_num = 0;
	}

	void name_chage(string name) { //이름 바꿔주기 
		this->name = name;
	}
	void level_up() { //레벨업
		level++;
		//this->level = level+1;
		cout << endl<<"레벨은 :" << level;
	}
	void add_item() { //아이템 +1  (현재 아이템 수 받아오기)
		item_num++;
		//this->item_num = item_num+1;
		cout << endl << "가지고 있는 아이템 수는 :" << item_num<<endl;
	}
	void use_item() { //아이템 -1
		if (this->item_num <=0)
		{
			cout << "아이템 수는 0 입니다";
		}
		else {
			item_num--;
			//this->item_num = item_num - 1;
			cout << endl << "가지고 있는 아이템 수는 :" << item_num << endl;
		}

	}



	//getter
	int get_level() { return level; }
	int get_item_num() { return item_num;}
	string get_name() { return name; }

	//setter
	void set_level(int level) { this->level = level; } //레벨 변경
	void set_item_num(int item_num) { this->item_num = item_num; } //아이템 수 변경
	void set_name(string name) { this->name = name;}

	


};
int main() {
	string name_in;
	int number;

	cout << "캐릭터의 이름을 입력하세요 : ";
	cin >> name_in;
	Character g(name_in); //생성자에서 이름, 레벨, 아이템수 넣어줬음 


	string name = g.get_name();
	int level = g.get_level();
	int item_num = g.get_item_num();

	g.set_name(name);
	g.set_level(level);
	g.set_item_num(item_num);
	
	cout << endl << "캐릭터를 어떻게 조작하시겠습니까?" << endl;
	cout << "0: 종료" << endl;
	cout << "1을 입력하면, 이름 변경하도록" << endl;
	cout << "2를 입력하면, level up" << endl;
	cout << "3을 입력하면, item 줍줍" << endl;
	cout << "4를 입력하면, item 사용" << endl;
	while (true)
	{
		cout << endl << "캐릭터를 어떻게 조작하시겠습니까?" << endl;
		cin >> number;

		switch (number)
		{
		case 0:
			exit(1); //종료
		case 1://이름 변경 
			name = g.get_name();
			cout << "바꿀 이름을 입력하세요 : ";
			cin >> name;
			g.name_chage(name);
			cout << "바뀐 이름은 " << g.get_name() << "입니다" << endl;
			break;
		case 2://레벨 업
			//level = g.get_level();
			cout << "레벨업 합니다" << endl;
			g.level_up();		
			break;
		case 3:
			//item_num = g.get_item_num();
			cout << "아이템을 주웠습니다" << endl;
			g.add_item();			
			break;
		case 4:
			//item_num = g.get_item_num();
			cout << "아이템을 사용합니다 " << endl;
			g.use_item();
			break;
		default:
			cout << "숫자를 잘못 입력하셨습니다" << endl << "다시 입력하세요 " << endl;
			break;
		}
	}



	return 0;
}
