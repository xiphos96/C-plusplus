#include <boost/tuple/tuple.hpp>
#include <string>

#include <boost/tuple/tuple_comparison.hpp>
#include <assert.h>
#include <set>

void foo1() {
    boost::tuple<int, std::string> almost_a_pair(10, "Hello");
    boost::tuple<int, float, double, int> quad(10, 1.0f, 10.0, 1);


    int i = boost::get<0>(almost_a_pair);
    const std::string& str = boost::get<1>(almost_a_pair);
    double d = boost::get<2>(quad);

    (void) i;
    (void) str;
    (void) d;

    using namespace boost;

    // 튜플 비교 연산자는 "boost/tuple/tuple_comparison.hpp" 에 정의되어 있다
    // 이 파일을 잊지 말고 불러들이자!
    std::set<tuple<int, double, int> > s;
    s.insert(make_tuple(1, 1.0, 2));
    s.insert(make_tuple(2, 10.0, 2));
    s.insert(make_tuple(3, 100.0, 2));
}

void foo2() {
    using namespace boost;

    // C++11 이어야 한다
    //auto t = make_tuple(0, -1.0, 2);
    //assert(2 == get<2>(t));
    assert(2 == get<2>(make_tuple(0, -1.0, 2)));

    // t의 데이터형에 대한 컴파일 시간 가정 검사를 할 수 있다. 
    // 어떻게 하는 건지 궁금한가?
    // 4 장, '컴파일 시간 묘기' 참고
}

void foo3() {
    boost::tuple<int, float, double, int> quad(10, 1.0f, 10.0, 1);
    int i;
    float f;
    double d;
    int i2;

    // 'quad' 변수에서 'i', 'f', 'd', 'i2'로 값 전달
    boost::tie(i, f, d, i2) = quad;

    assert(i == 10);
    assert(i2 == 1);
}

struct id_name_pair {
    int id;
    std::string name;
};

int main () {
    foo1();
    foo2();
    foo3();

    return 0;
}
