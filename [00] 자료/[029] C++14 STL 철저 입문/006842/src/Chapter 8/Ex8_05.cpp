// Ex8_05.cpp
// ���Ժ����� Ȯ���ϴ� ����
#include <random>                                      // ������ ���� �ѹ� ������
#include <algorithm>                                   // generate(), for_each(), max_element(), transform()
#include <numeric>                                     // accumulate() 
#include <vector>                                      // vector �����̳�
#include <map>                                         // map �����̳�
#include <cmath>                                       // pow(), round() �Լ�
#include <iostream>                                    // ǥ�� ��Ʈ��
#include <iomanip>
#include <string>
using std::string;
using Params = std::normal_distribution<>::param_type;

// ���� ���� �������� ������ �׸��� ���ø�
template<typename Iter>
void dist_plot(Iter& beg_iter, Iter& end_iter, size_t width=90)
{
  // ���� ���(distribution plot)�� �׸��� ���� ������ ����
  std::map<int, size_t> plot_data;                 // ���Ҵ� pair<value, frequency>

  // ��� ���� ���(plot) �ȿ� �ִ��� Ȯ��
  auto pr = std::minmax_element(beg_iter, end_iter, [](const double v1, const double v2) 
                                                      { return v1 < v2; });
  for(int n {static_cast<int>(*pr.first)}; n < static_cast<int>(*pr.second); ++n)
    plot_data.emplace(n,0);

  // ��� �����͸� ����
  std::for_each(beg_iter, end_iter,
    [&plot_data](double value) { ++plot_data[static_cast<int>(std::round(value))]; });

  // ��鿡 �׸� �ִ� �� ã�� - �ݵ�� ������ �ʺ� �ȿ� ����� �Ѵ�
  size_t max_f {std::max_element(std::begin(plot_data), std::end(plot_data),
    [](const std::pair<int,int>& v1, const std::pair<int,int>& v2)
                            { return v1.second < v2.second; })->second};

  // ������ ������׷����� �׸���
  std::for_each(std::begin(plot_data), std::end(plot_data),
    [max_f, width](const std::pair<int, int>& v)
  {std::cout << std::setw(3) << v.first << " -| " 
                             << string((width*v.second) / max_f, '*') << std::endl; });
}


int main()
{
  std::random_device rd;
  std::default_random_engine rng {rd()};
  std::normal_distribution<> norm;
  double mu {}, sigma {};
  const size_t sample_count{20000};
  std::vector<double> values(sample_count);
  while(true)
  {
    std::cout << "\nEnter values for the mean and standard deviation, or Ctrl+Z to end: ";
    if((std::cin >> mu).eof()) break;
    std::cin >> sigma;
    norm.param(Params{mu, sigma});
    std::generate(std::begin(values), std::end(values), [&norm, &rng]{ return norm(rng); });

    // ������׷��� �׸� �����͸� ����
    dist_plot(std::begin(values), std::end(values));

    // ������ ���� ���� ������ ��հ� ǥ�������� ���Ѵ� 
    double mean {std::accumulate(std::begin(values), std::end(values), 0.0)/ values.size()};

    std::transform(std::begin(values), std::end(values), std::begin(values),
                   [&mean](double value) { return std::pow(value - mean,2); });
    double s_dev {std::sqrt(std::accumulate(std::begin(values), 
                                       std::end(values), 0.0) /(values.size() - 1))};
    std::cout << "For generated values, mean = " << mean 
              << " standard deviation = " << s_dev << std::endl;
  }
}