// 最大公约数与最小公倍数B1008.cpp
// 数组原地循环

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

template<class T>
T gcd(T a, T b) {
	return (b == 0) ? a : gcd(b, a%b);
}

void inplace_moveforward(vector<int>& cont, size_t offset) {
	size_t len = cont.size(), d = gcd(cont.size(), offset);
	offset %= len;
	// 如果互质，则d=1，整个序列都可以到达，从一个开始就可以完成整个移动。
	// 如果不互质，d!=1，则有gcd个数列互相不能到达。任选一地点开始，进行gcd次循环移动。
	for (size_t i = 0; i < d; i++) {
		size_t pos = (i + offset) % len;
		int obj = cont[i];
		while (pos!=i) {
			clog << "move " << obj << " from " << (pos-offset+len)%len << " to " << pos << endl;
			swap(obj, cont[pos]);
			pos = (pos + offset) % len;
		}
		cont[i] = obj;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> data; data.reserve(n);
	while (n--) {
		static int t; cin >> t;
		data.push_back(t);
	}
	inplace_moveforward(data, m);
	if (!data.empty()) {
		cout << data.front();
		for (size_t i = 1; i < data.size(); i++) {
			cout << " " << data[i];
		}
	}
}

