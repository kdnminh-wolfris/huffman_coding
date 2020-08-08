#include "huffman.h"
#include <string>

using namespace std;

#define text_file "text/text.txt"
#define compressed_file "data/compressed.dat"
#define encoded_table "data/table.dat"

int main() {
	cout << "HUFFMAN CODING DEMONSTRATION\n\n";

	cout << "/* compressed text is printed to a text file for demonstration purpose\n";
	cout << "/* in real applications, compressed text will be printed to a binary file in form of bits\n";
	cout << "_________________________________________________________________________________________\n\n";


	cout << "Choose mode:\n";
	cout << "(1) Compression\n";
	cout << "(2) Decompression\n";
	
	int t; cin >> t;

	HuffmanTree sol;
	if (t == 1) sol.compress(text_file, compressed_file, encoded_table);
	else sol.decompress(text_file, compressed_file, encoded_table);

	cout << "Huffman tree:\n";
	sol.print();
<<<<<<< HEAD
	
	sol.clear();
||||||| merged common ancestors
=======

	return 1;
>>>>>>> 6e15f436c281bfa9f850f2ab2e702038182dd183
}