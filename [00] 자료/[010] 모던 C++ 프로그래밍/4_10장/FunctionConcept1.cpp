#include <iostream>
using namespace std;

class Chulsoo
{
public:
	void Eat();
};

void Chulsoo::Eat()
{
	cout << "ö���� �Դ´�" << endl;
}

int main(void)
{
	Chulsoo chulsoo;
	chulsoo.Eat();
	return 0;
}