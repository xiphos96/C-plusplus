// 'extern template'�� �ִ� ���
#include "header.hpp"

#ifndef BOOST_NO_CXX11_EXTERN_TEMPLATE
template class boost::variant<
    boost::blank,
    int,
    std::string,
    double
>;
#endif


#include <boost/variant.hpp>
#include <boost/blank.hpp>
#include <string>
