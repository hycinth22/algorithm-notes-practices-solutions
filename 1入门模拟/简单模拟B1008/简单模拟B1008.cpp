// 简单模拟B1008.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m; cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) 
	{
		cin >> v[i];
	}
	m %= n;
	for (int i = n-m, cnt = 0; cnt < n; i++, cnt++) {
		if (i == n) {
			i = 0;
		}
		cout << v[i];
		if (cnt != n - 1) {
			cout << " ";
		}
	}
}