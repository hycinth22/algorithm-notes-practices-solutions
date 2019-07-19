// 简单模拟A1002.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <functional>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
	map<int, double, greater<int> > m;
	int n; cin >> n;
	while (n--) {
		int e; double k; cin >> e >> k;
		m[e] += k;
	}
	cin >> n;
	while (n--) {
		int e; double k; cin >> e >> k;
		m[e] += k;
	}
	cout << count_if(m.cbegin(), m.cend(), [](pair<int, double> it) { return it.second != 0.0;});
	for (auto it = m.cbegin(); it != m.cend(); it++) {
		double k = it->second;
		if (k != 0.0) {
			cout << " " << it->first << " " << fixed << setprecision(1) << k;
		}
	}
}

