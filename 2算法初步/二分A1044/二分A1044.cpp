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
		static int t; cin >> t;
		sums[i] = sums[i - 1] + t;
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

