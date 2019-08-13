// 最大公约数与最小公倍数codeup1818.cpp
//

#include <iostream>
#include <utility>
using namespace std;

// 辗转相除递归写法
int int_gcd(int a, int b) {
	return b == 0 ? a : int_gcd(b, a%b);
}
// 辗转相除迭代写法
int int_gcd_inplace(int a, int b) {
	while (b != 0) {
		std::swap(a, b);
		b %= a;
	}
	return a;
}
int int_lcm(int a, int b) {
	return a / int_gcd(a, b) * b; // 先除再乘可减少溢出，由于gcd结果是a的约数，必定可整除
}

// stein优化算法 递归写法
int int_stein_gcd(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	if (b % 2 == 0) {
		if (a % 2 == 0) {
			return 2 * int_stein_gcd(a/2, b/2);
		}
		else {
			return int_stein_gcd(a, b / 2);
		}
	}
	else {
		if (a % 2 == 0) {
			return int_stein_gcd(a/2, b);
		}
		else {
			if (a < b) {
				std::swap(a, b);
			}
			return int_stein_gcd(a-b, b);
		}
	}
}
// stein优化算法 迭代写法
int int_stein_gcd_inplace(int a, int b) {
	int k = 1;
	while (a!=0 && b != 0) {
		if (b % 2 == 0) {
			if (a % 2 == 0) {
				k *= 2;
				a /= 2; b /= 2;
			}
			else {
				b /= 2;
			}
		}
		else {
			if (a % 2 == 0) {
				a /= 2;
			}
			else {
				if (a < b) {
					std::swap(a, b);
				}
				a -= b;
			}
		}
	}
	if (a == 0) {
		a = b;
	}
	return a * k;
}

// 迭代写法+模板化版本
template<typename NumType>
NumType gcd(NumType a, NumType b) {
	while (b != 0) {
		std::swap(a, b);
		b %= a;
	}
	return a;
}
template<typename NumType>
NumType lcm(NumType a, NumType b) {
	return a / gcd(a, b) * b;
}

// 模板化版本+迭代写法+采用stein优化版本+乘法替换为位运算的优化版本
template<typename NumType>
NumType stein_gcd(NumType a, NumType b) {
	NumType k = 0;
	while (a!=0 && b != 0) {
		if (b % 2 == 0) {
			if (a % 2 == 0) {
				k++;
				a /= 2; b /= 2;
			}
			else {
				b /= 2;
			}
		}
		else {
			if (a % 2 == 0) {
				a /= 2;
			}
			else {
				if (a < b) {
					std::swap(a, b);
				}
				a -= b;
			}
		}
	}
	if (a == 0) {
		a = b;
	}
	return a<<k; // 等价于a*pow(2,k)
}

#include <iostream>
using namespace std;
int main() {
	long long n, m;
	while (cin >> n >> m) {
		cout << stein_gcd(n, m) << endl;
	}
}


