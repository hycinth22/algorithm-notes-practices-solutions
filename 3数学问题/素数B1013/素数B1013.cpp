// 素数B1013.cpp
// 素数表方法适用于对某一段密集的素数进行处理，要运算的素数间有关联。
// 如此题需要输出的素数是按素数序号进行输出，可以减少验证素数的重复计算。
// 缺点是要必须得知输入最大的数字，以及如果不使用bit表（bitset或vector<bool>）可能占用过多空间。
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Eratosthenes筛法创建素数表
template<typename NumType>
struct primetable {
	vector<NumType> primes;
	primetable(NumType maxN) {
		generate(maxN);
	}
	void generate(NumType maxN) {
		primes.clear();
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
	int n, m; cin >> m >> n;
	primetable<unsigned long long> t(0);
	// 题目只给出了要求第几个素数，而我无法得知第n个素数在什么数值范围，
	// 此处自动探查扩增素数表，即使这样会造成少量重复运算，仍然比逐个判断高效太多。
	{
		int maxN = 10000; //初值
		while (t.size() < n) {
			maxN *= 30; // 30为底的指数扩增
			t.generate(maxN);
		}
	}

	for (int i = m; i <= n; i++) {
		cout << t[i-1];
		if ((i - m + 1) % 10 == 0) {
			cout << endl;
		}
		else if (i!=n){
			cout << " ";
		}
	}
}

