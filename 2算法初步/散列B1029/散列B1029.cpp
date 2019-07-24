// 哈希B1029.cpp
// 

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
	cin.sync_with_stdio(false); cout.sync_with_stdio(false);
	string expect, actual; 
	getline(cin, expect);
	getline(cin, actual);
	unordered_set<char> actualSet, missing;
	vector<char> missingOrdered;
	for (char &c : actual) {
		actualSet.insert(toupper(c));
	}
	for (char& c : expect) {
		char upper = toupper(c);
		if (actualSet.count(upper) == 0) {
			if (missing.count(upper)==0) {
				missingOrdered.push_back(upper);
				missing.insert(upper);
			}
		}
	}
	for (char& c : missingOrdered) {
		cout << c;
	}
}
