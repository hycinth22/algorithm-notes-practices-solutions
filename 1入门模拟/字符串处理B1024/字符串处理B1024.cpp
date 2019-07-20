// 字符串处理B1024.cpp
//

#include <iostream>
#include <string>
#include <cassert>
#include <cstdio>
using namespace std;

// [+-][1-9].[0-9]+E[+-][0-9]+
string normal(const string& sci) {
	if (sci.empty()) return "";
	char sign = sci.front();
	if (sign != '+' && sign != '-') {
		return "illegal sign";
	}
	size_t len = sci.length(),
		i = 2;
	while (i < len && (sci[i]>='0' && sci[i]<='9')) {
		i++;
	}
	if (sci[i] != '.') {
		return "illegal format";
	}
	size_t indexDot = i;
	i++;
	while (i < len && (sci[i] >= '0' && sci[i] <= '9')) {
		i++;
	}
	if (sci[i] != 'E') {
		return "illegal format";
	}
	size_t indexE = i;
	i++;
	size_t indexExpSign = i;
	i++;
	while (i < len && (sci[i] >= '0' && sci[i] <= '9')) {
		i++;
	}
	if (i != len) {
		return "illegal format";
	}

	string k1 = sci.substr(1, indexDot-1);
	string k2 = sci.substr(indexDot + 1, indexE - (indexDot + 1));
	char expSign = sci[indexExpSign];
	string expstr = sci.substr(indexExpSign + 1);
	int exp;
	sscanf(expstr.c_str(), "%d", &exp);

	const int k1len = 1;
	assert(k1len == k1.length());
	string result;
	if (expSign == '+') {
		result += k1 + k2;
		if (exp < k2.length()) {
			result.insert(k1len + exp, 1, '.');
		}
		else {
			result.append(exp-k2.length(), '0');
		}
	}
	else if (expSign == '-') {
		result += k1 + k2;
		if (exp < k1len) {
			result.insert(k1len - exp, 1, '.');
		}
		else {
			result.insert(0, exp - k1len, '0');
			result.insert(0, "0.");
		}
	}
	if (sign == '-') {
		result.insert(0, 1, '-');
	}
	return result;
}

int main()
{
	string input; getline(cin, input);
	cout << normal(input);
}

