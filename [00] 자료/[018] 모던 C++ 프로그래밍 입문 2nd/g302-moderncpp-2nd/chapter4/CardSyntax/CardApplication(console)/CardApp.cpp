#include "Card.h"

int main()
{
	Rect a{ 50, 100, 150, 200 };
	Card b{ 200, 100, 2, 7 };
	std::shared_ptr<Rect> c = std::make_shared<Card>(300, 100, 3, 5);
	cout << a << endl;
	cout << b << endl;
	cout << *c << endl;
	b.flip();
	cout << "after b flips" << endl;
	cout << a << endl;
	cout << b << endl;
	cout << *c << endl;
	cout << "after down casting c" << endl;
	CardPtr k = std::static_pointer_cast<Card>(c);
	k->flip();
	cout << a << endl;
	cout << b << endl;
	cout << *k << endl;

	return 0;
}