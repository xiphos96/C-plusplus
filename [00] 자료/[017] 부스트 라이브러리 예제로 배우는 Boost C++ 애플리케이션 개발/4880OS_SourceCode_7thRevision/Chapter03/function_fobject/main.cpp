// std::unary_function<> 템플릿에서 사용
#include <functional>
// int를 받아들이고 아무 것도 반환하지 않는 
// 함수 포인터에 대한 typedef 
typedef void (*func_t)(int);

// 함수에 대한 포인터를 받아 
// 자신이 가진 각 정수에 대해 그 함수를 호출하는 함수
// 함수 객체는 받지 못한다 :(
void process_integers(func_t f);

// 함수 객체
class int_processor: public std::unary_function<int, void> {
   const int min_;
   const int max_;
   bool& triggered_;

public:
    int_processor(int min, int max, bool& triggered)
        : min_(min)
        , max_(max)
        , triggered_(triggered)
    {}

    void operator()(int i) const {
        if (i < min_ || i > max_) {
            triggered_ = true;
        }
    }
};

#include <boost/function.hpp>
typedef boost::function<void(int)> fobject_t;

// 이제 이 함수에서도 함수 객체를 받을 수 있다
void process_integers(const fobject_t& f);

int main() {
    bool is_triggered = false;
    int_processor fo(0, 200, is_triggered);
    process_integers(fo);
    assert(is_triggered);
}

void foo(const fobject_t& f) {
    // boost::function는 bool로 변환할 수 있다
    if (f) {
        // 'f'에 값이 있다면
        // ...
    } else {
        // 'f'가 비엇다면
        // ...
    }
}

bool g_is_triggered = false;
void set_functional_object(fobject_t& f) {
    int_processor fo( 100, 200, g_is_triggered);
    f = fo;
    // 영역을 떠나면 'fo'는 소멸된다
    // 그러더라도 'f'를 영역 내/외에서 쓸 수 있다.
}

#include <vector>
#include <algorithm>
#include <boost/bind.hpp>
void foo1() {
    std::vector<int> v;
    std::for_each(v.begin(), v.end(), boost::bind(std::plus<int>(), 10, _1));

    fobject_t f(boost::bind(std::plus<int>(), 10, _1));
    std::for_each(v.begin(), v.end(), f);
}

void process_integers(const fobject_t& f) {
    static const int data[] = {1, 2, 3, 4, 5, 200};
    std::for_each(data, data + sizeof(data), f);
}
