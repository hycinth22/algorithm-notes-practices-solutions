// 二分-找x.cpp
// Contest100000585 1934 Problem  A
// incompleted

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct input{
	size_t pos;
	int val;
};

int binaryFind(const vector<input>& v, const int& val) {
	int n = v.size();
	// range [left, right)
	int left = 0, right = n;
	while (left < right) {
		int mid = left + (right-left) / 2; // 注意这里如果结果是小数（即区间内有偶数个元素，区间长度为奇数，最中间有两个元素），会取整，同时因为right不算在区间内，落在中间偏右的元素。
		if (v[mid].val==val) {
			return v[mid].pos;
		}
		else if (val < v[mid].val) {
			right = mid;
		}
		else if (val > v[mid].val) {
			left = mid + 1; // 一定不要忘记+1，不仅仅是效率问题，忘记以后会在边界造成错过元素或死循环
			if (left >= n) {
				return -1;
			}
		}
	}
	return -1;
}

int main()
{
	int n; cin >> n;
	vector<input> d(n);
	for (size_t i = 0; i < n; i++) {
		cin >> d[i].val;
		d[i].pos = i;
	}
	int x; cin >> x;
	stable_sort(d.begin(), d.end(), [](const input& a, const input& b) {return a.val < b.val; });
	cout << binaryFind(d, x);
}

