#include "huffman.h"

void HuffmanTree::to_tree() {
	priority_queue <pair <int, HuffmanNode *>> heap;
	for (auto x : frequency) {
		HuffmanNode* tmp = new HuffmanNode(-int(x.first));;
		heap.push({ -x.second, tmp });
	}
	while (heap.size() > 1) {
		auto right_child = heap.top(); heap.pop();
		auto left_child = heap.top(); heap.pop();
		HuffmanNode* tmp = new HuffmanNode(-(left_child.first + right_child.first));
		tmp->left = left_child.second;
		tmp->right = right_child.second;
		heap.push({ -tmp->val, tmp });
	}
	root = heap.top().second;
	heap.pop();
}

void HuffmanTree::print() {
	__print(root, 0, 0);
}

void HuffmanTree::__print(HuffmanNode* root, int level, int branch) {
	if (level) {
		for (int x = 3 * level; x--;)
			cout << ' ';
		cout << "|\n";
		for (int x = 3 * level; x--;)
			cout << ' ';
		cout << "--- ";
	}
	if (root->val < 0) {
		char c = -root->val;
		cout << "Letter: " << c << " - Frequency: " << frequency[c] << '\n';
	}
	else cout << "Total frequency: " << root->val << '\n';
}

bool HuffmanTree::compress(string text_file, string compressed_file, string encoded_table) {
	return false;
}

bool HuffmanTree::decompress(string text_file, string compressed_file, string encoded_table) {
	return false;
}
