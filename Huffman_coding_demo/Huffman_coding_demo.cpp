#include "huffman.h"
#include <string>

using namespace std;

int main() {
	FrequencyFinder ff(string("text.txt"));
	ff.show();
	return 1;
}