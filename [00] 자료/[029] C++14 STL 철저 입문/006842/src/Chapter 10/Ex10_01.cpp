// Ex10_01.cpp
// �ּ� ���� ȸ��
#include <numeric>                                       // accumulate(), inner_product()
#include <vector>                                        // vector �����̳�
#include <iostream>                                      // ǥ�� ��Ʈ��
#include <iomanip>                                       // ��Ʈ�� ������
#include <fstream>                                       // ���� ��Ʈ��
#include <iterator>                                      // �ݺ���, begin(), end()
#include <string>                                        // string Ŭ����
using std::string;

int main()
{
  // ������ ����: country_name renewables_per_person kwh_cost
  string file_in {"renewables_vs_kwh_cost.txt"};
  std::ifstream in {file_in};

  if(!in)                                       // ������ �ִ��� Ȯ��
  {
    std::cerr << file_in << " not open." << std::endl;
    exit(1);
  }

  std::vector<double> x;                        // 1�δ� ��� ������
  std::vector<double> y;                        // ų�ο�Ʈ �ð��� ���� ���

  // ������ �о �����͸� �����ش�
  std::cout << "   Country   " << " Watts per Head " << " kwh cost(cents) " << std::endl;
  while(true)
  {
    string country;
    double renewables {};
    double kwh_cost {};

    if((in >> country).eof()) break;                           // EOF ���� - �Ϸ�
    in >> renewables >> kwh_cost;
    x.push_back(renewables);
    y.push_back(kwh_cost);
    std::cout << std::left << std::setw(12) << country         // ���ڵ带 ���
              << std::right
              << std::fixed << std::setprecision(2) << std::setw(12) << renewables 
              << std::setw(16) << kwh_cost << std::endl;
  }

  auto n = x.size();                                            // ��ǥ�� ����
  auto sx = std::accumulate(std::begin(x), std::end(x), 0.0);   // x ������ �հ�
  auto sy = std::accumulate(std::begin(y), std::end(y), 0.0);   // y ������ �հ�
  auto mean_x = sx/n;                                           // x ������ ���
  auto mean_y = sy/n;                                           // y ������ ���

  // x*y ������ �հ�� x ������ �հ�
  auto sxy = std::inner_product(std::begin(x), std::end(x), std::begin(y), 0.0);
  auto sx_2 = std::inner_product(std::begin(x), std::end(x), std::begin(x), 0.0);

  double a {}, b {};                                            // ���� ���
  auto num = n*sxy - sx*sy;                                     // a�� ����
  auto denom = n*sx_2 - sx*sx;                                  // a�� �и�
  a = num / denom;
  b = mean_y - a*mean_x;
  std::cout << std:: fixed << std::setprecision(3) << "\ny = "  // ȸ�� ������ ���� 
            << a << "*x + " << b << std::endl;                  // ������ ���
}
