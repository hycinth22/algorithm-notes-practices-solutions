// 二分A1048.cpp
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	size_t nCoins; int pay; cin >> nCoins >> pay;
	vector<int> coins;
	while (nCoins--) {
		static int par; cin >> par;
		coins.push_back(par);
	}
	sort(coins.begin(), coins.end());
	nCoins = coins.size(); bool nosolu = true;
	int c1, c2;
	for (size_t i = 0; i < nCoins; i++) {
		int another = pay - coins[i];
		// 相同的直接判断相邻是否有
		if (another == coins[i]) {
			if (i != 0 && coins[i - 1] == another || i != nCoins - 1 && coins[i + 1] == another) {
				c1 = c2 = coins[i];
				nosolu = false;
			}
			goto out;
		}
		size_t l = 0, r = nCoins - 1;
		// 缩小查找范围
		if (another < coins[i] && i != 0) {
			r = i - 1;
		}
		else {
			l = i + 1;
		}
		// 查找区间[l, r]
		while (l <= r) {
			size_t mid = (l + r) / 2;
			if (coins[mid] == another) {
				c1 = coins[i]; c2 = another;
				nosolu = false;
				goto out;
			}
			if (coins[mid] < another) {
				l = mid + 1;
			}
			else {
				if (mid == 0) {
					break;
				}
				r = mid - 1;
			}
		}
	}
out:
	if (nosolu) {
		cout << "No Solution" << endl;
	}
	else {
		cout << min(c1, c2) << " " << max(c1, c2) << endl;
	}
}