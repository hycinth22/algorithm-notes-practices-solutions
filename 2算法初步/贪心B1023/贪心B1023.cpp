// 贪心B1023.cpp
// 简单贪心

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int> cnt(10, 0);
	for (int i = 0; i < 10; i++) {
		cin >> cnt[i];
	}
	string r;
	// 首位不能为0
	for (int i = 1; i < 10; i++) {
		if (cnt[i] > 0) {
			cnt[i]--;
			r = '0'+i;
			break; // 记得中断循环
		}
	}
	for (int i = 0; i < 10; i++) {
		r.append(cnt[i], '0' + i);
	}
	cout << r << endl;
}

