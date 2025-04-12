#include <iostream>
#include <utility>		// pair
#include <string>
using std::pair; using std::make_pair;
using std::string;
using std::cout; using std::endl;

int main()
{
	// �Ķ���Ͱ� �� ���� �����ڿ� ����Ʈ ������
	pair<string, int> myPair("doohun", 5);
	pair<string, int> thisPair;
	thisPair.first = "youngmi";
	thisPair.second = 7;
	// ���� ������
	pair<string, int> thatPair(thisPair);
	// make_pair �Լ�
	auto thePair = make_pair("wonjin", "eum");
	// operator<
	if (myPair < thisPair) {
		cout << "myPair is less than thisPair" << endl;
	}
	// operator==
	if (thisPair == thatPair)
		cout << "thisPair is equal to thatPair" << endl;
	else {
		cout << "thisPair is not equal to thatPair" << endl;
	}

	return 0;
}