#include "huffman.h"

void HuffmanTree::freq_to_tree(map <char, int> table) {
	priority_queue <pair <int, HuffmanNode *>> heap;
	frequency = table;
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

void HuffmanTree::tree_to_table(HuffmanNode* root, string code) {
	if (root->val < 0)
		encoded[char(-root->val)] = code;
	else
		tree_to_table(root->left, code + '0'),
		tree_to_table(root->right, code + '1');
}

void HuffmanTree::table_to_tree(string table)
{
	ifstream f;
	f.open(table);
	if (!f.is_open())
	{
		cout << "Error loading the character table" << endl;
		return;
	}
	if (this->encoded.size() != 0)
	{
		cout << "The encode table is not empty. Error!" << endl;
		return;
	}
	else this->load_table(f, this->encoded);

	for (auto it : this->encoded)
	{
		char ch = it.first;
		string code = it.second;
		//BUILD TREE
		this->insertToTree(this->root, ch, code, 0);
	}

	return;
}

void HuffmanTree::load_table(ifstream& f, map<char, string> &encoded)
{
	char ch;
	string code;
	//LineFeed
	while (EOF != (ch = f.get()))
	{
		f.get();
		f >> code;
		encoded[ch] = code;
		ch = f.get();
	}

	for (auto it : encoded)
		cout << it.first << " " << it.second << endl;
	return;
}

void HuffmanTree::insertToTree(HuffmanNode*& root, char ch, string code, int i)
{
	if (i == code.size())
	{
		root->val = -int(ch);
		return;
	}
	
	if (code[i] == '0')
	{
		root->left = new HuffmanNode(0);
		this->insertToTree(root->left, ch, code, i + 1);
	}
	else if (code[i] == '1')
	{
		root->right = new HuffmanNode(1);
		this->insertToTree(root->right, ch, code, i + 1);
	}
	return;
}

void HuffmanTree::print() {
	__print("", root, false);
}

void HuffmanTree::__print(const string& prefix, HuffmanNode* root, bool is_left) {
	cout << prefix;
	cout << "|____";

	if (root->val < 0) {
		char c = -root->val;
		cout << "Letter: " << c << " - Frequency: " << frequency[c] << '\n';
	}
	else
		cout << "Total frequency: " << root->val << '\n',
		__print(prefix + (is_left ? "|     " : "      "), root->left, true),
		__print(prefix + (is_left ? "|     " : "      "), root->right, false);
}

bool HuffmanTree::compress(string text_file, string compressed_file, string encoded_file) {
	ifstream fi;
	fi.open(text_file);

	if (!fi.is_open()) {
		cout << "Error opening " << text_file << "\n";
		return false;
	}

	FrequencyFinder ff(text_file);
	freq_to_tree(ff.freTable);
	tree_to_table(root, "");

	ofstream fo;
	fo.open(compressed_file);

	char c;
	while (EOF != (c = fi.get()))
		fo << encoded[c];

	fi.close();
	fo.close();

	fo.open(encoded_file);

	for (auto x : encoded)
		fo << x.first << ' ' << x.second << '\n';
	
	fo.close();
	return true;
}

bool HuffmanTree::decompress(string text_file, string compressed_file, string encoded_file) {
	return false;
}

void FrequencyFinder::frequencyCounter(ifstream& f)
{
	map<char, int>::iterator it;
	char ch;
	while(EOF != (ch = f.get()))
	{
		it = this->freTable.find(ch);
		if (it == this->freTable.end()) this->freTable[ch] = 1;
		else this->freTable[ch]++;
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