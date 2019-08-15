// 质因子分解A1059.cpp
//

#include <iostream>
#include <map>
#include <cmath>
using namespace std;

// factors (without 1, but only 1 when n==1)
map<long, int> factor(long n) {
	if (n <= 1) { return {make_pair(n, 1)}; } // 特判，否则测试点3错误
	map<long, int> r;
	auto edge = long(sqrt(n));
	// 从[2, sqrt(n))尝试分解，
	long i = 2;
	while (i <= edge) {
		// 判断是否是因子
		// 此处不必判断是否是质数，因为从小到大判断，而合数因子的因子总比合数因子小，
		// 因此n的合数因子的所有因子（也由于同样的理由递推都是质数因子）已经在更早的循环中被分解出去，
		// 从而到判断合数因子时，剩余的n必然已经不能被这个合数因子整除。
		// 从而保证得到n的因子结果必然都是质数。
		if (n % i == 0) {
			r[i]++;
			n /= i;
			// 下一轮仍然要判断i, 可能存在多个相同的质因子。
		}
		else {
			i++;
			// 继续尝试更大的数
		}
	}
	// 在[2, sqrt(n)) 还没有分解完，则剩余的一个质因数必然是n自身
	if (n > 1) {
		r[n]++;
	}
	return r;
}

int main()
{
	long n; cin >> n;
	auto result = factor(n);
	bool first = true;
	cout << n << "=";
	for (auto& p : result) {
		if (!first) {
			cout << "*";
		}
		cout << p.first;
		if (p.second > 1) {
			cout << "^" << p.second;
		}
		first = false;
	}
	cout << endl;
}

