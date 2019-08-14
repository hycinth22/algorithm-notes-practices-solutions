// 分数的四则运算A1081.cpp
//

#include <iostream>
#include <cmath>
using namespace std;

template<class T>
T gcd(T a, T b) {
	return (b == 0) ? a : gcd(b, a % b);
}
template<class T>
T lcm(T a, T b) {
	return a/gcd(a,b)*b;
}

struct rational {
	long long num;
	long long dome;
	const rational& operator+=(const rational& rhs) {
		if (num == 0) {
			num = rhs.num;
			dome = rhs.dome;
			return *this;
		}
		else if (rhs.num == 0){
			return *this;
		}
		auto cd = gcd(abs(num), abs(dome)); // 注意要取绝对值
		// num/dome + rhs.num/rhs.dome
		// -> (num*rhs.dome/gcd)/lcm + ( rhs.num*dome/gcd)/lcm
		num = rhs.dome/cd*num + dome/cd* rhs.num;
		dome = dome/cd * rhs.dome;
		simplify();
		return *this;
	}
	void simplify() {
		auto cd = gcd(abs(num), abs(dome)); // 注意要取绝对值
		num /= cd;
		dome /= cd;
	}
};
istream& operator>>(istream& is, rational& a) {
	is >> a.num;
	if (is.get() != '/') {
		is.setstate(istream::failbit);
	}
	is >> a.dome;
	return is;
}

int main()
{
	int n; cin >> n;
	rational sum{ 0, 0 };
	while (n--) {
		static rational t; cin >> t;
		sum += t;
	}
	sum.simplify();
	long long k = sum.num / sum.dome,
		up = sum.num % sum.dome,
		down = sum.dome;
	bool output = false;
	if (k != 0) {
		cout << k;
		output = true;
	}
	if (up != 0) {
		if (output) {
			cout << " ";
		}
		cout << up << "/" << down;
		output = true;
	}
	if (!output) {
		cout << "0";
	}
}

