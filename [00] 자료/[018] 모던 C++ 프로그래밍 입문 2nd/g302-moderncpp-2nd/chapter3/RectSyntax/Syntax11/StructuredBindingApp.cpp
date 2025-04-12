#include <iostream>
#include <tuple>

int main()
{
    // double, char, string의 튜플
    auto tuple = std::make_tuple(1.9, 'a', "eum");
    // C++17 이전, 변수들을 먼저 선언
    double d;
    char c;
    std::string s;
    // std::tie 함수를 이용해서 바인딩
    std::tie(d, c, s) = tuple;
    std::cout << "d=" << d << " c=" << c
                << " s=" << s << std::endl;

    // C++17, 바로 구조적 바인딩이 가능
    auto [d2, c2, s2] = tuple;
    std::cout << "d2=" << d2 << " c2=" << c2
                << " s2=" << s2 << std::endl;

    // 구조적 레퍼런스 바인딩도 가능
    auto& [d3, c3, s3] = tuple;
    d3 = 123.5;
    s3 = "doohun";
    std::cout << "d3=" << d3 << " tuple<0>="
                << std::get<0>(tuple) << std::endl;
    std::cout << "s3=" << s3 << " tuple<3>="
                << std::get<2>(tuple) << std::endl;

    return 0;
}