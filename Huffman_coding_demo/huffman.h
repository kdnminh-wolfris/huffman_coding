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
		HuffmanNode* root;
		HuffmanTree() : root(nullptr) {}

		void compress(ifstream &f, ofstream &txt); //test version

		map <char, int> frequency;

		void to_tree();

		void print();
		void __print(HuffmanNode* root, int level, int branch);
	public:
		bool compress(string text_file, string compressed_file, string encoded_table);
		bool decompress(string text_file, string compressed_file, string encoded_table);
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