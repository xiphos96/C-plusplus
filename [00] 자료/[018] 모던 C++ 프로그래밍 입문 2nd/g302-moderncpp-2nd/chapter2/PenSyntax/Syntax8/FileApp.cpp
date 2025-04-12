#include <iostream>
#include <fstream>
using std::ifstream; using std::ofstream;
using std::cout; using std::endl;

int main()
{
	ifstream input_file;
	input_file.open("infile.txt");		// open the input file
	if (!input_file.is_open()) {
		cout << "input file could not be opened! terminating!" << endl;
		return 1;
	}
	ofstream output_file("outfile.txt");		// open the output file
	if (!output_file.is_open()) {
		cout << "output file could not be opened! terminating!" << endl;
		return 1;
	}
	// read as long as the stream is good,
	// output is each number times two
	int datum;
	while (input_file >> datum) {
		output_file << datum * 2 << endl;
	}
	input_file.close();
	output_file.close();
	cout << "Done!" << endl;
	
	return 0;
}