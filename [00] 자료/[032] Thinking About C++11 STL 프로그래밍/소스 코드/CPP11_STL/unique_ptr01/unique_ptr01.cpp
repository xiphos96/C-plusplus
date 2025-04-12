
#include <iostream>
#include <vector>
#include <memory>

class Particle
{
public:
	Particle(int nID)
	{
		m_nID = nID;
		std::cout << "Particle " << m_nID << "�� ����. " << std::endl;
	}

	~Particle()
	{
		std::cout << "Particle " << m_nID << "�� �Ҹ�. " << std::endl;
	}

	int m_nID;
};



int main()
{
	{
		std::unique_ptr<Particle> ParticlePtr( new Particle( 1 ));
	}

	std::unique_ptr<Particle> ParticlePtr1( new Particle( 11 ));
	
	std::vector<std::unique_ptr<Particle>> ParticlePtrs;

	std::cout << "�����̳� ParticlePtrs�� ParticlePtr1 �ֱ�" << std::endl;
	//ParticlePtrs.push_back( ParticlePtr1 );	// ������ ����
	ParticlePtrs.push_back( std::move(ParticlePtr1) );

	if( ParticlePtr1.get() == nullptr )
	{
		std::cout << "ParticlePtr1���� �����ϴ� ��ü ����" << std::endl;
	}

	return 0;
}

