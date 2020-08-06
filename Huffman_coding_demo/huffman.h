#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>

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
	public:
		bool compress(char* text_file, char* compressed_file, char* encoded_table);
		bool decompress(char* text_file, char* compressed_file, char* encoded_table);
};

#endif