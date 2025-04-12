#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
	vector<int> intVector;
	intVector.push_back(12);
	intVector.push_back(100);
	intVector.push_back(77);
	vector<int>::iterator findIter;
	// intVector의 처음과 끝에서 12를 찾는다.
	findIter = find(intVector.begin(), intVector.end(), 12);
	if (findIter != intVector.end()) {
		cout << "12를 찾았습니다." << endl;
	}
	else {
		cout << "12는 없습니다." << endl;
	}
	// intVector 두 번째와 끝에서 12를 찾는다.
	// ++intVector.begin()으로 반복자를 한칸 이동시킨다.
	findIter = find(++intVector.begin(), intVector.end(), 12);
	if (findIter != intVector.end()) {
		cout << "12를 찾았습니다." << endl;
	}
	else {
		cout << "12는 없습니다." << endl;
	}

	return 0;
}