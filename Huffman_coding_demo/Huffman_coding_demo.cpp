#include "huffman.h"
#include <string>

using namespace std;

#define text_file "text/original.txt"
#define compressed_file "data/compressed.dat"
#define encoded_table "data/table.dat"

int main() {
	cout << "HUFFMAN CODING DEMONSTRATION\n\n";
	cout << "Choose mode:\n";
	cout << "(1) Compression\n";
	cout << "(2) Decompression\n";
	
	int t; cin >> t;

	HuffmanTree sol;
	if (t == 1) sol.compress(text_file, compressed_file, encoded_table);
	else sol.decompress(text_file, compressed_file, encoded_table);
	sol.print();
}