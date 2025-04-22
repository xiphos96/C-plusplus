#if !defined(DICTIONARYINTERFACE_H)
#define DICTIONARYINTERFACE_H

#include"Dictionary.h"
#include<iomanip>
#include<iostream>

template< typename char_t >
class dictionary_interface_t
{
public:
	enum command_t { Invalid = 0, Exit, Query, Load, Merge, Save, New_Word };
	
	typedef std::basic_string<char_t> string_t;
	typedef std::basic_stringstream<char_t> stringstream_t;
	
private:	
	dictionary_t<char_t> book;
	
	std::basic_istream<char_t> &in;
	std::basic_ostream<char_t> &out;

public:

	// Read dictionary
	explicit dictionary_interface_t( 
		const std::basic_string< char_t > &dictionary_filename,
		std::basic_istream<char_t> &i,
		std::basic_ostream<char_t> &o,
		const string_t &ldelim,
		const string_t &rdelim)
		: 
		book( dictionary_filename, ldelim, rdelim ),
		in(i), out(o)
	{}

	// Print memuscript and get user command
	command_t menu() const
	{
		out << std::endl;
		out << string_t("-- STL 사전 v1.0--") << std::endl;
		out << string_t("1. 단어 질의") << std::endl;
		out << string_t("2. 사전 읽기") << std::endl;
		out << string_t("3. 사전 합치기") << std::endl;
		out << string_t("4. 저장하기") << std::endl;
		out << string_t("5. 새로운 단어 등록") << std::endl;
		out << string_t("6. 그만하기") << std::endl;
		out << string_t("입력> ");
		
		char_t user_input;
		in >> user_input ;
		
		switch(user_input) 
		{
		case char_t('1'): return Query;
		case char_t('2'): return Load;
		case char_t('3'): return Merge;
		case char_t('4'): return Save;
		case char_t('5'): return New_Word;
		case char_t('6'): return Exit;
		default: break;
		}

		return Invalid;
	}
	
	void query() const
	{
		out << string_t("단어: ");
		
		string_t word, before, after;
		in >> word ;
		
		typename dictionary_t<char_t>::means_t means;
		
		if(book.query( word, means, before, after))
		{
			std::copy( means.begin(), means.end(), 
				std::ostream_iterator<string_t>(out, "\n") );
			
			out << before << string_t(" <--") 
				<< word << string_t("--> ") 
				<< after << std::endl;
		}
		else
		{
			out << before << string_t(" <-- --> ") 
				<< after << std::endl;
		}
	}
	
	void load()
	{
		out << string_t("사전 이름: ");
		
		string_t dictionary;
		in >> dictionary ;
		
		typename dictionary_t<char_t>::means_t means;
		
		if(book.load( dictionary ))
		{
			out << string_t("성공: ") << dictionary << std::endl;
		}
		else
		{
			out << string_t("실패") << std::endl;
		}
	}
	
	void merge()
	{
		out << string_t("사전 이름: ");
		
		string_t dictionary;
		in >> dictionary ;
		
		typename dictionary_t<char_t>::means_t means;
		
		if(book.merge( dictionary ))
		{
			out << string_t("성공: ") << dictionary << std::endl;
		}
		else
		{
			out << string_t("실패") << std::endl;
		}
	}
	
	void save()
	{
		out << string_t("저장할 이름: ");
		
		string_t dictionary;
		in >> dictionary ;
		
		typename dictionary_t<char_t>::means_t means;
		
		if(book.save( dictionary ))
		{
			out << string_t("성공: ") << dictionary << std::endl;
		}
		else
		{
			out << string_t("실패") << std::endl;
		}
	}

	void new_word()
	{
		out << string_t("새로운 단어: ");
		
		string_t word;
		in >> word;
		
		out << string_t("뜻을 입력하시고, 마지막엔 마침표 '.'를 찍어주세요. : ");
		
		string_t mean;
		typename dictionary_t<char_t>::means_t means;
		while( in >> mean ) 
		{
			typename string_t::size_type pos( mean.find( string_t(".") ) );
			if( pos != string_t::npos )
			{
				if( pos > 1 )
					means.push_back(string_t(mean.begin(), mean.begin()+pos));
				break;
			}
			else
				means.push_back(mean);
		}
		
		if( book.new_word( word, means) )
		{
			out << string_t("성공: ") << word << std::endl;
		}
		else
		{
			out << string_t("실패") << std::endl;
		}
	}
};


#endif