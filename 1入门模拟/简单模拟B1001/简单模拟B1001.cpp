﻿// 简单模拟B1001.cpp
//

#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	int cnt = 0;
	while (n != 1) {
		if (n % 2 == 0) {
			n /= 2;
		}
		else {
			n = n + (n + 1) / 2;
			// (3 * n + 1) / 2 =  (2 * n + n + 1) / 2 = n+(n+1)/2
		}
		cnt++;
	}
	cout << cnt << endl;
}

