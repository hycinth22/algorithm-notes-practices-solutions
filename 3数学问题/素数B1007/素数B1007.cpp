// 素数B1007.cpp
//

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
