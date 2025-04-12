void some_function(unsigned short param);
int foo();

void foo1() {
    // �ڵ� ���

    // � �����Ϸ������� int�� unsigned short�� ��ȯ�Ǹ�, 
    // �����͸� ���� �� �ִٰ� ����� ���� �𸥴�
    some_function(foo());
}

void foo2() {
    // �ڵ� ���

    // ��� �����Ǿ�, �ùٸ��� �����ϴ� ��ó�� ���δ�
    some_function(
        static_cast<unsigned short>(foo())
    );
}


#include <boost/numeric/conversion/cast.hpp>
void correct_implementation() {
    // 100% ��Ȯ
    some_function(
        boost::numeric_cast<unsigned short>(foo())
    );
}

#include <iostream>

void test_function() {
    for (unsigned int i = 0; i < 100; ++i) {
        try {
            correct_implementation();
        } catch (const boost::numeric::bad_numeric_cast& e) {
            std::cout << '#' << i << ' ' << e.what() << std::endl;
        }
    }
}

void test_function1() {
    for (unsigned int i = 0; i < 100; ++i) {
        try {
            correct_implementation();
        } catch (const boost::numeric::positive_overflow& e) {
            // ���� �����÷ο�(overflow)�� ��ó�ϱ�
            std::cout << "POS OVERFLOW in #" << i << ' ' << e.what() << std::endl;
        } catch (const boost::numeric::negative_overflow& e) {
            // ���� �����÷ο쿡 ��ó�ϱ�
            std::cout <<"NEG OVERFLOW in #" << i << ' ' << e.what() << std::endl;
        }
    }
}

#include <stdexcept>

template <class SourceT, class TargetT>
struct mythrow_overflow_handler {
    void operator() (boost::numeric::range_check_result r) {
        if (r != boost::numeric::cInRange) {
            throw std::logic_error("Not in range!");
        }
    }
};

template <class TargetT, class SourceT>
TargetT my_numeric_cast(const SourceT& in) {
    using namespace boost;
    typedef numeric::conversion_traits<TargetT, SourceT>   conv_traits;
    typedef numeric::numeric_cast_traits<TargetT, SourceT> cast_traits;
    typedef boost::numeric::converter
        <
            TargetT,
            SourceT,
            conv_traits,
            mythrow_overflow_handler<SourceT, TargetT> // !!!
        > converter;
    return converter::convert(in);
}


int main() {
    foo1();
    foo2();

    test_function();
    std::cout << "\n\n\n";
    test_function1();

    std::cout << "\n\n\n";
    // �ڵ� ���
    try {
        my_numeric_cast<short>(100000);
    } catch (const std::logic_error& e) {
        std::cout << "It works! " << e.what() << std::endl;
    }
}

void some_function(unsigned short param) {
    (void)param;
}

bool some_extremely_rare_condition() {
    static int i = 0;
    ++ i;

    if (i == 50 || i == 150) {
        return true;
    }

    return false;
}

bool another_extremely_rare_condition() {
    static int i = 0;
    ++ i;

    if (i == 60 || i == 160) {
        return true;
    }

    return false;

}

// ������ �߻��ϸ� -1 ��ȯ
int foo() {
    if (some_extremely_rare_condition()) {
        return -1;
    } else if (another_extremely_rare_condition()) {
        return 1000000;
    }

    return 65535;
}

