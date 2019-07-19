#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



int main() {
	string str1, str2;
	cin >> str1 >> str2;
	reverse(str1.begin(), str1.end()); reverse(str2.begin(), str2.end());
	size_t len1 = str1.length();
	size_t len2 = str2.length();
	size_t lenr = max(len1, len2);
	string result(lenr, 'X');
	str1.append(lenr - len1, '0');
	str2.append(lenr - len2, '0');
	size_t i;
	for (i = 0; i < lenr; i++) {
		bool odd = (i % 2 == 0);
		if (odd)
		{
			int a = str1[i] - '0';
			int b = str2[i] - '0';
			const int k = 13;
			int t = (a + b) % k;
			const char letters[k] = { '0', '1', '2', '3', '4', '5',
				'6', '7', '8', '9',
				'J', 'Q', 'K' };
			result[i] = letters[t];
		}
		else
		{
			int a = str1[i] - '0';
			int b = str2[i] - '0';
			int t = b - a;
			if (t < 0)
			{
				t += 10;
			}
			result[i] = '0' + t;
		}
	}
	reverse(result.begin(), result.end());
	if (result.empty()) {
		result = "0";
	}
	cout << result;
}
