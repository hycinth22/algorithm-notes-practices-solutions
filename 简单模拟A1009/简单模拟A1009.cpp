// 简单模拟A1009.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <functional>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
	map<int, double, greater<int> > first, result;
	int n; cin >> n;
	while (n--) {
		int e; double k; cin >> e >> k;
		first[e] =  k;
	}
	cin >> n;
	while (n--) {
		int e; double k; cin >> e >> k;
		for (auto it = first.begin(); it != first.end(); it++) {
			const int& firstE = it->first;
			const double& firstK = it->second;
			result[e + firstE] += k* firstK;
		}
	}
	cout << count_if(result.cbegin(), result.cend(), [](auto it) {return it.second != 0.0; });
	// 注意此处应计算非零项，count_if用法，pred写法
	cout << fixed << setprecision(1); // 注意保留小数1位
	for (auto it = result.cbegin(); it != result.cend(); it++) {
		if (it->second!=0.0) { //注意判断非零
			cout << " " << it->first << " " << it->second;
		}
	}
}

