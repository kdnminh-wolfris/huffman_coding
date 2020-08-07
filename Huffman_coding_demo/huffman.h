#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <fstream>
#include <map>
#include <queue>

using namespace std;

class HuffmanNode {
	public:
		int val;
		HuffmanNode* left, * right;
		HuffmanNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class HuffmanTree {
	private:
		HuffmanNode* root = nullptr;

		map <char, int> frequency;

		void to_tree();

		void print();
		void __print(HuffmanNode* root, int level, int branch);
	public:
		bool compress(string text_file, string compressed_file, string encoded_table);
		bool decompress(string text_file, string compressed_file, string encoded_table);
};

#endif