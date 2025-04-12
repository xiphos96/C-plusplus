//=========================================================
// 응용 과제 2
// 실습 과제를 발전시킴
// 콘솔 입출력
//=========================================================
#include <iostream>
using namespace std;

int getInt() {
	int x;
	bool done = false;
	do {
		cout << "please type an integer: ";
		cin >> x;
		if (cin)
			done = true;
		else {
			cout << "could not find a valid integer." << endl;
			cin.clear();
		}
		while (cin.get() != '\n') {};
	} while (!done);
	return x;
}

int main()
{
	char name[20];
	cout << "enter your name: ";
	cin >> name;
	cout << "enter five integers." << endl;
	for (int i = 0; i < 5; ++i)
		cout << i + 1 << ". you entered " << getInt() << endl;
	cout << "thanks, " << name << "!" << endl;

	return 0;
}