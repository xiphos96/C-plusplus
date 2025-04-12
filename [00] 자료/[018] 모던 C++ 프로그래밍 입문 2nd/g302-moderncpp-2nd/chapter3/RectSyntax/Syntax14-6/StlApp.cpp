#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

double mean(const vector<int>& nums)
{
	double sum = accumulate(nums.begin(), nums.end(),
							0, plus<int>());
	return sum / nums.size();
}

int main()
{
	vector<int> nums;
	for (int i = 0; i < 10; ++i)
		nums.push_back(i);
	cout << mean(nums) << endl;

	return 0;
}