
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
	std::shared_ptr<Particle> Particle1(new Particle(1));	// ���� �� 1
	std::cout << "Particle1�� ���� ��: " << Particle1.use_count() << std::endl;
	
	{
		std::shared_ptr<Particle> Particle2 = Particle1;		// ���� �� 2
		std::cout << "Particle1�� ���� ��: " << Particle1.use_count() << std::endl;
		std::cout << "Particle2�� ���� ��: " << Particle2.use_count() << std::endl;
	}

	// Particle2�� �������� ����鼭 �ı��Ǿ� Particle1�� ���� ���� 1
	std::cout << "Particle1�� ���� ��: " << Particle1.use_count() << std::endl;

	// Particle1�� �ı��Ǹ鼭 ���� ���� 0 �̵Ǹ鼭 �ڵ����� �޸� ����
	return 0;
}

            