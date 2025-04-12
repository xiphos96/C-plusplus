#include <boost/static_assert.hpp>
#include <boost/type_traits/is_same.hpp>

//template <class T>
//T process_data(const T& v1, const T& v2, const T& v3);

template <class T>
T process_data_plus_assign(const T& v1, const T& v2, const T& v3){
    BOOST_STATIC_ASSERT((boost::is_same<int, T>::value));
    (void)v2;
    (void)v3;
    return v1;
}

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/has_plus_assign.hpp>

// process_data의 수정된 일반 버전
template <class T>
typename boost::disable_if_c<boost::has_plus_assign<T>::value,T>::type
    process_data(const T& v1, const T& v2, const T& v3)
{
    BOOST_STATIC_ASSERT((boost::is_same<const char*, T>::value));
    (void)v2;
    (void)v3;
    return v1;
}

// 이 process_data는 process_data_plus_assign를 호출한다
template <class T>
typename boost::enable_if_c<boost::has_plus_assign<T>::value, T>::type
    process_data(const T& v1, const T& v2, const T& v3)
{
    return process_data_plus_assign(v1, v2, v3);
}

// 첫번째 버전
template <class T>
typename boost::disable_if<boost::has_plus_assign<T>, T>::type
process_data2(const T& v1, const T& v2, const T& v3);

// process_data_plus_assign
template <class T>
typename boost::enable_if<boost::has_plus_assign<T>, T>::type
process_data2(const T& v1, const T& v2, const T& v3);


int main() {
    int i = 1;
    // 최적화된 버전
    process_data(i, i, i);

    // 기본 버전
    // 템플릿 파라미터를 명시적으로 지정
    process_data<const char*>("Testing", "example", "function");
}
