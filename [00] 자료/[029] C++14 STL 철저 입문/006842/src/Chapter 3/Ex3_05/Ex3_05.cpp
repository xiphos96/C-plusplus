// Ex3_05.cpp
// ����Ʈ �����͸� ����� ��Ʈ ���� �ùķ��̼�
#include <iostream>                              // ǥ�� ��Ʈ��
#include <iomanip>                               // ��Ʈ�� ������
#include <vector>                                // vector �����̳�
#include <string>                                // string Ŭ����
#include <numeric>                               // accumulate()
#include <algorithm>                             // min_element�� max_element
#include <random>                                // ������ ���� ����
#include <memory>                                // ����Ʈ ������
#include "Checkout.h"
#include "Customer.h"

using std::string;
using distribution = std::uniform_int_distribution<>;
using PCheckout = std::unique_ptr<Checkout>;

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
  std::uniform_int_distribution<> service_t_d {service_t_min, service_t_max};

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

  std::vector<PCheckout> checkouts;
  checkouts.reserve(n_checkouts);                // ����Ʈ �����͸� ���� �޸� ����

  // ��Ʈ ������ �� ��ٸ��� ���� �߰�
  for (size_t i {}; i < n_checkouts; ++i)
    checkouts.push_back(std::make_unique<Checkout>());
  std::vector<int> service_times(service_t_max-service_t_min+1);

  // ��Ʈ ������ �� ��ٸ��� ���� �߰�
  int count {n_1st_customers_d(random_n)};
  std::cout << "��Ʈ ���� �ÿ� ��� �� ��: " << count << std::endl;
  int added {};
  int service_t {};

  // ���� �����͸� ���� ���� �񱳽� ����
  auto comp = [](const PCheckout& pc1, const PCheckout& pc2){ return *pc1 < *pc2; };
  while (added++ < count)
  {
    service_t = service_t_d(random_n);
    auto iter = std::min_element(std::begin(checkouts), std::end(checkouts), comp);
    (*iter)->add(std::make_unique<Customer>(service_t));
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
      (*std::min_element(std::begin(checkouts), std::end(checkouts), comp))->add(std::make_unique<Customer>(service_t));
      ++service_times[service_t - service_t_min];  // ���� �ð��� ����Ѵ�

      // ���� �� ��⿭�� ����� ������Ʈ
      for (auto& pcheckout : checkouts)
        longest_q = std::max(longest_q, pcheckout->qlength());

      new_cust_interval = arrival_interval_d(random_n);
    }

    // ���뿡���� �ð��� ������Ʈ- �� ť�� ù ��° ���� ó��
    for (auto& pcheckout : checkouts)
      pcheckout->time_increment();
  }

  std::cout << "Maximum queue length = " << longest_q << std::endl;
  std::cout << "\nHistogram of service times:\n";
  histogram(service_times, service_t_min);

  std::cout << "\nTotal number of customers today: "
            << std::accumulate(std::begin(service_times), std::end(service_times), 0)
            << std::endl;
}
