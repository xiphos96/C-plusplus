// char* vector_advance(char* val);

// char ( &vector_advance( char (&val)[4] ) )[4];


#include <boost/array.hpp>
#include <algorithm>

// 값을 1 증가시키는 함수 객체
struct add_1 : public std::unary_function<char, void> {
    void operator()(char& c) const {
        ++ c;
    }

    // 함수 객체를 만들 기분은 아니지만 
    // 'boost::bind(std::plus<char>(), _1, 1)'이 뭘 하는 건지 모른다면
	// '함수 파라미터에 값 묶기' 레시피를 읽어보자
};

typedef boost::array<char, 4> array4_t;
array4_t& vector_advance(array4_t& val) {
    // boost::array에는 begin(), cbegin(), end(), cend(), rbegin(),
    // size(), empty()와 다른 STL 컨테이너이 지원하는 공통 함수를 제공한다	
    std::for_each(val.begin(), val.end(), add_1());
    return val;
}

int main() {
    // boost::array는 C++11의 다른 배열처럼 초기화할 수 있다
    // array4_t val = {0, 1, 2, 3};
    // 하지만 C++03에서는 {}를 한번 더 붙여줘야 한다
    array4_t val = {{0, 1, 2, 3}};

    // boost::array는 일반 배열처럼 동작한다
    array4_t val_res;               // 만약 값의 데이터형이 기본 생성과 할당을 지원한다면 
    val_res = vector_advance(val);  // 기본 생성 및 기본 할당될 수 있다    

    assert(val.size() == 4);
    assert(val[0] == 1);
    /*val[4];*/ // 인덱스의 최대값이 3이므로 가정에 어긋난다 

    // 컴파일 시간에 가정 검사를 해보자.
    // 어떻게 하는 건지 궁금하다면
	// '컴파일할 때 크기 검사하기' 레시피를 읽어보자
    assert(sizeof(val) == sizeof(char) * array4_t::static_size);
    return 0;
}
