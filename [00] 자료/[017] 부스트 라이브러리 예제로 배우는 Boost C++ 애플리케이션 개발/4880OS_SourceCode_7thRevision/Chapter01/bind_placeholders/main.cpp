#include <boost/bind.hpp>
#include <vector>
#include <algorithm>
#include <functional>

class Number{};
inline Number operator + (Number, Number) {
    return Number();
}

// 원하는 코드는 여기서부터 시작
struct mul_2_func_obj: public std::unary_function<Number, Number> {
    Number operator()(Number n1) const {
        return n1 + n1;
    }
};

void mul_2_impl1(std::vector<Number>& values) {
    std::for_each(values.begin(), values.end(), mul_2_func_obj());
}

void mul_2_impl2(std::vector<Number>& values) {
    std::for_each(values.begin(), values.end(), boost::bind(std::plus<Number>(), _1, _1));
}

template <class T>
void mul_2_impl3(std::vector<T>& values) {
    std::for_each(values.begin(), values.end(), boost::bind(std::plus<T>(), _1, _1));
}

class Device1 {
private:
    short temperature();
    short wetness();
    int illumination();
    int atmospheric_pressure();

    void wait_for_data();

public:
    template <class FuncT>
    void watch(const FuncT& f) {
        for(;;) {
            wait_for_data();
            f(
                temperature(),
                wetness(),
                illumination(),
                atmospheric_pressure()
            );
        }
    }
};

class Device2 {
private:
    short temperature();
    short wetness();
    int illumination();
    int atmospheric_pressure();

    void wait_for_data();

public:
    template <class FuncT>
    void watch(const FuncT& f) {
        for(;;) {
            wait_for_data();
            f(
                wetness(),
                temperature(),
                atmospheric_pressure(),
                illumination()
            );
        }
    }
};

void detect_storm(int wetness, int temperature, int atmospheric_pressure);


// 테스트용 코드 
#include <assert.h>

struct storm_exception : std::exception{};

void detect_storm(int wetness, int temperature, int atmospheric_pressure) {
    if (wetness == 2 && temperature == 1 && atmospheric_pressure == 4)
        throw storm_exception();
}

short Device1::temperature() { return 1; }
short Device1::wetness() { return 2; }
int Device1::illumination() { return 3; }
int Device1::atmospheric_pressure()  { return 4; }
void Device1::wait_for_data() {
    static int counter = 0;
    if (counter) {
        assert(false);
    }

    ++ counter;
}

short Device2::temperature() { return 1; }
short Device2::wetness() { return 2; }
int Device2::illumination() { return 3; }
int Device2::atmospheric_pressure()  { return 4; }
void Device2::wait_for_data() {
    static int counter = 0;
    if (counter) {
        assert(false);
    }

    ++ counter;
}

#include <string>


template <class FuncT>
void watch(const FuncT& f) {
    f(10, std::string("String"));
    f(10, "Char array");
    f(10, 10);
}


struct templated_foo {
    template <class T>
    void operator()(T, int) const {
        // 구현 없음 
        // 그냥 bound 함수를 템플릿화한 대로 쓸 수 있다는 걸 보여주려는 용도 
    }
};

void check_templated_bind() {
    // bind 에서 함수 객체의 반환형을 명시해주지 못한다면
    // 직접 할 수도 있다
    watch(boost::bind<void>(templated_foo(), _2, _1));
}


int main () {
    // 10개의 숫자를 갖는 벡터
    std::vector<Number> vec(10);
    mul_2_impl1(vec);
    mul_2_impl2(vec);
    mul_2_impl3(vec);

    try {

        try {
            Device1 d1;
            // 여기서 얻은 함수 객체는 함수 호출 시 전달된 추가 파라미터를 그냥 무시한다
            d1.watch(boost::bind(&detect_storm, _2, _1, _4));
        } catch (const storm_exception&) {}


        try {
            Device2 d2;
            d2.watch(boost::bind(&detect_storm, _1, _2, _3));
        } catch (const storm_exception&) {}

    } catch (...) {
        assert(false);
    }


    check_templated_bind();
    return 0;
}
