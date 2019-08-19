// map_A1071.cpp
//

#include <iostream>
#include <string>
#include <map>
using namespace std;

inline bool isalpha(char c) {
	return (c>='0' && c<='9') ||
		(c >= 'A' && c <= 'Z') ||
		(c >= 'a' && c <= 'z');
}

void analyse(const string& str, string& out_word, int& out_cnt) {
	if (str.empty()) return;
	map<string, size_t> cnt;
	string word;
	for (const char& tc : str) {
		if (isalpha(tc)) {
			char c = tolower(tc);
			word.append(1, c);
		}
		else {
			if (!word.empty()) {
				cnt[word]++;
			}
			word = "";
		}
	}
	if (!word.empty()) {
		cnt[word]++;
	}
	out_cnt = 0;
	for (auto& p : cnt) {
		if (p.second > out_cnt ||
			p.second == out_cnt && p.first < out_word
			) {
			out_word = p.first;
			out_cnt = p.second;
		}
	}
}

int main()
{
	string str, rword; int cnt;
	getline(cin, str);
	analyse(str, rword, cnt);
	cout << rword << " " << cnt;
}

