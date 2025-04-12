#include <boost/coroutine/coroutine.hpp>

typedef boost::coroutines::coroutine< 
    std::string&(std::size_t max_characters_to_process) 
> corout_t;

void coroutine_task(corout_t::caller_type& caller) {
    std::string result;
    // 원래 프로그램으로 되돌아가기
    caller(result);

    while (1) {
        std::size_t max_characters_to_process = caller.get();

        // 문자 처리
        // ...
        result.resize(result.size() + max_characters_to_process);

        // 결과를 반환
        // 원래 프로그램으로 되돌아감
        caller(result);
    } /*while*/
}


struct spinlock_t {
    bool try_lock() {
        static int i = 0;
        return i++ >= 100;
    }
};

struct port_t {
    bool block_ready() {
        static int i = 0;
        return i++ >= 10;
    }
};

void coroutine_task(corout_t::caller_type& caller);

int main() {
    corout_t coroutine(coroutine_task);

    // 몇 가지 작업
    // ...
    spinlock_t spinlock;
    port_t port;
    
    while (!spinlock.try_lock()) {
        // 스핀 잠금(spinlock)을 한번 더 잠그기 전에 
        // 유용한 일을 좀 해두자
        coroutine(10); // 짧은 지연 시간 두기
    }
    // 스핀 잠금 잠그기
    // ...
    assert(coroutine.get().size() == 10 * 100);
    coroutine.get().clear();

    while (!port.block_ready()) {
        // 다시 데이터를 가져오기 전에
        // 유용한 일을 좀 해두자
        coroutine(300);  // 좀 큰 지연 시간 두기
        std::string& s = coroutine.get();
        // ...
        (void)s;
    }

    assert(coroutine.get().size() == 10 * 300);
}
