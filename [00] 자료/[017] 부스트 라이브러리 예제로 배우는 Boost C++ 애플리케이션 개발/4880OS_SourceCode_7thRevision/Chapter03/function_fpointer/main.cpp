#include <boost/function.hpp>
typedef boost::function<void(int)> fobject_t;

// ���� �� �Լ����� �Լ� ��ü�� ���� �� �ִ�
void process_integers(const fobject_t& f);


void my_ints_function(int i);

int main() {
   process_integers(&my_ints_function);
}

void my_ints_function(int /*i*/) {}
void process_integers(const fobject_t& /*f*/) {}
