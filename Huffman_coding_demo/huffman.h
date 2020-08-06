#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <map>
#include <string>

using namespace std;

class HuffmanNode {
	public:
		int val;
		HuffmanNode* left, * right;
		HuffmanNode() : val(0), left(nullptr), right(nullptr) {}
};

class HuffmanTree {
	private:
		HuffmanNode* root;
		HuffmanTree() : root(nullptr) {}

		bool compress(ifstream& in, ofstream& ou);
	public:
		bool compress(char* text_file, char* compressed_file, char* encoded_table);
		bool decompress(char* text_file, char* compressed_file, char* encoded_table);
};


class FrequencyFinder {
private:
	void frequencyCounter(ifstream& f);
public:
	map<char, int> freTable;
	void show();
	FrequencyFinder(string filename);
};
#endif