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
	// intVector�� ó���� ������ 12�� ã�´�.
	findIter = find(intVector.begin(), intVector.end(), 12);
	if (findIter != intVector.end()) {
		cout << "12�� ã�ҽ��ϴ�." << endl;
	}
	else {
		cout << "12�� �����ϴ�." << endl;
	}
	// intVector �� ��°�� ������ 12�� ã�´�.
	// ++intVector.begin()���� �ݺ��ڸ� ��ĭ �̵���Ų��.
	findIter = find(++intVector.begin(), intVector.end(), 12);
	if (findIter != intVector.end()) {
		cout << "12�� ã�ҽ��ϴ�." << endl;
	}
	else {
		cout << "12�� �����ϴ�." << endl;
	}

	return 0;
}