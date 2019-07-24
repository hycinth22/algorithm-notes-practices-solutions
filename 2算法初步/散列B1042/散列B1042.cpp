// 散列B1042.cpp
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

int main()
{
	cin.sync_with_stdio(false); cout.sync_with_stdio(false);
	string str; getline(cin, str);
	unordered_map<char, size_t> cnt;
	for (char& c : str) {
		if (isalpha(c)) {
			cnt[tolower(c)]++;
		}
	}
	if (cnt.empty()) {
		return 0;
	}
	auto it = cnt.begin();
	char letter = it->first; size_t max = it->second;
	while (it != cnt.end()) {
		if (it->second > max
			|| it->second == max && it->first<letter
			) {
			max = it->second;
			letter = it->first;
		}
		++it;
	}
	cout << letter << " " << max << endl;
}

