using namespace std;
#include <iostream>
#include <string>
int main() {

	/*
	for (int i = 1; i < 10; i++)
	{
		cout << i << "´Ü" << endl;
		for (int j = 1; j < 10; j++)
		{
			cout << i << "*" << j << "=" << i * j << endl;
		}
	}
	*/
	int a = 1;
	int b = 1;
	while (a<10)
	{
		cout << a << "´Ü" << endl;
		a++;
		b = 1;
		while (b < 10) {
			cout << a << "*" << b << "=" << b * a << endl;
			b++;
		}
	}







}