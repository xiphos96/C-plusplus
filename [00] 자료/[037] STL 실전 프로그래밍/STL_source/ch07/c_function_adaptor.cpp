extern "C" void encryption(const unsigned char *key, 
						   const unsigned char *data, 
						   unsigned char *prst);

#include<string>
#include<iostream>

template< typename char_t >
struct adaptor_encryption
{
	void operator()
		(
		const std::pair< 
			std::basic_string< char_t >, 
			std::basic_string< char_t > 
			> &input,
		char_t *prst
		)
	{
		encryption( input.first.data(), input.second.data(), prst );
	}
};

int main()
{
	unsigned char rst[8];
	unsigned char key[8] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07 };
	unsigned char dat[8] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07 };

	adaptor_encryption<unsigned char>()(
		std::make_pair( 
			std::basic_string<unsigned char>(key), 
			std::basic_string<unsigned char>(dat) ),
		rst);
}
