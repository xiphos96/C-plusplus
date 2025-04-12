#include <boost/variant.hpp>
#include <vector>
#include <string>
#include <iostream>

// �� typedef�� �޼ҵ���� ����� ���� ���̸�,
// ���� SQL �������̽��� �ѷ��Ѵ�

typedef boost::variant<int, float, std::string> cell_t;
typedef std::vector<cell_t> db_row_t;

// �̰� �׳� ������ �� ������ �����ͺ��̽��� �ٷ��� �ʴ´�
db_row_t get_row(const char* /*query*/) {
	// 'query' �Ķ���Ϳ� ������ ���������� ���� �ʹٸ�
	// �ش��� '���ڿ� ���������� ���� ������ ����ϱ�' �����Ǹ� ����
    db_row_t row;
    row.push_back(10);
    row.push_back(10.1f);
    row.push_back("hello again");
    return row;
}


// �������� ���ϱ� ���� �ڵ� 
// �湮�ڰ� �ƹ� �͵� ��ȯ���� �ʴ´ٸ�
// boost::static_visitor<>�� ���ø� �Ķ���͸� ������ �� ���� 
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
