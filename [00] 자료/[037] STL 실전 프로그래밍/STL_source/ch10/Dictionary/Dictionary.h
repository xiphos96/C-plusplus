#if !defined(DICTIONARY_H)
#define DICTIONARY_H

#include<map>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
#include<utility>
#include<string>
#include<algorithm>
#include<iterator>


template< typename char_t >
class dictionary_t
{
public:
	typedef std::basic_string<char_t> string_t;
	typedef std::vector< string_t > means_t;
	typedef std::map< string_t, means_t > book_t;

private:
	book_t book;
	string_t left_delim;
	string_t right_delim;
		
public:

	// Initialize dictionary.
	//  : It reads the word list at the file as line by line
	//    and stores at book.
	explicit dictionary_t(
		const string_t &dictionary_name,
		const string_t &ldelim,
		const string_t &rdelim)
		: left_delim(ldelim), right_delim(rdelim)
	{
		if( load( dictionary_name ) == false )
			throw std::logic_error("Fail to load file");
	}

	// Request the means of a word. If there is no such a word
	// it returns false else not. The "before" and "after" has 
	// the before and after word as the matching word.
	bool query( 
		const string_t &word, means_t &means, 
		string_t &before, string_t &after) const
	{
		typename book_t::const_iterator it = book.find( word );

		// If there is no such a word, return false.
		if( it == book.end() )
		{
			if( (it = book.upper_bound( word )) != book.end() )
			{
				after = it->first;

				if( it != book.begin() )
					before = (--it)->first;
				else
					before = string_t("--");
			}
			else
			{
				after = string_t("--");
				before = string_t("--");
			}

			return false;
		}

		// Before word
		if( it != book.begin() ) 
		{
			typename book_t::const_iterator bit(it);
			before = (--bit)->first;
		}
		else
			before = string_t("--");

		// After word
		if( it != book.end() )
		{
			typename book_t::const_iterator ait(it);
			if( ++ait != book.end() )
				after = ait->first;
			else
				after = string_t("--");
		}
		else
			after = string_t("--");

		means = it->second;

		return true;
	}

	// Load dictionary.
	bool load(const string_t &dictionary_name)
	{
		// Erase all data
		book.clear();

		return merge( dictionary_name );
	}

	// Merge dictionary
	bool merge( const string_t &dictionary_name )
	{		
		// Open Dictionary File.
		std::basic_ifstream<char_t> dictionary_file( dictionary_name.c_str() );
		
		// There is no such a file.
		if(!dictionary_file) return false;
		
		// Read whole dictinary
		//  : It has the word information per a line
		string_t temp_a_line;
		while( std::getline(dictionary_file, temp_a_line) )
		{
			typename string_t::size_type pos(0);
			
			// Read word
			string_t word;
			get_token( temp_a_line, pos, word );
			
			
			// Read means from a line
			std::vector< string_t > means;
			string_t mean;
			while( get_token( temp_a_line, pos, mean ) )
			{
				means.push_back( mean );
			}
			
			// Insert the word into book.
			book.insert( std::make_pair( word, means ) );
		}

		dictionary_file.close();

		return true;
	}

	// Save current book to dictionary_name
	bool save( const string_t &dictionary_name ) const
	{
		std::basic_ofstream<char_t> dictionary_file(dictionary_name.c_str());

		if(!dictionary_file) return false;

		for( typename book_t::const_iterator it = book.begin();
		it != book.end(); ++it)
		{
			// Word
			dictionary_file << to_token(it->first) << string_t(" ");

			// Means
			for( typename means_t::const_iterator it_means = it->second.begin();
			it_means != it->second.end(); ++it_means)
			{
				dictionary_file << to_token(*it_means) << string_t(" ");
			}

			dictionary_file << std::endl;
		}

		dictionary_file.close();

		return true;
	}

	// Add new word. 
	// If the word is already existed, it is rejected and returns false.
	bool new_word( const string_t &word, const means_t &means)
	{
		return book.insert( std::make_pair( word, means ) ).second;
	}

private:
		
	// Read a token from source. If there is no token more, 
	// it returns false else true.
	//  : token is started with '[' and terminated with ']'
	bool get_token( 
		const string_t &source, 
		typename string_t::size_type &pos,
		string_t &token)
	{
		// Check parameters
		if( pos > source.size() ) return false;
		
		// Find token
		typename string_t::size_type start_pos = source.find_first_of( left_delim, pos);
		typename string_t::size_type end_pos = source.find_first_of( right_delim, pos );
		
		// If the delimiter is not found, return.
		if( start_pos == string_t::npos || end_pos == string_t::npos ) return false;
		
		// Set token
		token = string_t( source.begin() + start_pos + 1, source.begin() + end_pos );
		
		// Set new position
		pos = end_pos +1;
		
		return true;
	}	
	
	// Make word to token and return it.
	//  : token is started with '[' and terminated with ']'
	string_t to_token( const string_t &word ) const
	{
		string_t token(word);
		
		token.insert(0, left_delim);
		token.append(right_delim);

		return token;
	}
};

#endif




























