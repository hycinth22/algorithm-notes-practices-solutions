// 简单数学B1019_A1069.cpp
//

#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;


string sub(const string& str1, const string& str2) {
	string result = to_string(stoi(str1) - stoi(str2));
	size_t len = result.length();
	if (len < 4) {
		result.insert(0, 4-len, '0');
	}
	return result;
}

bool euqal4(const string& str) {
	return str.size() == 4 && str[0] == str[1] && str[1] == str[2] && str[2] == str[3];
}

int main()
{
	string str; getline(cin, str);
	size_t len = str.size();
	if (len > 4) {
		return 1;
	}
	if (len < 4) { 
		// 注意，题目没有说明是4位字符串，只说是正整数。小于4位的输入是合法数据，需要手动补齐4位
		str.insert(0, 4-len, '0');
	}
	if (euqal4(str)) {
		cout << str << " - " << str << " = " << "0000" << endl;
		return 0;
	}
	string str2(str), result;
	while (result != "6174") {
		sort(str.begin(), str.end(), greater<char>());
		sort(str2.begin(), str2.end(), less<char>());
		result = sub(str, str2);
		cout << str << " - " << str2 << " = " << result << endl;
		str = str2 = result;
	}
}

