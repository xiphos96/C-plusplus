#include <iostream>
#include <tuple>

int main()
{
    // double, char, string�� Ʃ��
    auto tuple = std::make_tuple(1.9, 'a', "eum");
    // C++17 ����, �������� ���� ����
    double d;
    char c;
    std::string s;
    // std::tie �Լ��� �̿��ؼ� ���ε�
    std::tie(d, c, s) = tuple;
    std::cout << "d=" << d << " c=" << c
                << " s=" << s << std::endl;

    // C++17, �ٷ� ������ ���ε��� ����
    auto [d2, c2, s2] = tuple;
    std::cout << "d2=" << d2 << " c2=" << c2
                << " s2=" << s2 << std::endl;

    // ������ ���۷��� ���ε��� ����
    auto& [d3, c3, s3] = tuple;
    d3 = 123.5;
    s3 = "doohun";
    std::cout << "d3=" << d3 << " tuple<0>="
                << std::get<0>(tuple) << std::endl;
    std::cout << "s3=" << s3 << " tuple<3>="
                << std::get<2>(tuple) << std::endl;

    return 0;
}