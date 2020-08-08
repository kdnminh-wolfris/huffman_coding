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
		map <char, string> encoded;

		void freq_to_tree(map <char, int> table);
		void tree_to_table(HuffmanNode* root, string code);
		void table_to_tree(string table); // to-do
		void load_table(ifstream& f, map<char, string> &encoded);
		void insertToTree(HuffmanNode*& root, char ch, string code, int i);

		void __print(const string &prefix, HuffmanNode* root, bool is_left);
	public:
		bool compress(string text_file, string compressed_file, string encoded_file);
		bool decompress(string text_file, string compressed_file, string encoded_file); // to-do
		void print();
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