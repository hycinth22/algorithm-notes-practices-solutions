// 贪心A1038.cpp
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool cmp(string& a, string& b) {
	// 注意，字符串拼接结果最小的判断方法。
	// 而不能直接a<b（只有当全部为1位可以这样做）
	// 如 12+3<3+12，但如果按3<12将错判
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

