
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

Particle* GetParticlePointer(std::shared_ptr<Particle>& ParticlePtr)
{
	return ParticlePtr.get();
}

int main()
{
	std::shared_ptr<Particle> ParticlePtr(new Particle(10));	
	
	// Particle �ν��ͽ��� ������ �� ���� ��� ���� ���
	Particle& ParticleRef = *ParticlePtr;
	std::cout << "ParticleRef�� ID: " << ParticleRef.m_nID << std::endl;

	// Particle �ν��ͽ��� �����͸� �� ��� ���� ���
	Particle* pParticle = GetParticlePointer(ParticlePtr);
	std::cout << "pParticle�� ID: " << pParticle->m_nID << std::endl;

	// Particle1�� ���ؼ� Particle �ν��ͽ��� ��� ����
	std::cout << "ParticlePtr�� ID: " << ParticlePtr->m_nID << std::endl;
	
	return 0;
}

            