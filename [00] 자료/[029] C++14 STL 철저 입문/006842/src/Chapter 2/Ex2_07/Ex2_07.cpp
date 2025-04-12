// Ex2_07.cpp
// Numeric_Range ���ø� ����غ���
#include <algorithm>                         // copy()
#include <numeric>                           // accumulate()
#include <iostream>                          // ǥ�� ��Ʈ��
#include <vector>                            // ���� �����̳�
#include "Numeric_Range.h"                   // Numeric_Range<T> & Numeric_Iterator<T>

int main()
{
  Numeric_Range<double> range {1.5, 0.5, 5};
  auto first = range.begin();
  auto last = range.end();
  std::copy(first, last, std::ostream_iterator<double>(std::cout, "  "));
  std::cout << "\nSum = " << std::accumulate(std::begin(range), std::end(range), 0.0) << std::endl;

  // Numeric_Range���� �����̳ʸ� �ʱ�ȭ
  Numeric_Range<long> numbers {15L, 4L, 10};
  std::vector<long> data {std::begin(numbers), std::end(numbers)};
  std::cout << "\nValues in vector are:\n";
  std::copy(std::begin(data), std::end(data), std::ostream_iterator<long>(std::cout, "  "));
  std::cout << std::endl;

  // ������ �ִ� ���� ����ϱ�
  std::cout << "\nThe values in the numbers range are:\n";
  for (auto n : numbers)
    std::cout << n << " ";
  std::cout << std::endl;
}
