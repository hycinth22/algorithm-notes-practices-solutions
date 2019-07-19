// 简单模拟-B1011.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main()
{
	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		long long a, b, c; cin >> a >> b >> c;
		cout << "Case #" << i << ": ";
		if (a + b > c) {
			cout  << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
}
