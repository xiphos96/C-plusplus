#include <cstring>
#include <boost/array.hpp>

template <class T, std::size_t BufSizeV>
void serialize_bad(const T& value, boost::array<unsigned char, BufSizeV>& buffer) {
    assert(BufSizeV >= sizeof(value));
    // 할 일: 고쳐야함
    std::memcpy(&buffer[0], &value, sizeof(value));
}

#include <boost/static_assert.hpp>
#include <boost/type_traits/is_pod.hpp>

template <class T, std::size_t BufSizeV>
void serialize(const T& value, boost::array<unsigned char, BufSizeV>& buffer) {
    BOOST_STATIC_ASSERT(BufSizeV >= sizeof(value));
    BOOST_STATIC_ASSERT(boost::is_pod<T>::value);

    std::memcpy(&buffer[0], &value, sizeof(value));
}

BOOST_STATIC_ASSERT(3 >= 1);

struct some_struct { enum enum_t { value = 1}; };
BOOST_STATIC_ASSERT(some_struct::value);

template <class T1, class T2>
struct some_templated_struct {
    enum enum_t { value = (sizeof(T1) == sizeof(T2))};
};
BOOST_STATIC_ASSERT((some_templated_struct<int, unsigned int>::value));


#include <iostream>
#include <boost/type_traits/is_unsigned.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/remove_const.hpp>

template <class T1, class T2>
void type_traits_examples(T1& /*v1*/, T2& /*v2*/) {
    // T1이 부호없는 숫자라면 참 반환
    std::cout << boost::is_unsigned<T1>::value;

    // T1이 T2와 완전히 같은 데이터형을 갖는다면 참 반환
    std::cout << boost::is_same<T1, T2>::value;

    // 아래 코드로 t1의 const 수정자를 제거
    // T1 데이터형에 일어날 일:
    // const int => int
    // int => int
    // int const volatile => int volatile
    // const int& => const int&
    typedef typename boost::remove_const<T1>::type t1_nonconst_t;
}

template <class T, std::size_t BufSizeV>
void serialize2(const T& value, boost::array<unsigned char, BufSizeV>& buf) {
    BOOST_STATIC_ASSERT_MSG(boost::is_pod<T>::value,
        "This serialize2 function may be used only "
        "with POD types."
    );

    BOOST_STATIC_ASSERT_MSG(BufSizeV >= sizeof(value),
        "Can not fit value to buffer. "
        "Make buffer bigger."
    );

    std::memcpy(&buf[0], &value, sizeof(value));
}

int main() {
    const int i = 1;
    type_traits_examples(i, i);

    // 코드 어딘가
    boost::array<unsigned char, 1> buf;
    //serialize2(std::string("Hello word"), buf);

    (void)buf;
}
