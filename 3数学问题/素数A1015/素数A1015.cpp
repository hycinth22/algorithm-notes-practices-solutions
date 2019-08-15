// 素数A1015.cpp
//

#include <iostream>
#include <map>
#include <cmath>

using namespace std;

bool isPrime(int m) {
	if (m <= 1) return false;
	int edge = int(sqrt(m)); // 注意边界条件。数学上应该是i<sqrt(m)，但是由于结果取整，小数部分被舍去，需要写成i<=sqrt(m)
	// 同时注意，缓存结果以防止循环中多次重复开方运算。
	for (int i = 2; i <= edge; i++) {
		if (m % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	int n, radix;
	while (cin >> n >> radix) {
		if (n < 0) {
			break;
		}
		bool reprime = false;
		if (isPrime(n)) {
			int reverseN = 0;
			while (n>0) {
				reverseN *= radix;
				reverseN += n % radix;
				n /= radix;
			}
			clog << "reverse is " << reverseN;
			if (isPrime(reverseN)) {
				reprime = true;
			}
		}
		cout << (reprime ? "Yes" : "No") << endl;
	}
}

