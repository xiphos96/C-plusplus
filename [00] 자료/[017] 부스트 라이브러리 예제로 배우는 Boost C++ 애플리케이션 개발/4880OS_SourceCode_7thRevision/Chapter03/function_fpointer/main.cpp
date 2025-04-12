#include <boost/function.hpp>
typedef boost::function<void(int)> fobject_t;

// 이제 이 함수에서 함수 객체를 받을 수 있다
void process_integers(const fobject_t& f);


void my_ints_function(int i);

int main() {
   process_integers(&my_ints_function);
}

void my_ints_function(int /*i*/) {}
void process_integers(const fobject_t& /*f*/) {}
