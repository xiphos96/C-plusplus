
//// 일반 구현
//template <class T>
//class data_processor {
//    double process(const T& v1, const T& v2, const T& v3);
//};

//// 정수형 맞춤 버전
//template <class T>
//class data_processor {
//    typedef int fast_int_t;
//    double process(fast_int_t v1, fast_int_t v2, fast_int_t v3);
//};

//// 부동 소수점형에 대한 SSE 최적화 버전
//template <class T>
//class data_processor {
//    double process(double v1, double v2, double v3);
//};

#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_integral.hpp>
#include <boost/type_traits/is_float.hpp>

// 일반 구현
template <class T, class Enable = void>
class data_processor {
    // ...
public:
    double process(const T& /*v1*/, const T& /*v2*/, const T& /*v3*/) {
        BOOST_STATIC_ASSERT((boost::is_same<const char*, T>::value));
        return 0.0;
    }
};


// 정수형 맞춤 버전
template <class T>
class data_processor<T, typename boost::enable_if_c<boost::is_integral<T>::value >::type> {
    // ...
public:
    typedef int fast_int_t;
    double process(fast_int_t /*v1*/, fast_int_t /*v2*/, fast_int_t /*v3*/){
        BOOST_STATIC_ASSERT((boost::is_same<int, T>::value || boost::is_same<short, T>::value));
        return 0.0;
    }
};

// 부동 소수점형에 대한 SSE 최적화 버전
template <class T>
class data_processor<T, typename boost::enable_if_c<boost::is_float<T>::value >::type> {
    // ...
public:
    double process(double /*v1*/, double /*v2*/, double /*v3*/){
        BOOST_STATIC_ASSERT((boost::is_same<double, T>::value || boost::is_same<float, T>::value));
        return 0.0;
    }
};

template <class T>
double example_func(T v1, T v2, T v3) {
    data_processor<T> proc;
    return proc.process(v1, v2, v3);
}

int main () {
    // 정수형 맞춤 버전이 쓰인다
    example_func(1, 2, 3);
    short s = 0;
    example_func(s, s, s);

    // 실수형 맞춤 버전이 쓰인다
    example_func(1.0, 2.0, 3.0);
    example_func(1.0f, 2.0f, 3.0f);

    // 일반 버전이 쓰인다
    example_func("Hello", "word", "processing");
}
