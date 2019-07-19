// 字符串B1014.cpp
//
/*
Case:

input
3485djDkxh4hhGE
2984akDfkkkkggEdsb
s&hgsfdk
d&Hyscvnm

output
THU 14:04 
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

const string whatday[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

const auto upperPred = bind(
	logical_and<>(),
	bind(greater_equal<>(), placeholders::_1, 'A'),
	bind(less_equal<>(), placeholders::_1, 'Z')
);

const auto lowerPred = bind(
	logical_and<>(),
	bind(greater_equal<>(), placeholders::_1, 'a'),
	bind(less_equal<>(), placeholders::_1, 'z')
);

int parseHEX(char hex) {
	if (hex >= '0' && hex <= '9') {
		return hex - '0';
	}
	if (hex >= 'a' && hex <= 'z') {
		return 10 + (hex - 'a');
	}
	if (hex >= 'A' && hex <= 'Z') {
		return 10 + (hex - 'A');
	}
	return -1;
}

int main()
{
	string s1, s2, s3, s4; cin >> s1 >> s2 >> s3 >> s4;

	size_t i = 0;
	char letter1;
	{
		bool found = false;
		while (i < s1.length() && i < s2.length()) {
			// 注意是A-G而不是A-Z
			if (s1[i]>='A'&& s1[i] <= 'G' && s1[i] == s2[i]) {
				found = true;
				break;
			}
			i++;
		}
		if (!found) {
			return -1;
		}
		letter1 = s1[i];
	}
	cout << whatday[letter1 - 'A'] << " ";
	i++;
	char letter2;
	{
		bool found = false;
		while (i < s1.length() && i < s2.length()) {
			// 注意题意中是“相同的字符”，因此也包括数字
			if (
				( s1[i] >= '0' && s1[i] <= '9'
				||
				s1[i] >= 'A' && s1[i] <= 'N' 
				)
				&& s1[i] == s2[i]) {
				found = true;
				break;
			}
			i++;
		}
		if (!found) {
			return -1;
		}
		letter2 = s1[i];
	}
	// 注意补位填充
	cout << setfill('0') << setw(2) << parseHEX(letter2) << ":";
	i = 0;
	size_t letter3Pos;
	{
		bool found = false;
		while (i < s3.length() && i < s4.length()) {
			// 注意此处大小写都包括
			if ((upperPred(s3[i]) || lowerPred(s3[i])) && s3[i] == s4[i]) {
				found = true;
				break;
			}
			i++;
		}
		if (!found) {
			return -1;
		}
		letter3Pos = i;
	}
	// 注意补位填充
	cout << setfill('0') << setw(2) << letter3Pos;
}

