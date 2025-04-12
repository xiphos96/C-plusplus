#include <boost/any.hpp>
#include <vector>
#include <string>
#include <typeinfo>
#include <algorithm>
#include <iostream>

// �� typedef�� �޼ҵ���� ����� ���� ���̸�,
// ���� SQL �������̽��� �ѷ��Ѵ�

typedef boost::any cell_t;
typedef std::vector<cell_t> db_row_t;

// �̰� �׳� ������ �� ������ �����ͺ��̽��� �ٷ��� �ʴ´�
db_row_t get_row(const char* /*query*/) {
    // ���� ���ø����̼��̶��, 'query' �Ķ���ʹ� 'const char*'�̳� 
	// 'const std::string&'���̾�� �ұ�?
	// �ش��� '���ڿ� ���������� ���� ������ ����ϱ�' �����Ǹ� ����
    db_row_t row;
    row.push_back(10);
    row.push_back(10.1f);
    row.push_back(std::string("hello again"));
    return row;
}


// ����ڰ� Ŭ������ ����ϴ� ���
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
