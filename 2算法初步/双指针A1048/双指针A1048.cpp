// 双指针A1048.cpp
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
	for (size_t i = 0; i < nCoins; i++) {
		static int par; cin >> par;
		coins.push_back(par);
	}
	sort(coins.begin(), coins.end());
	// 下面的算法需要保证至少有一个数据，否则j无符号数，减法溢出。
	size_t i = 0, j = (nCoins!=0)?(nCoins-1):0;
	while (i < j) {
		if (coins[i]+coins[j]==pay) {
			// 找到解，由于序列升序，i从左向右扫描，也保证这是coins[i]最小的一组解。
			break;
		}
		if (coins[i] + coins[j] < pay) {
			i++;
		}
		else {
			j--;
		}
	}
	if (i>=j) {
		cout << "No Solution" << endl;
	}
	else {
		cout << coins[i] << " " << coins[j] << endl;
	}
}