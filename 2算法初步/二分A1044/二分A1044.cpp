// 二分A1044.cpp
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, m; cin >> n >> m;
	n++;
	vector<int> sums(n);
	sums[0] = 0;
	for (size_t i = 1; i < n; i++) {
		static int t; cin >> t; // 输入数据非有序，且要求保持相对位置。不可以直接应用二分查找。
		sums[i] = sums[i - 1] + t; // 通过累加方法，使存储数据成为递增序列，从而可以应用二分等要求有序的算法。
		// 限制：要求输入规模较小，否则累加后易溢出。
		// 限制：二分查找时，也不知道原数据累加后是多少。
		// 因此不能够以原数据为关键字进行查找，只能适用于查找关键字增减变化区间（如原数据k，条件长度n，查找数据k+n、k-n在哪里）。
	}
	int minWatsePay = sums.back(); bool noans = true;
	for (int i = 1; i < n; i++) {
		size_t j = upper_bound(sums.data()+i, sums.data()+n, sums[i-1]+m) - sums.data();
		if (sums[j-1]-sums[i-1] == m) {
			cout << i << "-" << j-1 << endl;
			noans = false;
		}
		else if (j != n){
			minWatsePay = min(minWatsePay, sums[j] - sums[i-1]);
		}
	}
	if (noans) {
		for (int i = 1; i < n; i++) {
			size_t j = upper_bound(sums.data() + i, sums.data() + n, sums[i-1] + minWatsePay) - sums.data();
			if (sums[j - 1] - sums[i - 1] == minWatsePay) {
				cout << i << "-" << j - 1 << endl;
			}
		}
	}
}

