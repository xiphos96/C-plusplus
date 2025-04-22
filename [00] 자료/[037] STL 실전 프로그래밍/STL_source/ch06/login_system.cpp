//////////////////////////////////////////////////////////////
/// 
/// \file aligning.cpp
///
/// \brief
///  set을 이용하여 로그인 제어
///
/// set을 이용하여 로그인을 제어하는 예. 입력된 계정 내용이
/// 저장되어 있는 내용과 일치하는 가를 판단.
///
/// \테스트환경
///  Gcc3.2.2, Comeau4.3.3, VC++6.0, VC++.NET 2003
///
/// \author 
///  Kim, Seungtai( stkim@yujinrobot.com )
/// 
/// \date
///  - 2004-08-10, Kim, Seungtai, Create
/// 
/// \see
///
//////////////////////////////////////////////////////////////

#include<set>
#include<string>
#include<iostream>

template<typename str_t>
struct account_t
{ 
	str_t id; 
	str_t passwd;
	
	bool operator < (const account_t<str_t> &right) const
	{
        return id < right.id;
	}
	
	bool operator == (const account_t<str_t> &right) const
	{
        return 
			(id == right.id) && (passwd == right.passwd);
    }
};

template<typename str_t>
class log_in
{
private:
	
	typedef std::set< account_t<str_t> > accounts_t;
	accounts_t accounts;
	
public:
	
	void add(str_t id, str_t passwd)
	{
		account_t<str_t> account;
		account.id = id;
		account.passwd = passwd;
		
		accounts.insert(account);
	}
	
	bool check(str_t id, str_t passwd)
	{
		account_t<str_t> account;
		account.id = id;
		account.passwd = passwd;
		
		typename accounts_t::const_iterator it = accounts.find(account);
		if( it != accounts.end())
		{
			if( *it == account ) return true;			
		}
		return false;
	}
};


int main()
{
	log_in<std::string> log_in_system;
	
	log_in_system.add("stkim", "1234");
	log_in_system.add("stkim", "1234");
	log_in_system.add("galgum001", "5678");
	
	std::string id, passwd;
	
	std::cout << "ID: ";
	std::cin >> id;
	std::cout << "PASSWD: ";
	std::cin >> passwd;
	
	if( log_in_system.check(id.c_str(), passwd.c_str()) )
		std::cout<< "SUCCESS" << std::endl;
	else
		std::cout<< "FAIL" << std::endl;
}