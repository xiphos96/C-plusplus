// ��Ʈ ���� - ��⿭�� �ִ� ���� ���� ����Ʈ �����͸� ���
#ifndef CHECKOUT_H
#define CHECKOUT_H
#include <queue>                                 // queue �����̳�
#include <memory>                                // ����Ʈ ������
#include "Customer.h"
using PCustomer = std::unique_ptr<Customer>;

class Checkout
{
private:
  std::queue<PCustomer> customers;                // ����� ��ٸ��� ��⿭

public:
  void add(PCustomer&& customer) { customers.push(std::move(customer)); }
  size_t qlength() const { return customers.size(); }

  // 1�о� ��� �ð��� ������Ų��
  void time_increment()
  {
    if (customers.front()->time_decrement().done())  // ���� ����� ��������...
      customers.pop();                               // ...��⿭���� �����Ѵ�
  };

  bool operator<(const Checkout& other) const { return qlength() < other.qlength(); }
  bool operator>(const Checkout& other) const { return qlength() < other.qlength(); }
};
#endif
