// ���� ������� ���� �ð����� �����Ѵ�
#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer
{
private:
  size_t service_t {};                           // ������� ���� �ð�

public:
  explicit Customer(size_t st = 10) :service_t {st}{}

  // ������� ��� �ð��� ���ҽ�Ų��
  Customer& time_decrement()
  {
    --service_t;
    return *this;
  }
  bool done() { return service_t == 0; }
};
#endif