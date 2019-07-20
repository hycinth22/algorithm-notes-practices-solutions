// 字符串处理A1005.cpp
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

const char* a[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int main()
{
	string n; getline(cin, n); // non-negative
	int sum = 0;
	for (char c : n) {
		sum += c - '0';
	}
	vector<int> indexs;
	if (sum == 0) {
		cout << a[0] << endl;

	}
	else {
		while (sum != 0) {
			indexs.push_back(sum%10);
			sum /= 10;
		}
		auto it = indexs.crbegin();
		cout << a[*it++];
		for (; it != indexs.crend(); ++it) {
			cout << " " << a[*it];
		}
	}
}

