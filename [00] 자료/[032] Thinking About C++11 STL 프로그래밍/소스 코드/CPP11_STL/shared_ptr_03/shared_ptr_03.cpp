
#include <iostream>
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
	std::shared_ptr<Particle> ParticlePtr( new Particle(10) );	
	std::cout << "ParticlePtr�� ID: " << ParticlePtr->m_nID << std::endl;

	std::cout << "reset - �ٸ� �ν��Ͻ��� ��ü" << std::endl;
	ParticlePtr.reset( new Particle(11) );
	std::cout << "ParticlePtr�� ID: " << ParticlePtr->m_nID << std::endl;
	
	std::cout << "reset - �ν��Ͻ� ����" << std::endl;
	ParticlePtr.reset();
	std::cout << "ParticlePtr�� ���� ��: " << ParticlePtr.use_count() << std::endl;
	
	return 0;
}

            