// 素数A1078.cpp
//

#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

bool isPrime(int m) {
	if (m <= 1) return false; // 注意边界数据。不要只写==1，0和负数也不是质数。
	int edge = int(sqrt(m)); // 注意边界条件。数学上应该是i<sqrt(m)，但是由于结果取整，小数部分被舍去，需要写成i<=sqrt(m)
	// 同时注意，缓存结果以防止循环中多次重复开方运算。
	for (int i = 2; i <= edge; i++) {
		if (m % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	int msize, n; cin >> msize >> n;
	while (!isPrime(msize)) {
		msize++;
	}

	vector<bool> posFlag(msize, false);
	vector<int> pos(msize, -1);
	for (int i = 0; i < n; i++) {
		static int t, hash;
		cin >> t; hash = t % msize;
		int step = 1;
		int finalhash = hash;
		while (posFlag[finalhash] && step < msize) // 注意此处判断不可能插入的方法
		{
			finalhash = (hash + step * step) % msize; // 注意二次探查法的写法，是从原位置逐次查找raw+0^2, raw+1^2, raw+2^2..., raw+k^2
			step++;
		}
		if (!posFlag[finalhash]) {
			posFlag[finalhash] = true;
			pos[i] = finalhash;
		}
		else {
			pos[i] = -1; // impossible to insert
		}
	}
	if (!pos.empty()) {
		for (int i = 0; i < n; i++) {
			if (i != 0) cout << " ";
			// cout << " " << (pos[i] != -1 ? pos[i] : "-"); 错误写法，三目表达式必须一致类型，'-'会被强转为int
			if (pos[i] == -1) {
				cout << "-";
			}
			else {
				cout << pos[i];
			}
			
		}
	}
	cout << endl;
}

