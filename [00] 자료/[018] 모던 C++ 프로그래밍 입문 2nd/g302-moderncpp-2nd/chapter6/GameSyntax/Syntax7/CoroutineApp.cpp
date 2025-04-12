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
	// �ٸ� �����忡 ���ŷ�� �����ϴ� �۾� ȣ��
	std::cout << "foo: the first part" << std::endl;
	co_await std::suspend_always{};
	// ���ŷ �۾��� ��� ó��
	std::cout << "foo: the second part" << std::endl;
}

int main()
{
	ReturnObject obj = foo();
	std::cout << "main: the first part" << std::endl;
	obj.co_handler.resume();
	// ���ŷ�� �ð� ���� �ٸ� �۾� ����
	std::cout << "main: the second part" << std::endl;
	obj.co_handler.resume();

	return 0;
}