#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

// 注意： 2≤b≤10^9，所以不能转换成字符串进制表示，没有合适的表示方法，只能先将各位以数字形式存储于数组
vector<int> spiltbase(int num, int base) {
	vector<int> r;
	if (base <= 1) return r; // 进制最小为2
	while (num != 0) {
		r.insert(r.begin(), num % base);
		num /= base;
	}
	return r;
}

bool isHuiStr(const vector<int> &basestand) {
	// 起始位置到末位的距离是size-1。（0加size-1等于末位）
	// 则起始位置到中位的距离是(size-1)/2 = size/2 - 0.5，取整得size/2
	for (int i = 0; i < basestand.size() / 2; i++) {
		if (basestand[i] != basestand[basestand.size() - i - 1]) {
			return false;
		}
	}
	return true;
}

int main()
{
	int n, base; cin >> n >> base;
	auto str = spiltbase(n, base);
	cout << (isHuiStr(str) ? "Yes" : "No") << endl;
	auto it = str.cbegin();
	if (it != str.cend()) {
		cout << *it++; //输出和增加都需要在此。
		// end迭代器再次++会引起出错，因此需在此保证不是end才能++
	}
	for (; it != str.cend(); it++) {
		cout << " " << *it;
	}
	cout << endl;
}

