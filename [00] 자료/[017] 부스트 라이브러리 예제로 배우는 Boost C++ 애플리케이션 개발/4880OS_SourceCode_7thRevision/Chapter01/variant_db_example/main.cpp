#include <boost/variant.hpp>
#include <vector>
#include <string>
#include <iostream>

// 이 typedef과 메소드들은 헤더에 있을 것이며,
// 원래 SQL 인터페이스를 둘러싼다

typedef boost::variant<int, float, std::string> cell_t;
typedef std::vector<cell_t> db_row_t;

// 이건 그냥 예제일 뿐 실제로 데이터베이스를 다루진 않는다
db_row_t get_row(const char* /*query*/) {
	// 'query' 파라미터에 적합한 데이터형을 고르고 싶다면
	// 해답은 '문자열 데이터형에 대한 참조자 사용하기' 레시피를 참고
    db_row_t row;
    row.push_back(10);
    row.push_back(10.1f);
    row.push_back("hello again");
    return row;
}


// 변수들을 더하기 위한 코드 
// 방문자가 아무 것도 반환하지 않는다면
// boost::static_visitor<>에 템플릿 파라미터를 제공할 수 없다 
struct db_sum_visitor: public boost::static_visitor<double> {
    double operator()(int value) const {
        return value;
    }

    double operator()(float value) const {
        return value;
    }

    double operator()(const std::string& /*value*/) const {
        return 0.0;
    }
};


int main()
{
    db_row_t row = get_row("Query: Give me some row, please.");

    double res = 0.0;
    for (db_row_t::const_iterator it = row.begin(), end = row.end(); it != end; ++it) {
        res += boost::apply_visitor(db_sum_visitor(), *it);
    }

    std::cout << "Sum of arithmetic types in database row is: " << res << std::endl;

    return 0;
}
