#include <boost/regex.hpp>
#include <iostream>

int main() {
    std::cout 
        << "Available regex syntaxes:\n"
        << "\t[0] Perl\n"
        << "\t[1] Perl case insensitive\n"
        << "\t[2] POSIX extended\n"
        << "\t[3] POSIX extended case insensitive\n"
        << "\t[4] POSIX basic\n"
        << "\t[5] POSIX basic case insensitive\n"
        << "Choose regex syntax: ";

    boost::regex::flag_type flag;
    switch (std::cin.get()) {
    case '0': flag = boost::regex::perl;
        break;

    case '1': flag = boost::regex::perl|boost::regex::icase;
        break;
        
    case '2': flag = boost::regex::extended;
        break;

    case '3': flag = boost::regex::extended|boost::regex::icase;
        break;

    case '4': flag = boost::regex::basic;
        break;
        
    case '5': flag = boost::regex::basic|boost::regex::icase;
        break;
    default:
        std::cout << "Inccorect number of regex syntax. Exiting... \n";
        return -1;
    } 
    // 예외 비활성화
    flag |= boost::regex::no_except;
    
    // std::cin 복원
    std::cin.ignore();
    std::cin.clear();
    
    std::string regex, str;
    do {
        std::cout << "Input regex: ";
        if (!std::getline(std::cin, regex) || regex.empty()) {
            return 0;
        }
        
        // `boost::regex::no_except` 플래그가 없으면
        // 이 생성자는 예외를 던질 수도 있다
        const boost::regex e(regex, flag);
        if (e.status()) {
            std::cout << "Incorrect regex pattern!\n";
            continue;
        }
        
        std::cout << "String to match: ";
        while (std::getline(std::cin, str) && !str.empty()) {
            bool matched = boost::regex_match(str, e);
            std::cout << (matched ? "MATCH\n" : "DOES NOT MATCH\n");
            std::cout << "String to match: ";
        } // `while (std::getline(std::cin, str))`의 끝
                
        std::cout << '\n';
        
        // std::cin 복원
        std::cin.ignore();
        std::cin.clear();
    } while (1);
} // int main()
