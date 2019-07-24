// 散列B1033.cpp
//

#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>
using namespace std;

int main()
{
	unordered_set<char> broken;
	bool brokenShift = false;
	string words;
	for (char c = cin.get(); c != '\n'; c = cin.get()) {
		if (c=='+') {
			brokenShift = true;
		}
		else {
			broken.insert(tolower(c));
		}
	}
	getline(cin, words);
	for (char c : words) {
		if (brokenShift && isupper(c)) {
			continue;
		}
		if (!broken.count(tolower(c))) {
			cout << c;
		}
	}
}

