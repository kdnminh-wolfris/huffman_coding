#include "huffman.h"
#include <string>

using namespace std;

#define text_file "text/text - sample.txt"
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
	sol.clear();
}