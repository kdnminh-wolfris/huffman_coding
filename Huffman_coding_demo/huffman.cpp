#include "huffman.h"
#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

void FrequencyFinder::frequencyCounter(ifstream& f) //NEDD # AT THE END OF FILE TO STOP
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
