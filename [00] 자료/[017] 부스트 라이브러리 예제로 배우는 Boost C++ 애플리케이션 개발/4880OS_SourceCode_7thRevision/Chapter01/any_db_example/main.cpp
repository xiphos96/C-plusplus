#include <boost/any.hpp>
#include <vector>
#include <string>
#include <typeinfo>
#include <algorithm>
#include <iostream>

// 이 typedef과 메소드들은 헤더에 있을 것이며,
// 원래 SQL 인터페이스를 둘러싼다

typedef boost::any cell_t;
typedef std::vector<cell_t> db_row_t;

// 이건 그냥 예제일 뿐 실제로 데이터베이스를 다루진 않는다
db_row_t get_row(const char* /*query*/) {
    // 실제 애플리케이션이라면, 'query' 파라미터는 'const char*'이나 
	// 'const std::string&'형이어야 할까?
	// 해답은 '문자열 데이터형에 대한 참조자 사용하기' 레시피를 참고
    db_row_t row;
    row.push_back(10);
    row.push_back(10.1f);
    row.push_back(std::string("hello again"));
    return row;
}


// 사용자가 클래스를 사용하는 방법
struct db_sum: public std::unary_function<boost::any, void> {
private:
    double& sum_;

public:
    explicit db_sum(double& sum)
        : sum_(sum)
    {}

    void operator()(const cell_t& value) {
        const std::type_info& ti = value.type();

        if (ti == typeid(int)) {
            sum_ += boost::any_cast<int>(value);
        } else if (ti == typeid(float)) {
            sum_ += boost::any_cast<float>(value);
        }
    }
};


int main()
{
    db_row_t row = get_row("Query: Give me some row, please.");

    double res = 0.0;
    std::for_each(row.begin(), row.end(), db_sum(res));

    std::cout << "Sum of arithmetic types in database row is: " << res << std::endl;

    return 0;
}
