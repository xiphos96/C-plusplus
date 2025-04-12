#include <boost/static_assert.hpp>
#include <boost/type_traits/is_pod.hpp>

//// �Ϲ� ����
//template <class T>
//T process(const T& val) {
//    BOOST_STATIC_ASSERT((boost::is_pod<T>::value));
//    // ...
//    (void)val;
//}

#include <boost/mpl/int.hpp>

namespace detail {
    // �Ϲ� ����
    template <class T, class Tag>
    T process_impl(const T& val, Tag /*����*/) {
        // ...
        BOOST_STATIC_ASSERT(sizeof(val) != 1
                && sizeof(val) != 4
                && sizeof(val) != 8
        );
        return val;
    }

    // 1 ����Ʈ ����ȭ ����
    template <class T>
    T process_impl(const T& val, boost::mpl::int_<1> /*����*/) {
        // ...
        BOOST_STATIC_ASSERT(sizeof(val) == 1);
        return val;
    }


    // 4 ����Ʈ ����ȭ ����
    template <class T>
    T process_impl(const T& val, boost::mpl::int_<4> /*����*/) {
        // ...
        BOOST_STATIC_ASSERT(sizeof(val) == 4);
        return val;
    }

    // 8 ����Ʈ ����ȭ ����
    template <class T>
    T process_impl(const T& val, boost::mpl::int_<8> /*����*/) {
        // ...
        BOOST_STATIC_ASSERT(sizeof(val) == 8);
        return val;
    }
} // ���ӽ����̽� detail


// �Լ� ȣ���� �й��ϱ⸸ �Ѵ�
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
