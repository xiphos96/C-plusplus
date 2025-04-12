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

    // Ʃ�� �� �����ڴ� "boost/tuple/tuple_comparison.hpp" �� ���ǵǾ� �ִ�
    // �� ������ ���� ���� �ҷ�������!
    std::set<tuple<int, double, int> > s;
    s.insert(make_tuple(1, 1.0, 2));
    s.insert(make_tuple(2, 10.0, 2));
    s.insert(make_tuple(3, 100.0, 2));
}

void foo2() {
    using namespace boost;

    // C++11 �̾�� �Ѵ�
    //auto t = make_tuple(0, -1.0, 2);
    //assert(2 == get<2>(t));
    assert(2 == get<2>(make_tuple(0, -1.0, 2)));

    // t�� ���������� ���� ������ �ð� ���� �˻縦 �� �� �ִ�. 
    // ��� �ϴ� ���� �ñ��Ѱ�?
    // 4 ��, '������ �ð� ����' ����
}

void foo3() {
    boost::tuple<int, float, double, int> quad(10, 1.0f, 10.0, 1);
    int i;
    float f;
    double d;
    int i2;

    // 'quad' �������� 'i', 'f', 'd', 'i2'�� �� ����
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
