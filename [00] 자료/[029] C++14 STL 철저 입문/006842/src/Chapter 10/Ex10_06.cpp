// Ex10_06.cpp
// complex ��ü�� ����� �渮�� ������ ����Ż �̹����� �����ϴ� ����
#include <iostream>                                      // ǥ�� ��Ʈ��
#include <iomanip>                                       // ��Ʈ�� ������
#include <complex>                                       // complex Ÿ��
#include <chrono>                                        // Ŭ��, duration, time_point
using std::complex;
using namespace std::chrono;
using namespace std::literals;

// time_point<>�� ���� ��Ȯ�� �ð� ������ �� ������ ����Ѵ�
template<typename TimePoint>
void print_timepoint(const TimePoint& tp, size_t places = 0)
{
  auto elapsed = tp.time_since_epoch();          // �ð� ������ ���� duration ��ü

  auto seconds = duration_cast<duration<double>>(elapsed).count();
  std::cout << std::fixed << std::setprecision(places) << seconds << " seconds\n";
}

int main()
{
  const int width {100}, height {100};                     // �̹��� ���� ����
  size_t count {100};                                      // ��͸� ���� �ݺ� ī��Ʈ
  char image[width][height];
  auto start_time = steady_clock::now();                   // ���� ������ ���� time_point ��ü
  complex<double> c {-0.7, 0.27015};                       // z = z*z + c���� ��� c ����

  for(int i {}; i < width; ++i)                            // �ȼ��� width�� ���� �ݺ�
  {
    for(int j {}; j < height; ++j)                         // �ȼ��� height�� ���� �ݺ�
    {
      // -1�� +1 ������ �Ǽ��ο� ������� ������(Ȯ��/���)
      auto re = 1.5*(i - width/2) / (0.5*width);
      auto im = (j - height/2) / (0.5*height);
      complex<double> z {re,im};                           // ���� ����� ��
      image[i][j] = ' ';                                   // �渮�� ������ �ƴ� ��
      // z=z*z+c ī��Ʈ ��ŭ �ݺ�
      for(size_t k {}; k < count; ++k)
      {
        z = z*z + c;
      }
      if(std::abs(z) < 2.0)                                // ���� ���⿡ �ش��Ѵٸ�...
        image[i][j] = '*';                                 // ...�渮�� ���տ� �ش�
    }
  }
  auto end_time = std::chrono::steady_clock::now();        // �� ������ ���� time_point ��ü
  auto elapsed = end_time - start_time.time_since_epoch();
  std::cout << "Time to generate a Julia set with " << width << "x" << height << " pixels is ";
  print_timepoint(elapsed, 9);

  std::cout << "The Julia set looks like this:\n";
  for(size_t i {}; i < width; ++i)
  {
    for(size_t j {}; j < height; ++j)
      std::cout << image[i][j];
    std::cout << '\n';
  }
}
