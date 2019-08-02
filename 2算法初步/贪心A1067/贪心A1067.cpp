// 贪心A1067.cpp
//

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	int n; cin >> n;
	vector<int> pos(n); // 由于保证无重，不实际顺序存储元素，而是采用记录出现的那些元素的对应位置的方法。
	// 在模拟交换时，可以直接O(1)直接查到元素所在位置。
	// 反之，如果存储元素，则需要遍历查找。
	for (int i = 0; i < n; i++) {
		cin >> pos[i];
	}
	int k; // 作为查找起始点，降低时间复杂度。k至多只会从1到n-1一次。
	// find the first not sorted as k
	for (int i = 0; i < n; i++) {
		if (pos[i] != i) {
			k = i;
			break;
		}
	}
	int ans = 0;
	while (1) {
		if (pos[0] == 0) {
			// check order,
			// if ordered already, terminate the process.
			// if unordered still, update k(firstly not sorted) so that we can avoid comparing those sorted
			// and swap zero with it(firstly not sorted) so that sort with swap(0, pos[0]) can continue.
			while (k < n && pos[k]==k) {
				k++;
			}
			if (k == n) {
				// all elements have been sorted.
				break; 
			}
			clog << "swap" << pos[0] << " " << pos[k] << endl;
			swap(pos[0], pos[k]);
		}
		else {
			// sort with swap(0, pos[0])
			clog << "swap" << pos[0] << " " << pos[pos[0]] << endl;
			swap(pos[0], pos[pos[0]]);
		}
		ans++;
	}
	cout << ans << endl;
}

