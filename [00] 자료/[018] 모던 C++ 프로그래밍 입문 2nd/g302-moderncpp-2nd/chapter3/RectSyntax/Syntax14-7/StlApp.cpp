#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	vector<int> vec;
	vector<int>::iterator it;
	vec.push_back(41); vec.push_back(22);
	vec.push_back(88); vec.push_back(32);
	vec.push_back(89); vec.push_back(11);
	vec.push_back(76); vec.push_back(37);
	cout << "정렬 하기 전" << endl;
	for (it = vec.begin(); it != vec.end(); ++it) {
		cout << *it << ", ";
	}
	cout << endl << endl;
	// 오름차순 정렬
	sort(vec.begin(), vec.end());
	cout << "오름차순 정렬" << endl;
	for (it = vec.begin(); it != vec.end(); ++it) {
		cout << *it << ", ";
	}
	cout << endl << endl;
	// 내림차순 정렬
	sort(vec.begin(), vec.end(), greater<int>());
	cout << "내림차순 정렬" << endl;
	for (it = vec.begin(); it != vec.end(); ++it) {
		cout << *it << ", ";
	}
	cout << endl << endl;
	// 일부만 오름차순 정렬
	sort(vec.begin() + 4, vec.end());
	cout << "일부만 오름차순 정렬" << endl;
	for (it = vec.begin(); it != vec.end(); ++it) {
		cout << *it << ", ";
	}
	cout << endl;

	return 0;
}