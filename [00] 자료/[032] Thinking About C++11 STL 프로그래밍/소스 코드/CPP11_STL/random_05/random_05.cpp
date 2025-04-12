
#include <random>
#include <iostream>

int main() 
{
	std::mt19937_64 rng1(3244);

	std::bernoulli_distribution dist(0.7);

	int nSuccess = 0;
	int nFail = 0;

	for (int i = 0; i < 100; ++i) 
	{
		bool result = dist(rng1);

		if(result)
			++nSuccess;
		else
			++nFail;
	}


	std::cout << "���� Ƚ��: " << nSuccess << ",  ���� Ƚ��: " << nFail << std::endl;

	return 0;
}

