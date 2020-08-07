#include "huffman.h"
#include <string>

using namespace std;

#define text_file "original.txt"
#define compressed_file "compressed.dat"
#define encoded_table "table.dat"

int main() {
	FrequencyFinder ff(string("text.txt"));
	ff.show();
	return 1;

	cout << "HUFFMAN CODING DEMONSTRATION\n\n";
	cout << "Choose mode:\n";
	cout << "(1) Compression\n";
	cout << "(2) Decompression\n";
	
	int t; cin >> t;

	HuffmanTree sol;
	if (t == 1) sol.compress(text_file, compressed_file, encoded_table);
	//else sol.decompress(text_file, compressed_file, encoded_table);
}