// Ex8_01.cpp
// 8 �õ带 �������� �����ϱ�
#include <random>                                // random_device Ŭ����
#include <iostream>                              // ǥ�� ��Ʈ��

int main()
{
  std::random_device rd;                         // �õ带 �����ϴ� �Լ� ��ü
  for(size_t n {}; n < 8; ++n)
    std::cout << rd() << " ";
  std::cout << std::endl;
}
