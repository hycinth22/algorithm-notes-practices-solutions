// 简单模拟B1010.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int k, exp;
	bool output = false;
	while (cin >> k >> exp) {
		// 不能在此判断并输出空格（如果后续判断为零项不输出，则导致多余的空格）
		if (exp != 0) {
			k *= exp;
			exp -= 1;
			if (k != 0) {
				if (output) { // 必须在此判断并输出空格
					cout << " ";
				}
				cout << k << " " << exp;
				output = true;
			}
		}
	}
	if (!output) {
		cout << "0 0";
	}
	cout << endl;
}