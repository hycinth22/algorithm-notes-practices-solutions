// 贪心A1038.cpp
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool cmp(string& a, string& b) {
	return a + b < b + a;
}

int main()
{
	int n; cin >> n;
	vector<string> v(n);
	for (auto& str: v) {
		cin >> str;
	}
	sort(v.begin(), v.end(), cmp);
	string str = accumulate(v.begin(), v.end(), string());
	str.erase(0, str.find_first_not_of('0'));
	if (str.empty()) {
		str = "0";
	}
	cout << str << endl;
}

