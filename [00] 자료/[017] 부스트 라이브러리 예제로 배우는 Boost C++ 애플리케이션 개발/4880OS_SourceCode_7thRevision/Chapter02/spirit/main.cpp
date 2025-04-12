#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <assert.h>
#include <boost/spirit/include/qi.hpp>

struct date {
    unsigned short year;
    unsigned short month;
    unsigned short day;
};

// 파라미터 's'의 데이터형으로 std::string보다 나은 걸 쓰고 싶다면
// '문자열 데이터형에 대한 참조자 사용하기' 레시피를 참고하자
date parse_date_time1(const std::string& s) {
    using boost::spirit::qi::_1;
    using boost::spirit::qi::ushort_;
    using boost::spirit::qi::char_;
    using boost::phoenix::ref;

    date res;
    const char* first = s.data();
    const char* const end = first + s.size();
    bool success = boost::spirit::qi::parse(first, end,
        ushort_[ ref(res.year) = _1 ]  >> char_('-') >> ushort_[ ref(res.month) = _1 ] >> char_('-') >> ushort_[ ref(res.day) = _1 ]
    );

    if (!success || first != end) {
        throw std::logic_error("Parsing failed");
    }

    return res;
}

date parse_date_time2(const std::string& s) {
    using boost::spirit::qi::_1;
    using boost::spirit::qi::uint_parser;
    using boost::spirit::qi::char_;
    using boost::phoenix::ref;

    // unsigned short를 출력형으로 사용하며, Radix 10과 2에서부터 2개의 숫자가 필요하다 
    uint_parser<unsigned short, 10, 2, 2> u2_;

    // unsigned short를 출력형으로 사용하며, Radix 10과 4에서부터 4개의 숫자가 필요하다
    uint_parser<unsigned short, 10, 4, 4> u4_;

    date res;
    const char* first = s.data();
    const char* const end = first + s.size();
    bool success = boost::spirit::qi::parse(first, end,
        u4_ [ ref(res.year) = _1 ]  >> char_('-') >> u2_ [ ref(res.month) = _1 ] >> char_('-') >> u2_ [ ref(res.day) = _1 ]
    );

    if (!success || first != end) {
        throw std::logic_error("Parsing failed");
    }

    return res;
}


int main() {
    date d = parse_date_time1("2012-12-31");
    assert(d.year == 2012);
    assert(d.month == 12);
    assert(d.day == 31);

    parse_date_time2("2012-12-31");
    assert(d.year == 2012);
    assert(d.month == 12);
    assert(d.day == 31);

    try {
        parse_date_time2("12345-12-31");
        assert(false);
    }catch (const std::logic_error&) {}
}

// ushort_[ [&res](unsigned short s) {res.year = s;} ]  >> char_('-') >> ushort_[ ref(res.month) = _1 ] >> char_('-') >> ushort_[ ref(res.day) = _1 ]
