#include <iostream>
using namespace std;

int main(void)
{
	Chulsoo chulsoo;
	chulsoo.Eat();
	return 0;
}

class Chulsoo
{
public:
	void Eat();
};

void Chulsoo::Eat()
{
	cout << "Ã¶¼ö´Â ¸Ô´Â´Ù" << endl;
}