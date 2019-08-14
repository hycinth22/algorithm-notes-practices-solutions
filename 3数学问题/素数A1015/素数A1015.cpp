// 素数A1015.cpp
//

#include <iostream>
#include <map>

using namespace std;

template<typename NumType = unsigned long long>
struct primetable {
	// vector<NumType> primes;
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
				// primes.push_back(i);
				for (NumType j = i*2; j <= n; j += i) {
					filter[j] = true;
				}
			}
		}
	}
	void clear() {
		// primes.clear();
		filter.clear();
	}
	bool isPrime(NumType n) {
		return !filter[n];
	}
};


int main()
{
	primetable<> t;
	t.findUtil(100000);
	int n, radix;
	while (cin >> n >> radix) {
		if (n < 0) {
			break;
		}
		bool reprime = false;
		if (t.isPrime(n)) {
			int reverseN = 0;
			while (n>0) {
				reverseN *= radix;
				reverseN += n % radix;
				n /= radix;
			}
			clog << "reverse is " << reverseN;
			if (t.isPrime(reverseN)) {
				reprime = true;
			}
		}
		cout << (reprime ? "Yes" : "No") << endl;
	}
}

