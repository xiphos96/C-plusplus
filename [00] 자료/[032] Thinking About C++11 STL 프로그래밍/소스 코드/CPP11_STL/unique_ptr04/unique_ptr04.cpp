
#include <iostream>
#include <memory>

class Particle
{
public:
	Particle()
	{
		std::cout << "Particle ������" << std::endl;
	}

	~Particle()
	{
		std::cout << "Particle �Ҹ���" << std::endl;
	}
};


int main()
{
	std::unique_ptr<Particle[]> ParticlePtr1( new Particle[3]);

	return 0;
}


