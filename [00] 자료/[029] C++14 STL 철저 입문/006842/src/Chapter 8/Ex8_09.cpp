// Ex8_09.cpp
// ���� ���� ������ �����ϴ� ����
#include <random>                                       // ������ ���� �ѹ� ������
#include <vector>                                       // vector �����̳�
#include <map>                                          // map �����̳�
#include <utility>                                      // pair Ÿ��
#include <algorithm>                                    // copy(), count(), remove()
#include <iostream>                                     // ǥ�� ��Ʈ��
#include <iterator>                                     // ��Ʈ�� �ݺ���
#include <iomanip>                                      // ��Ʈ�� ������
#include <string>                                       // string Ŭ����
#include <cmath>
using std::string;

int main()
{
  std::vector<double> v {10, 30, 40, 55, 60};             // ���� ��
  std::vector<double> w {6, 12, 9, 6, 0};                 // ���� ���� ������ ����ġ
  std::piecewise_linear_distribution<> d {std::begin(v), std::end(v), std::begin(w)};

  // ���� ���� ���� Ȯ���� ���
  auto values = d.intervals();
  std::cout << "Sample values: ";
  std::copy(std::begin(values), std::end(values), std::ostream_iterator<double>{std::cout, " "});
  std::cout << "  probability densities: ";
  auto probs = d.densities();
  std::copy(std::begin(probs), std::end(probs), std::ostream_iterator<double>{std::cout, " "});
  std::cout << '\n' << std::endl;
  
  std::random_device rd;
  std::default_random_engine rng {rd()};
  std::map<int, size_t> results;                          // ���� ���� ������ �����ϰ� ī��Ʈ
                                                          // ���� ���� ���� ����...
  for(size_t i {}; i < 20000; ++i)
    ++results[static_cast<int>(std::round(d(rng)))];

  // ���� ������ �׸���
  auto max_count = std::max_element(std::begin(results), std::end(results),
    [](const std::pair<int, size_t>& pr1, const std::pair<int, size_t>& pr2)
  { return pr1.second < pr2.second; })->second;
  std::for_each(std::begin(results), std::end(results),
                [max_count](const std::pair<int, size_t>& pr)
                {
                  if(!(pr.first % 10))  // 10�� ����� ���� ǥ��
                    std::cout << std::setw(3) << pr.first << "-|";
                  else
                    std::cout << "    |";
                  std::cout << std::string(pr.second * 80 / max_count, '*')
                            << '\n';
                });
}
