// Ex2_03.cpp
// ���� �����̳ʿ��� �뷮�� ��� �����ϴ��� �����ϱ�
#include <iostream>                             // ǥ�� ��Ʈ��
#include <vector>                               // ���� �����̳�

int main()
{
  std::vector <size_t> sizes;                    // ���ҵ��� ���� ���
  std::vector <size_t> capacities;               // �뷮 ���
  size_t el_incr {10};                           // �ʱ� ���� ī��Ʈ ����
  size_t incr_count {4 * el_incr};               // ���� ī��Ʈ�� ���� ����

  for (size_t n_elements {}; n_elements < incr_count; n_elements += el_incr)
  {
    std::vector<int> values(n_elements);
    std::cout << "\nAppending to a vector with " << n_elements << " initial elements:\n";
    sizes.push_back(values.size());
    size_t space {values.capacity()};
    capacities.push_back(space);

    // �뷮�� ������ ������ ���ҵ��� �߰��Ѵ�
    size_t count {};                             // �뷮 ���� ī��Ʈ
    size_t n_increases {10};
    while (count < n_increases)
    {
      values.push_back(22);                      // �� ���Ҹ� �߰�
      if (space < values.capacity())             // �뷮�� �����ϰ�...
      {                                          // ...���� ũ��� �뷮�� ���
        space = values.capacity();
        capacities.push_back(space);
        sizes.push_back(values.size());
        ++count;
      }
    }
    // ������ �߻��� �� ũ��� �뷮�� ǥ��
    std::cout << "Size/Capacity: ";
    for (size_t i {}; i < sizes.size(); ++i)
      std::cout << sizes.at(i) << "/" << capacities.at(i) << "  ";
    std::cout << std::endl;
    sizes.clear();                               // ��� ���� ����
    capacities.clear();                          // ��� ���� ����
  }
}
