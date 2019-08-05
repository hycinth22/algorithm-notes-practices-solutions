// 二分-快速幂.cpp
//

#include <iostream>
#include <limits>
using namespace std;

template<typename numType = int, typename powType = int>
int binaryPow(numType n, powType p, numType m = numeric_limits<int>::max()) {
	if (p == 1) return n;
	if (p % 2 == 1) {
		return n * binaryPow(n, p-1, m) % m;
	}
	numType r = binaryPow(n, p/2, m);
	return r * r %m;
}

int main()
{
	int n, p, m;
	while (cin >> n >> p >> m) {
		cout << binaryPow(n, p, m) << endl;
	}
}

