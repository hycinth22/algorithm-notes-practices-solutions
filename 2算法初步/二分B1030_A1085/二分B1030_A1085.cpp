// 二分B1030_A1085.cpp
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

size_t upperbound(const vector<int>& v,
	size_t begin, size_t end,
	const long long& val) {
	if (v[end-1] <= val) { //注意特殊处理，后面的二分查找最多只能查找到end-1，在此种情况下少1。
		return end;
	}
	size_t l = begin, r = end-1;
	while (l < r) {
		size_t mid = (l + r) / 2;
		if (v[mid] < val) {
			l = mid + 1;
		}
		else {
			if (mid == 0) {
				break;
			}
			r = mid - 1;
		}
	}
	return r;
}

int main()
{
	int n, p; cin >> n >> p;
	vector<int> data(n);
	for (int& i : data) {
		cin >> i;
	}
	sort(data.begin(), data.end());
	// 最大值尽可能大，最小值尽可能小，且满足M≤mp，即M/m≤p
	size_t ans = 0;
	for (size_t i = 0; i != data.size(); ++i) {
		// m:data[i], M:data[u]
		// STL写法：
		/*
		auto r = upper_bound<int, long long>(data.cbegin()+i, data.cend(), (long long)p*data[i]);
		size_t d = r - (data.cbegin() + i);
		*/
		size_t r = upperbound(data, i, data.size(), (long long)p * data[i]);
		size_t d = r - i;
		ans = max(ans, d);
		clog << i << " " << d << endl;
	}
	cout << ans << endl;
}

