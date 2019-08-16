// 因子分解A1096.cpp。
// 注意点：此题只要求是因子，没有要求必须是质数因子。
// 注意点：此题的要求，n分解为一组因子，可以只取这一组中某一段连续的作为答案，而不要求一组因子整体连续。
// 数学技巧：计算各数字的乘积，若n能整除这些数的乘积，
// 则可以判断这些数字都是n的因子，且可以在同一组因子组合中同时存在（即乘积<=n，且乘积/n为整数）。
// 从小到大遍历，保证了同等长的的连续因子区间之中，必定先发现开头小的那些。

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// factors (without 1)
vector<int> factorConsecutive(int n) {
	if (n <= 1) { return {}; }
	int begin = 2, len = 0;
	int edge = int(sqrt(n))+1; // 优化边界
	for (int i = 2; i <= edge; i++) {
		// find 连续因子[i, j)
		int j = i;
		int product = 1; // 乘积可能溢出
		while (j <= edge && product) {
			product *= j; // 序列[i, j]的乘积，只要j也是因子，则n必定可整除product
			if (product <= 0 /* 判断乘积过大溢出 */ || 
				n % product != 0) {
				break;
			}
			j++;
		}
		// 此时[i, j)，是n的一段连续因子，对比是否是最长序列。
		if (j-i > len) {
			begin = i;
			len = j-i;
		}
	}
	if (len == 0) {
		return {n};
	}
	vector<int> r;
	for (int i = begin; i < begin + len; i++) {
		r.push_back(i);
	}
	return r;
}

int main()
{
	int n; cin >> n;
	auto result = factorConsecutive(n);
	cout << result.size() << endl;
	for (size_t i = 0; i < result.size(); i++) {
		if (i!=0) {
			cout << "*";
		}
		cout << result[i];
	}
	cout << endl;
}

