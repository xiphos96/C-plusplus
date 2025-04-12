#include <assert.h>
#include <boost/lexical_cast.hpp>

void foo1() {
    std::string s = boost::lexical_cast<std::string>(100);
    assert(s == "100");
}

#include <sstream>
void foo2() {
    // C++에서 문자열로 변환하는 방법
    std::stringstream ss;
    ss << 100;
    std::string s;
    ss >> s;
    // 뭘 어떻게 하든 이 영역이 끝날 때까지 변수인 'ss'가 계속해서 남는다. 
    // 변환하는 동안 가상 함수가 여러 번 호출된다
    assert(s == "100");
}

#include <cstdlib>
void foo3() {
    // C에서 문자열로 변환하는 방법
    char buffer[100];
    std::sprintf(buffer, "%i", 100);
    // 이 세상에 존재하는 'printf' 종류의 함수에서 얼마나 오류가 많이 나는지 세어 보려면
    // unsigned long long int 정도는 써야 할 것이다
    // 게다가 'printf' 함수는 항상 보안 문제가 있다!
    // 그래도 잠시만 기다려보자. std::string를 만들어야 하니까.
    std::string s(buffer);
    // 이제 쓰이지 않을 버퍼 변수를 갖게 됐다
    assert(s == "100");
}

#include <boost/noncopyable.hpp>
#include <boost/tuple/tuple.hpp>
#include <algorithm>

namespace vendor1 {

class control_console: private boost::noncopyable {
public:
    enum command_t {
        MOVE = 0,// 이동 조작자(manipulator) ---___----
        TURN_CLOCKWISE = 1, // 시계방향으로 회전 조작자
        TURN_COUNTER_CLOCKWISE = 2 // 반 시계방향으로 회전 조작자
    };

typedef boost::tuple<command_t, unsigned short, unsigned short> data_t;

private:
    control_console(); // 생성할 수 없는 클래스
    static bool get_data(data_t& out);

public:

    template <class FuncT>
    static void handle_data(FuncT f) {
        data_t data;
        while (get_data(data)) {
            f(data);
        }
    }
};

bool control_console::get_data(control_console::data_t& out) {
    static int i = 0;

    if (i == 0) {
        out = boost::make_tuple(control_console::MOVE, static_cast<unsigned short>(100), static_cast<unsigned short>(100));
    } else if (i == 1) {
        out = boost::make_tuple(control_console::TURN_CLOCKWISE, static_cast<unsigned short>(10), static_cast<unsigned short>(0));
    } else if (i == 2) {
        out = boost::make_tuple(control_console::TURN_COUNTER_CLOCKWISE, static_cast<unsigned short>(190), static_cast<unsigned short>(0));
    } else {
        return false;
    }

    ++ i;
    return true;
}

}

namespace vendor2 {

namespace robot {
    // 명령어:
    // "clws" - 시계방향으로 회전 조작자
    // "move" - 이동 조작자
    // "cclo" - 반 시계방향으로 회전 조작자

    typedef boost::array<char, 512> command_t;
    void accept_command(const command_t& comnd) {
        // do something

        static int i = 0;
        if (i == 0) {
            assert(!std::strcmp(&comnd[0], "move 100 100"));
        } else if (i == 1) {
            assert(!std::strcmp(&comnd[0], "clws 10"));
        } else if (i == 2) {
            assert(!std::strcmp(&comnd[0], "cclo 190"));
        }

        ++ i;
    }
}

}

namespace your_project {
    typedef vendor1::control_console::data_t data_t;

    namespace detail {
        static const std::size_t buffer_size
            = 5 /* unsigned short로 표현할 수 있는 값은 최대 65535 이다*/
            + 1; /* '\0' 기호를 넣을 자리*/

        // boost::lexical_cast의 출력 파라미터형으로 boost::array이나 std::array를 전달하면
        // lexical_cast는 std::string를 생성하지 않는다
        // 그러면 문자열 생성자를 써서 힙 할당하는 일도 없다
        typedef boost::array<char, buffer_size> num_data_buffer_t;

        void move_impl(vendor2::robot::command_t& command, unsigned short x, unsigned short y) {
            char* it = &command[0];
            const boost::array<char, 6> move_word = {{"move "}};
            // '\0' 문자를 쓰고 싶지 않으니 '-1'가 있어야 한다
            it = std::copy(move_word.begin(), move_word.end() - 1, it);

            // X 좌표
            const num_data_buffer_t converted_x_value
                    = boost::lexical_cast<num_data_buffer_t>(x);
            const std::size_t converted_x_len = std::strlen(converted_x_value.cbegin());
            it = std::copy(converted_x_value.cbegin(), converted_x_value.cbegin() + converted_x_len, it);

            // X와 Y 좌표 사이의 공백
            *it = ' ';
            ++it;

            // Y 좌표
            const num_data_buffer_t converted_y_value
                    = boost::lexical_cast<num_data_buffer_t>(y);
            std::copy(converted_y_value.cbegin(), converted_y_value.cend(), it);
        }

        void clockwise_impl(vendor2::robot::command_t& command, unsigned short degree) {
            char* it = &command[0];
            const boost::array<char, 6> clws_word = {{"clws "}};
            // '\0' 문자를 쓰고 싶지 않으니 '-1'가 있어야 한다
            it = std::copy(clws_word.begin(), clws_word.end() - 1, it);

            // 각도
            const num_data_buffer_t converted_degree_value
                    = boost::lexical_cast<num_data_buffer_t>(degree);
            std::copy(converted_degree_value.cbegin(), converted_degree_value.cend(), it);
        }

        void counter_clockwise_impl(vendor2::robot::command_t& command, unsigned short degree) {
            char* it = &command[0];
            const boost::array<char, 6> cclo_word = {{"cclo "}};
            // '\0' 문자를 쓰고 싶지 않으니 '-1'가 있어야 한다
            it = std::copy(cclo_word.begin(), cclo_word.end() - 1, it);

            // 각도
            const num_data_buffer_t converted_degree_value
                    = boost::lexical_cast<num_data_buffer_t>(degree);
            std::copy(converted_degree_value.cbegin(), converted_degree_value.cend(), it);
        }
    }


    void accept_and_send_data(const data_t& data) {
        typedef vendor1::control_console enum_vals_t;
        vendor2::robot::command_t command;

        switch (boost::get<0>(data)) {
        case enum_vals_t::MOVE:
            detail::move_impl(command, boost::get<1>(data), boost::get<2>(data));
            break;

        case enum_vals_t::TURN_CLOCKWISE:
            detail::clockwise_impl(command, boost::get<1>(data));
            break;

        case enum_vals_t::TURN_COUNTER_CLOCKWISE:
            detail::counter_clockwise_impl(command, boost::get<1>(data));
            break;
        }

        vendor2::robot::accept_command(command);
    }
}


int main() {
    foo1();
    foo2();
    foo3();

    vendor1::control_console::handle_data(&your_project::accept_and_send_data);
}
