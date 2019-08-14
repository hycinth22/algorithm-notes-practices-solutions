// 分数的四则运算B1034_A1088.cpp
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
	return a / gcd(a, b) * b;
}

struct rational {
	long long symbol = 1, num, dome; // 注意，初始化/一旦改变值，时刻保持分数最简化
	rational() = default;
	rational(long long symbol, long long num, long long dome)
		: symbol(symbol), num(num), dome(dome)
	{ simplify(); }
	const rational operator+(const rational& rhs) {
		auto lcmv = lcm(dome, rhs.dome);
		auto rn = symbol * num * (lcmv/dome) + rhs.symbol * rhs.num * (lcmv/rhs.dome);
		return { (rn >= 0 ? 1 : -1), abs(rn), lcmv };
	}
	const rational operator-(const rational& rhs) {
		return operator+(rational{ -rhs.symbol, rhs.num, rhs.dome }); // 加上相反数
	}
	const rational operator*(const rational& rhs) {
		return { symbol * rhs.symbol, num * rhs.num, dome * rhs.dome };
	}
	const rational operator/(const rational& rhs) {
		return operator*(rational{ rhs.symbol, rhs.dome, rhs.num }); // 乘以倒数
	}
	void simplify() {
		dome = abs(dome); num = abs(num);
		if (dome!=0) {
			auto cd = gcd(num, dome);
			num /= cd; dome /= cd;
		}
	}
};
istream& operator>>(istream& is, rational& a) {
	is >> a.num;
	a.symbol = (a.num >= 0 ? 1 : -1);
	a.num = abs(a.num);
	if (is.get() != '/') {
		is.setstate(istream::failbit);
	}
	is >> a.dome;
	a.dome = abs(a.dome);
	a.simplify(); // ！！！注意：输入即要约分。因为输出算式就必须约分式，另外不约分也会导致算术溢出。否则将导致测试点2不通过。
	return is;
}

ostream& operator<<(ostream& os, const rational& a) {
	if (a.dome == 0) {
		os << "Inf";
		return os;
	}
	if (a.num == 0) {
		os << "0";
		return os;
	}
	long long k = a.num / a.dome, 
		up = a.num % a.dome,down = a.dome;
	if (a.symbol < 0) {
		cout << "(-";
	}
	if (k != 0) {
		os << k;
		if (up != 0) {
			os << " " << up << "/" << down;
		}
	}
	else{
		os << up << "/" << down;
	}
	if (a.symbol < 0) {
		cout << ")";
	}
	return os;
}

int main()
{
	rational a, b;
	cin >> a >> b;
	rational plus = a + b, minus = a - b,
		mutilply = a * b, divide = a / b;
	cout << a << " + " << b << " = " << plus << endl
		<< a << " - " << b << " = " << minus << endl
		<< a << " * " << b << " = " << mutilply << endl
		<< a << " / " << b << " = " << divide << endl;
}


