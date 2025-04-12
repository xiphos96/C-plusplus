// Ex3_02.cpp
// ���밡 ������ ��Ʈ �ùķ��̼�
#include <iostream>                              // ǥ�� ��Ʈ��
#include <iomanip>                               // ��Ʈ�� ������
#include <vector>                                // vector �����̳�
#include <string>                                // string Ŭ����
#include <numeric>                               // accumulate()
#include <algorithm>                             // min_element�� max_element
#include <random>                                // ������ ���� ����

#include "Customer.h"
#include "Checkout.h"

using std::string;
using distribution = std::uniform_int_distribution<>;

// ���� �ð��� ���� �׷����� ���
void histogram(const std::vector<int>& v, int min)
{
  string bar (60, '*');                          // �࿡ ����� *
  for (size_t i {}; i < v.size(); ++i)
  {
    std::cout << std::setw(3) << i+min << " "    // ���� �ð��� index + min
      << std::setw(4) << v[i] << " "             // �߻� Ƚ�� ���
      << bar.substr(0, v[i])                     // ...�׸��� * ����
      << (v[i] > static_cast<int>(bar.size()) ? "...": "")
      << std::endl;
  }
}

int main()
{
  std::random_device random_n;

  // �ּ� �ִ� üũ�ƿ� �Ⱓ ���� - �� ����
  int service_t_min {2}, service_t_max {15};
  distribution service_t_d {service_t_min, service_t_max};

  // ��Ʈ ���� �ÿ� ���� �ּ�, �ִ� ���ڸ� ����
  int min_customers {15}, max_customers {20};
  distribution n_1st_customers_d {min_customers, max_customers};

  // ���� �����ϴ� �ð� ������ �ּ�, �ִ� ����
  int min_arr_interval {1}, max_arr_interval {5};
  distribution arrival_interval_d {min_arr_interval, max_arr_interval};

  size_t n_checkouts {};
  std::cout << "��Ʈ ���� ���� �Է�: ";
  std::cin >> n_checkouts;
  if(!n_checkouts)
  {
    std::cout << "���� ������ 1 �̻��̾�� �մϴ�. 1�� �����մϴ�." << std::endl;
    n_checkouts = 1;
  }

  std::vector<Checkout> checkouts {n_checkouts};
  std::vector<int> service_times(service_t_max-service_t_min+1);

  // ��Ʈ ������ �� ��ٸ��� ���� �߰�
  int count {n_1st_customers_d(random_n)};
  std::cout << "��Ʈ ���� �ÿ� ��� �� ��: " << count << std::endl;
  int added {};
  int service_t {};
  while (added++ < count)
  {
    service_t = service_t_d(random_n);
    std::min_element(std::begin(checkouts), std::end(checkouts))->add(Customer(service_t));
    ++service_times[service_t - service_t_min];
  }

  size_t time {};                                // ��� �ð� ����
  const size_t total_time {600};                 // �ùķ��̼� �Ⱓ - �� ����
  size_t longest_q {};                           // ���� �� ��⿭ ���̸� ����

  // ���� ���� ������ �������� �ð� ����
  int new_cust_interval {arrival_interval_d(random_n)};

  // total_time �� ���� ��Ʈ �ùķ��̼��� ����
  while (time < total_time)                      // �ð� ��ŭ ���� �ùķ��̼�
  {
    ++time;                                      // 1�о� ����

    // ���� ������ 0�� �� �� ���� �����Ѵ�
    if (--new_cust_interval == 0)
    {
      service_t = service_t_d(random_n);         // �� ���� �ð��� �������� ����
      std::min_element(std::begin(checkouts), std::end(checkouts))->add(Customer(service_t));
      ++service_times[service_t - service_t_min];  // ���� �ð��� ����Ѵ�

      // ���� �� ��⿭�� ����� ������Ʈ
      for (auto & checkout : checkouts)
        longest_q = std::max(longest_q, checkout.qlength());

      new_cust_interval = arrival_interval_d(random_n);
    }

    // ���뿡���� �ð��� ������Ʈ- �� ť�� ù ��° ���� ó��
    for (auto & checkout : checkouts)
      checkout.time_increment();
  }

  std::cout << "�ִ� ��⿭ ���� = " << longest_q << std::endl;
  std::cout << "\n���� �ð� ���� �׷���:\n";
  histogram(service_times, service_t_min);

  std::cout << "\n���� �� �� ��: "
            << std::accumulate(std::begin(service_times), std::end(service_times), 0)
            << std::endl;
}
