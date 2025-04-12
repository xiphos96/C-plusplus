#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class IsOdd {
public:
	bool operator()(int i) {
		return((i % 2) == 1);
	}
};

int main() {
	vector<int> intVector;
	intVector.push_back(10);
	intVector.push_back(32);
	intVector.push_back(21);
	intVector.push_back(26);
	IsOdd isOdd;
	// functor 사용
	auto it = find_if(intVector.begin(), intVector.end(), isOdd);
	cout << "Using functor, the first odd value: " << *it << endl;
	// lambda 사용
	auto it2 = find_if(intVector.begin(), intVector.end(), [](int i) {
		return((i % 2) == 1);
	});
	cout << "Using lambda, the first odd value: " << *it2 << endl;

	return 0;
}