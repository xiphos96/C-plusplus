// Ex8_04.cpp
// ����⸦ ������ �� ���ϱ�
#include <iostream>                                             // ǥ�� ��Ʈ��
#include <random>                                               // ����, ���� �ѹ� ������
#include <cmath>                                                // sin() �Լ�

int main()
{
  const double pi = 3.1415962;
  double stick_length{};                                        // ����� ����
  double board_width {};                                        // ������ �ʺ�

  std::cout << "����ٴ��� �ʺ� �Է��ϼ���: ";
  std::cin >> board_width;
  std::cout << "������� ���̸� �Է��ϼ���(����ٴ��� �ʺ� " << board_width << "���� �۾ƾ� ��): ";
  std::cin >> stick_length;
  if(board_width < stick_length) stick_length = 0.9*board_width;

  std::uniform_real_distribution<> angle {0.0, pi};             // ����� ������ ����

  // ����� �߽� ��ġ�� ����, �������� �����ڸ��� ��������
  std::uniform_real_distribution<> position {0.0, board_width}; 

  std::random_device rd;                                        // ��������� �õ� �ҽ�
  std::default_random_engine rng {rd()};                        // ���� �ѹ� �����⸦ �����
  const size_t throws{5'000'000};                               // ���� �������� Ƚ��
  size_t hits {};                                               // �������� �����ϴ� ������� ����

  // ����⸦ throws Ƚ����ŭ ������
  for(size_t i {}; i < throws; ++i)
  {
    double y {position(rng)};
    double theta {angle(rng)};
    // ����Ⱑ �������� �����ڸ��� �����ϴ��� �˻�
    if(((y + stick_length*sin(theta)/2) >= board_width) || ((y - stick_length*sin(theta) / 2) <= 0))
      ++hits;                                                    // �����ϸ� ī��Ʈ�� ����
  }

  std::cout << "�������� �����ڸ��� �����ϴ� ������� Ȯ��: "
              << (static_cast<double>(hits)/ throws) << std::endl;
  std::cout << "���� ��: " << (2* stick_length*throws)/(board_width*hits) << std::endl;
}
