// Ex10_02.cpp
// valarray ��ü�� ����� ���� �������� ������ �����ϰ� ����߸��� ����
#include <numeric>                                       // iota()
#include <iostream>                                      // ǥ�� ��Ʈ��
#include <iomanip>                                       // ��Ʈ�� ������
#include <algorithm>                                     // for_each()
#include <valarray>                                      // valarray
const static double g {32.0};                            // �߷� ���ӵ��� ���� ���ӵ�

int main()
{
  double height {};                                      // �ǹ� ����
  std::cout << "Enter the approximate height of the building in feet: ";
  std::cin >> height;

  // ������ �������� �ð��� ��(sec)�� ���
  double end_time {std::sqrt(2 * height / g)};
  size_t max_time {1 + static_cast<size_t>(end_time + 0.5)};

  std::valarray<double> times(max_time+1);               // �ð��� ���� �迭
  std::iota(std::begin(times), std::end(times), 0);      // �ʱ�ȭ: 0 to max_time
  *(std::end(times) - 1) = end_time;                     // ������ �ð� ���� ����

  // �� �ʴ� �Ÿ��� ���
  auto distances = times.apply([](double t) { return 0.5*g*t*t; });

  // �� �ʴ� �ӵ��� ��� 
  auto v_fps = sqrt(distances.apply([](double d) { return 2 * g*d;}));

  // ��� ����� ���� ���� ǥ����
  auto print = [](double v) { std::cout << std::setw(6) << static_cast<int>(std::round(v)); };

  // �ð��� ��� - ������ ���� Ư���� ���̽��� ó��...
  std::cout << "Time (seconds): ";
  std::for_each(std::begin(times), std::end(times)-1, print);
  std::cout << std::setw(6) << std::fixed << std::setprecision(2) << *(std::end(times)-1);

  std::cout << "\nDistances(feet):";
  std::for_each(std::begin(distances), std::end(distances), print);

  std::cout << "\nVelocity(fps):  ";
  std::for_each(std::begin(v_fps), std::end(v_fps), print);

  // mph(�ð��� ����)�� �ӵ��� ���ϰ� ����Ѵ�
  auto v_mph = v_fps.apply([](double v) { return v*60/88; });
  std::cout << "\nVelocity(mph):  ";
  std::for_each(std::begin(v_mph), std::end(v_mph), print);
  std::cout << std::endl;
}
