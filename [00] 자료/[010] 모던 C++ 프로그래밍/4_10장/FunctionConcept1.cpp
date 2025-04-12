#include <iostream>
using namespace std;

class Chulsoo
{
public:
	void Eat();
};

void Chulsoo::Eat()
{
	cout << "Ã¶¼ö´Â ¸Ô´Â´Ù" << endl;
}

int main(void)
{
	Chulsoo chulsoo;
	chulsoo.Eat();
	return 0;
}