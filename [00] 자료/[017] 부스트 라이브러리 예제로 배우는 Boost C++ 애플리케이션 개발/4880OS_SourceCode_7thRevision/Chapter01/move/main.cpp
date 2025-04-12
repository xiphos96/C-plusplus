#include <string>
#include <vector>
//#include <auto_ptr>
#include <memory>
#include <assert.h>
#include <iostream>

#include <boost/swap.hpp>
#include <boost/move/move.hpp>

using namespace std;


namespace other {
    // 기본 생성자가 싸고 빠르다 
    class characteristics{};
} // 네임스페이스 other

struct person_info {
    // 필드를 여기에 선언한다
    // ...
    bool is_male_;
    std::string name_;
    std::string second_name_;
    other::characteristics characteristic_;

private:
    BOOST_COPYABLE_AND_MOVABLE(person_info)

public:
    // 예제를 간단히 하기 위해
	// person_info의 기본 생성자와 swap은 매우 싸고 빠르다고 가정
    person_info() {}

    person_info(const person_info& p)
        : is_male_(p.is_male_)
        , name_(p.name_)
        , second_name_(p.second_name_)
        , characteristic_(p.characteristic_)
    {}

    person_info(BOOST_RV_REF(person_info) person) {
        swap(person);
    }

    person_info& operator=(BOOST_COPY_ASSIGN_REF(person_info) person) {
        if (this != &person) {
             person_info tmp(person);
             swap(tmp);
         }

        return *this;
    }

    person_info& operator=(BOOST_RV_REF(person_info) person) {
        if (this != &person) {
             swap(person);
             person_info tmp;
             tmp.swap(person);
         }

        return *this;
    }


    void swap(person_info& rhs) {
        std::swap(is_male_, rhs.is_male_);
        name_.swap(rhs.name_);
        second_name_.swap(rhs.second_name_);
        boost::swap(characteristic_, rhs.characteristic_);
    }
};



int main() {

    person_info vasya;
    vasya.name_ = "Vasya";
    vasya.second_name_ = "Snow";
    vasya.is_male_ = true;

    person_info new_vasya(boost::move(vasya));
    assert(new_vasya.name_ == "Vasya");
    assert(new_vasya.second_name_ == "Snow");
    assert(vasya.name_.empty());
    assert(vasya.second_name_.empty());

    vasya = boost::move(new_vasya);
    assert(vasya.name_ == "Vasya");
    assert(vasya.second_name_ == "Snow");
    assert(new_vasya.name_.empty());
    assert(new_vasya.second_name_.empty());

    new_vasya = vasya;
    assert(vasya.name_ == "Vasya");
    assert(vasya.second_name_ == "Snow");
    assert(new_vasya.name_ == "Vasya");
    assert(new_vasya.second_name_ == "Snow");

	return 0;
}
