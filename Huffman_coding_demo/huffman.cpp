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

void HuffmanTree::compress(ifstream &f, ofstream &txt)
{
	char ch;
	f.get(ch);
	while (ch != '#')
	{
		int a = this->frequency[ch];
		txt << a;
		f.get(ch);
	}
	return;
}

void FrequencyFinder::frequencyCounter(ifstream& f) //NEED # AT THE END OF FILE TO STOP
{
	char ch;
	map<char, int>::iterator it;
	f.get(ch);
	while(ch != '#') //stop with #
	{
		it = this->freTable.find(ch);
		if (it == this->freTable.end()) this->freTable[ch] = 1;
		else this->freTable[ch]++;
		f.get(ch);
	}
	return;
}

void FrequencyFinder::show()
{
	cout << "This is the Frequency Table: " << endl;
	for (map<char, int>::iterator it = this->freTable.begin(); it != this->freTable.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
}

FrequencyFinder::FrequencyFinder(string filename)
{
	ifstream f;
	f.open(filename);
	if (!f.is_open())
	{
		cout << "Error opening the text file" << endl;
		return;
	}

	this->frequencyCounter(f);
	f.close();
}