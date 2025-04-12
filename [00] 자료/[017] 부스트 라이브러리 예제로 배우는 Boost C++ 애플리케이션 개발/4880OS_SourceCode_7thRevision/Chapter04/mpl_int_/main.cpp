#include <boost/static_assert.hpp>
#include <boost/type_traits/is_pod.hpp>

//// 일반 구현
//template <class T>
//T process(const T& val) {
//    BOOST_STATIC_ASSERT((boost::is_pod<T>::value));
//    // ...
//    (void)val;
//}

#include <boost/mpl/int.hpp>

namespace detail {
    // 일반 구현
    template <class T, class Tag>
    T process_impl(const T& val, Tag /*무시*/) {
        // ...
        BOOST_STATIC_ASSERT(sizeof(val) != 1
                && sizeof(val) != 4
                && sizeof(val) != 8
        );
        return val;
    }

    // 1 바이트 최적화 구현
    template <class T>
    T process_impl(const T& val, boost::mpl::int_<1> /*무시*/) {
        // ...
        BOOST_STATIC_ASSERT(sizeof(val) == 1);
        return val;
    }


    // 4 바이트 최적화 구현
    template <class T>
    T process_impl(const T& val, boost::mpl::int_<4> /*무시*/) {
        // ...
        BOOST_STATIC_ASSERT(sizeof(val) == 4);
        return val;
    }

    // 8 바이트 최적화 구현
    template <class T>
    T process_impl(const T& val, boost::mpl::int_<8> /*무시*/) {
        // ...
        BOOST_STATIC_ASSERT(sizeof(val) == 8);
        return val;
    }
} // 네임스페이스 detail


// 함수 호출을 분배하기만 한다
template <class T>
T process(const T& val) {
    BOOST_STATIC_ASSERT((boost::is_pod<T>::value));
    return detail::process_impl(val, boost::mpl::int_<sizeof(T)>());
}

template <int Value>
struct int_ {
    static const int value = Value;
    typedef int_<Value> type;
    typedef int value_type;
};

int main() {
    process(1);
    process(double());
    process(float());
    process(char());
    process(unsigned());
    process(short());
}
