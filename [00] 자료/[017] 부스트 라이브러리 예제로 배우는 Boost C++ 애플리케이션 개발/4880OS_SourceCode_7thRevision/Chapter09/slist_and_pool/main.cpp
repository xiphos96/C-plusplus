#include <boost/pool/pool_alloc.hpp>
#include <boost/container/slist.hpp>
#include <cassert>

template <class ListT>
void test_lists();



typedef boost::fast_pool_allocator<int> allocator_t;
typedef boost::container::slist<int, allocator_t> slist_t;

void list_specific(slist_t& list, slist_t::iterator it) {
	typedef slist_t::iterator iterator;

	// 요소 776 삭제
	assert( *(++iterator(it)) == 776);
	assert(*it == 777);
	list.erase_after(it);
	assert(*it == 777);
	assert( *(++iterator(it)) == 775);

	// 메모리 풀어주기
	boost::singleton_pool<
		boost::pool_allocator_tag,
		sizeof(int)
	>::release_memory();
}

#include <list>
typedef std::list<int> stdlist_t;
void list_specific(stdlist_t& list, stdlist_t::iterator it) {
	typedef stdlist_t::iterator iterator;

	// 요소 776 삭제
	++it;
	assert( *it == 776);
	it = list.erase(it);
	assert(*it == 775);
}

void test_slist() {
	test_lists<slist_t>();
}

void test_list() {
	test_lists<std::list<int> >();
}

template <class ListT>
void test_lists() {
	typedef ListT list_t;

	// 1000000개의 0 삽입
	list_t  list(1000000, 0);

	for (int i = 0; i < 1000; ++i) {
		list.insert(list.begin(), i);
	}

	// 어떤 값 찾기
	typedef typename list_t::iterator iterator;
	iterator it = std::find(list.begin(), list.end(), 777);
	assert(it != list.end());

	// 몇몇 값 삭제
	for (int i = 0; i < 100; ++i) {
		list.pop_front();
	}

	// 반복자는 여전히 유효하며, 같은 값을 가리키고 있다
	assert(it != list.end());
	assert(*it == 777);

	// 값을 더 삽입
	for (int i = -100; i < 10; ++i) {
		list.insert(list.begin(), i);
	}

	// 반복자는 여전히 유효하며, 같은 값을 가리키고 있다
	assert(it != list.end());
	assert(*it == 777);

	list_specific(list, it);
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		test_slist();
		test_list();
		return 0;
	}

	switch(argv[1][0]) {
	case 's': std::cout << "slist_t:   "; test_slist(); break;
	case 'l': std::cout << "std::list: "; test_list();  break;
	default:
		std::cout << "Use 's' for testsing slist performance "
					 "and 'l' for testsing std::list performance.";
	}

	return 0;
}
