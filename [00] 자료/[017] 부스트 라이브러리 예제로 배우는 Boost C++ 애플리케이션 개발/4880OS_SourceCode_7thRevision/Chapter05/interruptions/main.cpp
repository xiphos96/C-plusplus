bool stop_parsing = true;
bool not_end_of_parsing = true;

#include <boost/thread.hpp>

void do_parse();

int main() {
    boost::thread parser_thread(&do_parse);

    // 여기에 코드 몇 줄이 온다
    // ...

    if (stop_parsing) {
        // 더이상 파싱할 필요 없음
        // 할 일: 파서 중단
    }

    if (stop_parsing) {
        // 더이상 파싱할 필요 없음
        parser_thread.interrupt();
    }

	parser_thread.join();
}

void do_parse() {
    while (not_end_of_parsing) {
        boost::this_thread::interruption_point();
        // 파싱에 필요한 코드

    }

    // 새 스레드는 이쪽으로 온다 
    assert(false);
}

