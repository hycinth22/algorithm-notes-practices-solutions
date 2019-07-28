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
	vector<int> v(n); 
	for (int& i : v) {
		cin >> i;
	}
	int izero = 0;
	// find zero
	for (int i = 0; i < n; i++) {
		if (v[i] == 0) {
			izero = i;
			break;
		}
	}
	int k = 0;
	// find first not sorted
	for (int i = 0; i < n; i++) {
		if (v[i] != i) {
			k = i;
			break;
		}
	}
	int ans = 0;
	while (1) {
		// check order & update k
		bool order = true;
		for (int i = k; i < n; i++) {
			if (v[i] != i) {
				k = i;
				order = false;
				break;
			}
		}
		if (order) {
			break;
		}
		if (v[0] == 0) {
			for (int i = k; i < n; i++) {
				// swap zero with any number which is not in its correct position
				if (v[i] != i) {
					clog << "swap" << v[0] << " " << v[i] << endl;
					swap(v[0], v[i]);
					izero = i; // 注意更新izero
					ans++;
					break;
				}
			}
		}
		else {
			for (int i = 0; i < n; i++) {
				if (v[i] != i && v[i] == izero) {
					clog << "swap" << v[izero] << " " << v[i] << endl;
					swap(v[izero], v[i]);
					izero = i; // 注意更新izero
					ans++;
					break;
				}
			}
		}
	}
	cout << ans << endl;
}

