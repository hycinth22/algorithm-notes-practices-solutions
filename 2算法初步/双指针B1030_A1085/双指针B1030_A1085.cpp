// 双指针B1030_A1085.cpp
// (广义指针，非严格语言意义上的指针，可以包括如数组下标）

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

int main()
{
	unsigned n, p; cin >> n >> p;
	vector<uint64_t> data(n);
	for (auto& i : data) {
		cin >> i;
	}
	sort(data.begin(), data.end());
	// 最大值尽可能大，最小值尽可能小，且满足M≤mp，即M/m≤p
	size_t ans = 0;
	size_t i = 0, j = 0;
	while (i < n) {
		while (j < n && data[j] <= data[i] * p) {
			j++;
		}
		i++;
		size_t d = j - i + 1;
		ans = max(ans, d);
	}
	cout << ans << endl;
}

