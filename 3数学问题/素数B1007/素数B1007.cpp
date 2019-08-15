// 素数B1007.cpp
// 素数表方法适用于对某一段密集的素数进行处理，要运算的素数间有关联。
// 如此题需要输出的素数是相邻素数间处理，可以减少验证素数的重复计算。
// 缺点是要必须得知输入最大的数字，以及如果不使用bit表（bitset或vector<bool>）可能占用过多空间。

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Eratosthenes筛法创建素数表
template<typename NumType>
struct primetable {
	vector<NumType> primes;
	primetable(NumType maxN) {
		vector<bool> isPrime{ false, false, true }; // neither 0 or 1 is not a prime. 2 is a prime .
		isPrime.resize(maxN + 1, true); // zero also need a space
		for (NumType i = 2; i <= maxN; i++) {
			if (isPrime[i]) {
				primes.push_back(i);
				for (NumType j = 2 * i; j <= maxN; j += i) {
					isPrime[j] = false;
				}
			}
		}
	}
	NumType operator[](size_t index) const {
		return primes[index];
	}
	size_t size() const {
		return primes.size();
	}
};

int main()
{

	int n; cin >> n;
	primetable<int> t(n);
	int ans = 0;
	for (size_t i = 1; i < t.size(); i++) {
		if (t[i] - t[i - 1] == 2) {
			ans++;
		}
	}
	cout << ans << endl;
}
