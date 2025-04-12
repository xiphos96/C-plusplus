#include <iostream>
#include <coroutine>

class ReturnObject
{
public:
	struct promise_type
	{
		ReturnObject get_return_object() noexcept
		{
			return ReturnObject{
				std::coroutine_handle<promise_type>::from_promise(*this) };
		}
		auto initial_suspend() noexcept { return std::suspend_always{}; }
		auto final_suspend() noexcept { return std::suspend_always{}; }
		void return_void() { return; }
		void unhandled_exception() { return std::exit(1); }
	};

	ReturnObject(std::coroutine_handle<promise_type> handler) :
												co_handler(handler) {}
	~ReturnObject() { if((bool)co_handler) co_handler.destroy(); }

	std::coroutine_handle<promise_type> co_handler;
};

ReturnObject foo()
{
	// 다른 스레드에 블록킹을 유발하는 작업 호출
	std::cout << "foo: the first part" << std::endl;
	co_await std::suspend_always{};
	// 블록킹 작업의 결과 처리
	std::cout << "foo: the second part" << std::endl;
}

int main()
{
	ReturnObject obj = foo();
	std::cout << "main: the first part" << std::endl;
	obj.co_handler.resume();
	// 블록킹된 시간 동안 다른 작업 진행
	std::cout << "main: the second part" << std::endl;
	obj.co_handler.resume();

	return 0;
}