// Ex1_03.cpp
// �˰��� �Լ��� �����ϱ�
#include <iostream>                         // ǥ�� ��Ʈ��
#include <algorithm>                        // transform()
#include <iterator>                         // �ݺ���
#include <functional>                       // function

class Root
{
public:
  double operator()(double x) { return std::sqrt(x); };
};

int main()
{
  double data[] { 1.5, 2.5, 3.5, 4.5, 5.5};

  // �Լ� ��ü�� �����ϱ�
  Root root;                                // �Լ� ��ü
  std::cout << "Square roots are:" << std::endl;
  std::transform(std::begin(data), std::end(data),
                    std::ostream_iterator<double>(std::cout, " "), root);

  // ���� ǥ������ ���ڷ� ����ϱ�
  std::cout << "\n\nCubes are:" << std::endl;
  std::transform(std::begin(data), std::end(data),
                    std::ostream_iterator<double>(std::cout, " "), [](double x){ return x*x*x; });

  // std::function<> Ÿ���� ������ ���ڷ� ����ϱ�
  std::function<double(double)> op {[](double x){ return x*x; }};
  std::cout << "\n\nSquares are:" << std::endl;
  std::transform(std::begin(data), std::end(data),
                    std::ostream_iterator<double>(std::cout, " "), op);

  // �ٸ� ���� ǥ������ ȣ���ϴ� ���� ǥ������ ���ڷ� ����ϱ�
  std::cout << "\n\n4th powers are:" << std::endl;
  std::transform(std::begin(data), std::end(data),
             std::ostream_iterator<double>(std::cout, " "), [&op](double x){ return op(x)*op(x); });
  std::cout << std::endl;
}
