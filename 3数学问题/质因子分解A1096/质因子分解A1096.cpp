// 质因子分解A1096.cpp
//

#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <functional>
using namespace std;

// factors (without 1)
vector<int> factorInConsecutivePrime(int n) {
	if (n <= 1) { return {}; }
	vector<int> r; vector<int> tr;
	for (int i = 2; i <= n; i++) {
		if (n % i == 0) {
			tr.push_back(i);
		}
		else {
			if (tr.size() > r.size() ) {
				int product = accumulate(tr.begin(), tr.end(), 1, multiplies<int>());
				if (product == n) {
					r.swap(tr); // tr = r;
				}
			}
			tr.clear();
		}
	}
	if (tr.size() > r.size()) {
		return tr;
	}
	return r;
}

int main()
{
	int n; cin >> n;
	auto result = factorInConsecutivePrime(n);
	cout << result.size() << endl;
	for (size_t i = 0; i < result.size(); i++) {
		if (i!=0) {
			cout << "*";
		}
		cout << result[i];
	}
	cout << endl;
}

