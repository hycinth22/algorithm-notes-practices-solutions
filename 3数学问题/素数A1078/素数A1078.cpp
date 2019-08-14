// 素数A1078.cpp
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;

template<typename NumType = unsigned long long>
struct primetable {
	map<NumType, bool> filter; // Eratosthenes筛法, true代表已判断不是素数
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
				for (NumType j = i * 2; j <= n; j += i) {
					filter[j] = true;
				}
			}
		}
	}
	void clear() {
		filter.clear();
	}
	bool isPrime(NumType n) {
		return !filter[n];
	}
};

int main()
{
	primetable<> t; t.findUtil(10000);

	int msize, n; cin >> msize >> n;
	while (!t.isPrime(msize)) {
		msize++;
	}

	vector<bool> posFlag(msize, false);
	vector<int> pos(msize, -1);
	for (size_t i = 0; i < n; i++) {
		static int t, hash;
		cin >> t; hash = t % msize;
		int step = 1;
		int finalhash = hash;
		while (posFlag[finalhash]) {
			finalhash = (hash + step * step) % msize; // 注意二次探查法的写法，是从原位置逐次查找0^2, 1^2, 2^2..., k^2
			if (finalhash == hash) {
				pos[i] = -1; // impossible to insert
				goto next;
			}
			step++;
		}
		posFlag[finalhash] = true;
		pos[i] = finalhash;
	next:
		continue;
	}
	if (!pos.empty()) {
		cout << (pos.front()!=-1? pos.front():'-');
		for (size_t i = 1; i < n; i++) {
			cout << " " << pos[i];
		}
	}
}

