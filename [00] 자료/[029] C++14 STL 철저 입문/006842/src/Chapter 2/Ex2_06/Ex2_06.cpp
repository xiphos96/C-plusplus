// Ex2_06.cpp
// ������ ����Ʈ ����ϱ�
#include <algorithm>                             // copy()
#include <iostream>                              // ǥ�� ��Ʈ��
#include <forward_list>                          // forward_list �����̳�
#include <iterator>                              // ��Ʈ�� �ݺ���
#include "Box.h"

// ������ ������ ���ҵ��� �����ϱ�
template<typename Iter>
void list_elements(Iter begin, Iter end)
{
  size_t perline {6};                            // ���� �� ����� �ִ� ������ ����
  size_t count {};                               // ������ ī��Ʈ
  while (begin != end)
  {
    std::cout << *begin++;
    if (++count % perline == 0)
    {
      std::cout << "\n";
    }
  }
  std::cout << std::endl;
}

int main()
{
  std::forward_list<Box> boxes;
  std::copy(std::istream_iterator<Box>(std::cin), std::istream_iterator<Box>(),
                                                                std::front_inserter(boxes));

  boxes.sort();                                    // ���ڸ� ����
  std::cout << "\n������ ������:\n";
  // Box ��ü�� �����ִ� �뵵 - ostream �ݺ��ڸ� ���
  std::copy(std::begin(boxes), std::end(boxes), std::ostream_iterator<Box>(std::cout, " "));
  std::cout << std::endl;

  // �� ���� ���ڸ� ����
  std::forward_list<Box> more_boxes {Box {3, 3, 3}, Box {5, 5, 5}, Box {4, 4, 4}, Box {2, 2, 2}};
  boxes.insert_after(boxes.before_begin(), std::begin(more_boxes), std::end(more_boxes));
  std::cout << "�� ���� ���ڸ� ������ ������:\n";
  list_elements(std::begin(boxes), std::end(boxes));

  boxes.sort();                                    // ���ڸ� ����
  std::cout << std::endl;
  std::cout << "�ٽ� ������ ������:\n";
  list_elements(std::begin(boxes), std::end(boxes));

  more_boxes.sort();
  boxes.merge(more_boxes);                         // �� ���� ���ڸ� ����
  std::cout << "more_boxes�� ������ ������:\n";
  list_elements(std::begin(boxes), std::end(boxes));

  boxes.unique();
  std::cout << "�ߺ� ������ ������ ������:\n";
  list_elements(std::begin(boxes), std::end(boxes));

  // ���� ���ڸ� ����
  const double max_v {30.0};
  boxes.remove_if([max_v](const Box& box){ return box.volume() < max_v; });
  std::cout << "���ǰ� 30 �̸��� ������ �����ϰ� ������ ������:\n";
  list_elements(std::begin(boxes), std::end(boxes));
}
