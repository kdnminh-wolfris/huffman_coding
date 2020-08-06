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
		HuffmanTree(char* txt);
		void compress(char* txt);
};

#endif