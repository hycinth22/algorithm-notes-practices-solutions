// 简单模拟B1046.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	int afail = 0, bfail = 0;
	while (n--) {
		int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
		if (a1 + b1 == a2 && a1 + b1 != b2)
		{
			bfail++;
		}
		if (a1 + b1 != a2 && a1 + b1 == b2)
		{
			afail++;
		}
	}
	cout << afail << " " << bfail << endl;
}