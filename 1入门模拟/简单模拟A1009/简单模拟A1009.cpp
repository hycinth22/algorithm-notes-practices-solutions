// 简单模拟A1009.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <functional>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	map<int, double, greater<int> > first, result;
	int n; cin >> n; 
	while (n--) {
		int e; double k; cin >> e >> k;
		result[e] =  k;
	}
	while (cin >> n) {
		first = result;
		result.clear();
		while (n--) {
			int e; double k; cin >> e >> k;
			for (auto it = first.begin(); it != first.end(); it++) {
				const int& firstE = it->first;
				const double& firstK = it->second;
				double t = k * firstK;
				if (fabs(t)>=0.05) {
					result[e + firstE] += t;
				}
			}
		}
	}

	cout << count_if(result.cbegin(), result.cend(), [](auto it) {return it.second != 0.0; });
	// 注意此处应计算非零项，count_if用法，pred写法
	cout << fixed << setprecision(1); // 注意保留小数1位
	for (auto it = result.cbegin(); it != result.cend(); it++) {
		if (it->second!=0.0) { //注意判断非零
			cout << " " << it->first << " " << it->second;
			//cout << " + " << it->second << "x^" << it->first;
		}
	}
	cout << endl;
}

