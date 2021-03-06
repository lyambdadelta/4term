#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <iomanip>
using namespace std;

bool isletter(char& c) {
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= 'а' && c <= 'я') || (c >= 'А' && c <= 'Я')) {
		return 1;
	}
	else {
		return 0;
	}
}

vector<string> parse(string s) {
	string word = "";
	vector<string> words;
	int flag = 0;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	for (auto let : s) {
		if (isletter(let)) {
			if (!flag) {
				flag = 1;
			}
			word += let;
		}
		else {
			if (flag) {
				words.push_back(word);
				word = "";
				flag = 0;
			}
		}
	}
	if (flag) {
		words.push_back(word);
	}
	return words;
}

int getlenght(int N) {
	int n;
	for (n = 0; N > 0; n++) {
		N /= 10;
	}
	return n;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int N, counter = 0, n, setfr = 0;
	cout << "Enter number of words: ";
	cin >> N;
	n = getlenght(N);
	map <string, int> dict;
	map <int, set<string>> freq;
	ifstream text("book.txt");
	string s;
	while (!text.eof()) {
		text >> s;
		for (auto word : parse(s)) {
			dict[word]++;
		}
	} 
	for (auto line : dict) {
		freq[line.second].insert(line.first);
	} 
	{
		auto it = freq.rbegin();
		setfr = getlenght(it->first);
	}
	for (auto it = freq.rbegin(); it != freq.rend(); it++) {
		for (auto word : it->second) {
			if (counter < N) {
				cout << "The " << setw(n) << counter + 1 << " word with frequency " << setw(setfr) << it->first << " is " << word << endl;
				counter++;
			}
		}
	}
	cout << "Thanks for using AVIS4 program!" << endl;
	system("PAUSE");
    return 0;
}

