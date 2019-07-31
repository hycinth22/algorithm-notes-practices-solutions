// 模拟-64位乘法.cpp
//

#include <iostream>
#include <cstdint>
#include <vector>
using namespace std;

typedef int64_t int64;

vector<int64> mutiply64(int64 a, int64 b) {
	bool positive = true;
	if (a < 0) {
		a = -a;
		positive = !positive;
	}
	if (b < 0) {
		b = -b;
		positive = !positive;
	}
	vector<int64> v(3);
	int64 ah = a >> 32, al= a & (1<<33)-1,
		bh = b >> 32, bl = b & (1 << 33) - 1;
	return v;
}

int main()
{
	int64 a, b;
	while (cin >> a >> b) {
		auto result = mutiply64(a, b);
		for (auto& i : result) {
			cout << i;
		}
		cout << endl;
	}
	
}

