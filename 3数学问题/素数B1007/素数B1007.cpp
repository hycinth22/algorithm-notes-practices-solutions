// 素数B1007.cpp
// 素数表方法适用于对某一段密集的素数进行处理，要运算的素数间有关联。
// 如此题需要输出的素数是相邻素数间处理，可以减少验证素数的重复计算。
// 缺点是要必须得知输入最大的数字，以及如果不使用bit表（bitset或vector<bool>）可能占用过多空间。

#include <iostream>
#include <vector>
#include <map>
using namespace std;

template<typename NumType = unsigned long long>
struct primetable {
	vector<NumType> primes;
	map<NumType, bool> filter; //	Eratosthenes筛法, true代表已判断不是素数
	void findUtil(NumType n) {
		if (n < filter.size()) {
			return;
		}
		clear();
		// neither 0 or 1 is not a prime. 2 is a prime .
		filter[0] = true;
		filter[1] = true;
		filter[2] = false;
		for (NumType i = 2; i <= n; i++) {
			if (!filter[i]) {
				primes.push_back(i);
				for (NumType j = i*2; j <= n; j += i) {
					filter[j] = true;
				}
			}
		}
	}
	void clear() {
		primes.clear();
		filter.clear();
	}
};

int main()
{

	int n; cin >> n;
	primetable<> t;
	t.findUtil(n);
	int ans = 0;
	for (size_t i = 1; i < t.primes.size(); i++) {
		if (t.primes[i] - t.primes[i - 1] == 2) {
			ans++;
		}
	}
	cout << ans << endl;
}
