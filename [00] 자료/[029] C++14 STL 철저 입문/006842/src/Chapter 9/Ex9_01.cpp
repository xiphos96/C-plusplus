// Ex9_01.cpp
// istream_iterator �Լ� ����� ȣ���ϴ� ����
#include <iostream>                                   // ǥ�� ��Ʈ��
#include <iterator>                                   // ��Ʈ�� �ݺ��� 

int main()
{
  std::cout << "Enter some integers - enter Ctrl+Z to end.\n";
  std::istream_iterator<int> iter {std::cin};         // ���� �Է� ��Ʈ�� �ݺ��ڸ� ����...
  std::istream_iterator<int> copy_iter {iter};        // ...������ ����
  std::istream_iterator<int> end_iter;                // �� �Է� ��Ʈ�� �ݺ��� ����
  // ���� �� ���� �о sum�� ����
  int sum {};
  while(iter != end_iter)                             // Ctrl+Z�� ���� ������ ���
  {
    sum += *iter++;
  }
  std::cout << "Total is " << sum << std::endl;

  std::cin.clear();                                   // EOF ���¸� ����
  std::cin.ignore();                                  // ���ڵ��� ����

  // �ݺ����� �������� ����� ������ �б�
  std::cout << "Enter some more integers - enter Ctrl+Z to end.\n";
  int product {1};
  while(true)
  {
    if(copy_iter == end_iter) break;                  // Ctrl+Z�� ������ �ߴ�
    product *= *copy_iter++;
  }
  std::cout << "product is " << product << std::endl;

}
