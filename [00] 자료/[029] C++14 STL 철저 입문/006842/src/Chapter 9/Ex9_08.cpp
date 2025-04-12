// Ex9_08.cpp
// ��Ʈ�� �ݺ��ڸ� ����� ���� �µ� ������ �����ϴ� ����
#include <iostream>                                   // ǥ�� ��Ʈ��
#include <iterator>                                   // �ݺ���, begin(), end()
#include <iomanip>                                    // ��Ʈ�� ������
#include <fstream>                                    // ���� ��Ʈ��
#include <algorithm>                                  // generate_n(), for_each()
#include <random>                                     // ������ ���� �ѹ�
#include <string>                                     // string Ŭ����
using std::string;

int main()
{
  string file_name {"temperatures.txt"};
  std::ofstream temps_out {file_name, std::ios_base::out | std::ios_base::trunc};
  const size_t n {50};                                // �ʿ��� �µ� ���� ����

  std::random_device rd;                              // ��������� �ҽ�
  std::mt19937 rng {rd()};                            // �޸��� Ʈ������ ������
  double mu {50.0}, sigma {15.0};                     // ���: 50, �µ� ǥ������: 15
  std::normal_distribution<> normal {mu, sigma};      // ���� ����

  // ���� �µ� ���� ���Ͽ� ����
  std::generate_n(std::ostream_iterator<double> { temps_out, " "}, n,
    [&rng, &normal]
  { return normal(rng); });
  temps_out.close();                                  // ��� ������ �ݱ�

  // ������ ������ ����Ѵ�
  std::ifstream temps_in {file_name};                 // ���� �µ� ���� �б� ���� ���� ����
  for_each(std::istream_iterator<double> {temps_in}, std::istream_iterator<double> {},
    [](double t) 
      { const size_t perline {10};
        static size_t count {};
        std::cout << std::fixed << std::setprecision(2) << std::setw(5) << t
                  << ((++count % perline) ? " " : "\n");
      });
  std::cout << std::endl;
  temps_in.close();                                       // �Է� ������ �ݱ�
}
