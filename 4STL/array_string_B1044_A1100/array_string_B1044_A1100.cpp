// array_string_B1044_A1100.cpp
//

#include <iostream>
#include <array>
#include <string>
#include <cctype>
using namespace std;

const array<string, 13> int2huo_low = {
	"tret",
	"jan", "feb", "mar", "apr",
	"may", "jun", "jly", "aug",
	"sep", "oct", "nov", "dec"
},
int2huo_high = {
		"",
		"tam", "hel", "maa", "huh",
		"tou", "kes", "hei", "elo",
		"syy", "lok", "mer", "jou"
};

int findIn(const array<string, 13> & arr, const string& str) {
	for (size_t i = 0; i < arr.size(); i++) {
		if (arr[i] == str) {
			return int(i);
		}
	}
	return -1;
}

int parseFromHuo(const string& str) {
	size_t s = str.find(" ");
	if (s == string::npos) {
		int high = findIn(int2huo_high, str);
		if (high != -1) {
			return high * 13;
		}
		int low = findIn(int2huo_low, str);
		if (low != -1) {
			return low;
		}
		return 0;
	}
	string a = str.substr(0, s), b = str.substr(s + 1);
	return findIn(int2huo_high, a) * 13 + findIn(int2huo_low, b);
}
string toHuo(int i) {
	if (i >= 169) {
		i %= 169;
	}
	if (i < 13) {
		return int2huo_low[i % 13];
	}
	if (i % 13 == 0) {
		// 注意点：13的整倍数，不应该输出低位的0（即tret）
		return int2huo_high[i / 13];
	}
	return int2huo_high[i / 13] + " " + int2huo_low[i % 13];
}
int parseFromDi(const string& i) {
	return stoi(i);
}
string toDi(int i) {
	return to_string(i);
}

int main()
{
	int n; cin >> n; cin.get();
	string str;
	while (n--) {
		getline(cin, str);
		if (!str.empty()) {
			if (isdigit(str.front())) {
				cout << toHuo(parseFromDi(str)) << endl;
			}
			else {
				cout << toDi(parseFromHuo(str)) << endl;
			}
		}
	}
}
