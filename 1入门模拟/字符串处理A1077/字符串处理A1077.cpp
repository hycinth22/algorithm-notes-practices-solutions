// 字符串处理A1077.cpp
//

#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

inline string suffix(const string& str, size_t n){
	return str.substr(str.length()-n, n);
}
inline char backn(const string& str, size_t n) {
	return str[str.length()-n];
}

string Kuchiguse(vector<string> spoken) {
	if (spoken.empty()) {
		return "";
	}
	size_t length = 0;
	for (;;) {
		size_t toCheck = length + 1;
		bool success = true;
		for (const string& words: spoken) {
			if (words.length() < toCheck
				|| backn(words, toCheck) != backn(spoken[0], toCheck)) {
				// 注意越界以及不要死循环
				success = false;
				break;
			}
		}
		if (success) {
			length++;
		}
		else {
			break;
		}
	}
	if (length == 0) {
		return "nai";
	}
	return suffix(spoken[0], length);
}

int main()
{
	int n; cin >> n;
	vector<string> spoken;
	cin.get(); // 使用getline前要注意空白字符问题
	while (n--) {
		string str; getline(cin, str);
		spoken.emplace_back(move(str));
	}
	cout << Kuchiguse(spoken);
}

