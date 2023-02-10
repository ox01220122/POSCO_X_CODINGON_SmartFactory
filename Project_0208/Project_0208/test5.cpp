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

	void name_chage(string name) {
		this->name = name;
		cout << "바뀐 이름은 : " << this->name << endl;}

	void level_up() { 
		level++;
		cout << endl<<"레벨은 :" << level;}

	void add_item() {
		item_num++;
		cout << endl << "가지고 있는 아이템 수는 :" << item_num<<endl;}

	void use_item() {
		if (this->item_num <=0){cout << "아이템 수는 0 입니다";}
		else {
			item_num--;
			cout << endl << "가지고 있는 아이템 수는 :" << item_num << endl;}
		}

	string get_name() { return name; }
	void set_name(string name) { this->name = name; }
};

int main() {
	string name_in;
	int number;

	cout << "캐릭터의 이름을 입력하세요 : ";
	cin >> name_in;
	Character g(name_in); 
	string name = g.get_name();
	g.set_name(name);
	
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
		switch (number){
		case 0:
			exit(1);
		
		case 1: 
			cout << "바꿀 이름을 입력하세요 : ";
			cin >> name;
			g.name_chage(name);	
			break;

		case 2:
			cout << "레벨업 합니다" << endl;
			g.level_up();		
			break;

		case 3:
			cout << "아이템을 주웠습니다" << endl;
			g.add_item();			
			break;

		case 4:
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
