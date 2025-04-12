// ��Ʈ ���� - ��⿭�� �ִ� ���� �����ϰ� ó���Ѵ�
#ifndef CHECKOUT_H
#define CHECKOUT_H
#include <queue>                                 // queue �����̳�
#include "Customer.h"

class Checkout
{
private:
  std::queue<Customer> customers;                // ����� ��ٸ��� ��⿭(ť)

public:
  void add(const Customer& customer) { customers.push(customer); }
  size_t qlength() const { return customers.size(); }

  // 1�о� ��� �ð��� ������Ų��
  void time_increment() 
  { // ��ٸ��� ���� �ִٸ�...
    if (!customers.empty())
    { 
      if (customers.front().time_decrement().done()) // ���� ����� ��������...
        customers.pop();                             // ...��⿭���� �����Ѵ�
    }
  };

  bool operator<(const Checkout& other) const { return qlength() < other.qlength(); }
  bool operator>(const Checkout& other) const { return qlength() > other.qlength(); }
};
#endif
