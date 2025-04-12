#include "Card.h"

int main()
{
	Card m(100, 100, 3, 8);
	Card n(200, 200, 3, 8);
	m.flip(); n.flip();
	cout << "m = " << m << endl;
	cout << "n = " << n << endl;
	if (m == n)
		cout << "m and n are equal." << endl;
	else
		cout << "m and n are not equal." << endl;

	return 0;
}