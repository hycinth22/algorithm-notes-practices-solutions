// 素数B1013.cpp
// 素数表方法适用于对某一段密集的素数进行处理，要运算的素数间有关联。
// 如此题需要输出的素数是按素数序号进行输出，可以减少验证素数的重复计算。
// 缺点是要必须得知输入最大的数字，以及如果不使用bit表（bitset或vector<bool>）可能占用过多空间。

#include <iostream>
#include <vector>
using namespace std;


template<typename NumType = unsigned long long>
struct primetable{
	vector<NumType> primes;
	vector<bool> filter; //	Eratosthenes筛法, true代表已判断不是素数
	// TODO: 不完善的地方。 
	// 题目只给出了要求第几个素数，而我无法得知第n个素数在什么数值范围，
	// 因而此处需要手动调maxN（最大能判断出的素数大小），数值越大，消耗内存和分配相应内存时间也越大
	template<NumType maxN = 10000000>
	void findNth(size_t n) {
		if (n < primes.size()) {
			return;
		}
		clear();
		filter = { true, true, false }; // neither 0 or 1 is not a prime. 2 is a prime 
		filter.resize(maxN);
		for (NumType i = 2; primes.size()<n; i++) {
			if (!filter[i]) {
				primes.push_back(i);
				for (NumType j = i*2; j < maxN; j+=i) {
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
	int n, m; cin >> m >> n;
	primetable<> t;
	t.findNth(n);
	for (size_t i = m; i <= n; i++) {
		cout << t.primes[i-1];
		if ((i - m + 1) % 10 == 0) {
			cout << endl;
		}
		else if (i!=n){
			cout << " ";
		}
	}
}

