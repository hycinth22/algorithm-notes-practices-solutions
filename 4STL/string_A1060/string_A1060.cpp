// string_A1060.cpp
//

#include <iostream>
#include <string>
using namespace std;

string normalize(const string& str, size_t n) {
	string normal = "0.";
	size_t i = 0, len = str.size(), // str遍历
		cnt = 0; // 已复制的有效数字位数，最多为n
	int exp = 0; // 指数
	// 整数部分开始
	// prefix zero
	while (str[i] == '0') {
		i++;
	}
	// 统计整数位数（cnt）、指数（exp），复制最多n个有效数字
	while (i < len && str[i] != '.') {
		if (cnt < n) {
			normal.append(1, str[i]);
		}
		exp++;
		cnt++;
		i++;
	}
	// assert(exp == cnt); // 对于整数部分，两者应该相等
	// 跳过点（.）
	if (i < len && str[i] == '.') {
		i++; // dot
	}
	// 小数部分开始
	if (cnt == 0) {
		// 整数部分为0，小数部位需要跳过前导0并更改指数
		// prefix zero
		while (str[i] == '0') {
			i++;
			exp--;
		}
	}
	// 复制最多n个有效数字
	while (i < len) {
		if (cnt < n) {
			normal.append(1, str[i]);
			cnt++;
		}
		i++;
	}
	if (cnt == 0) {
		exp = 0; // 特例，如果没有有效数字（结果是0.0...0），指数需要归0
		//（否则输出指数为负数，对应前面skip prefix zero部分遍历的0个数）
	}
	if (cnt < n) {
		normal.append(n - cnt, '0'); // 有效数字不足，剩余的补0
	}
	normal.append("*10^");
	normal.append(to_string(exp));
	return normal;
}

int main()
{
	int n; cin >> n;
	string a, b; cin >> a >> b;
	a = normalize(a, n);
	b = normalize(b, n);
	bool equal = a == b;
	if (equal) {
		cout << "YES " << a << endl;
	}
	else {
		cout << "NO " << a << " " << b << endl;
	}
}

