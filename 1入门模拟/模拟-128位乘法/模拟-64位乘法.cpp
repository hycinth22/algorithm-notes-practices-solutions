// 模拟-64位乘法.cpp
// （支持运算结果超出64位）
// 输入有符号64位[-2^63, 2^63-1]（1位符号位），结果有符号[-2^126, 2^125]（1位符号位）。
// 输入无符号64位[0, 2^64-1]，结果无符号127位半[0, 2^127]。
// TODO: 输入数据无符号达到2^63(9223372036854775808)以后，计算结果仍然有问题
// 有符号也有类似问题，而且范围更小一些。
// 
// test case: 2*2=4
// test case: 6*6=36
// test case: 6*-6=-36
// test case: 0*2147483648=0‬‬
// test case: 9999999*9999999=99999980000001‬
// test case: 2147483647*2147483647=‬4611686014132420609
// test case: 2147483648*2147483648=4611686018427387904‬
// test case: 4294967296*4294967295=18446744069414584320
// test case: 17179869184*17179869184=295147905179352825856
// test case: 1099511627776L* 1099511627776L= 1208925819614629174706176L
// test case: 35184372088832L* 35184372088832L= 1237940039285380274899124224L
// test case: 70368744177664L * 70368744177664L=4951760157141521099596496896L
// test case: 140737488355328L * 140737488355328L=19807040628566084398385987584L
// test case: 4611686018427387904*4611686018427387904=21267647932558653966460912964485513216
// test case: 9223372036854775807*9223372036854775807=85070591730234615847396907784232501249
// test case: 9223372036854775808L*9223372036854775808L=85070591730234615865843651857942052864L

#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
using namespace std;

typedef int64_t int64;
typedef uint64_t uint64;

template<typename T>
struct BigIntResult {
	BigIntResult(const vector<T>& v) 
		: data(v)
	{}
	BigIntResult(vector<T>&& v)
		: data(forward<vector<T>>(v))
	{}
	string toString(size_t base = 10) {
		constexpr const size_t lowBitSize = sizeof(T) * 4; // 1/2 bits of T
		auto tdata(data); string result; bool negetive = false;
		if (tdata.empty()) return result;
		if (tdata.front() < 0) {
			tdata.front() = -tdata.front();
			negetive = true;
		}
		// todo: the following util return
		while (!tdata.empty()) {
			T remain = 0;
			for (size_t i = 0; i < tdata.size(); i++) {
				tdata[i] += remain << lowBitSize;
				remain = tdata[i] % base;
				tdata[i] /= base;
			}
			result.insert(0, 1, util_transIntToChar(remain));
			auto zeroBegin = tdata.begin(), zeroEnd = zeroBegin;
			while (zeroEnd != tdata.end() && *zeroEnd == 0) {
				zeroEnd++;
			}
			tdata.erase(zeroBegin, zeroEnd);
		}
		if (negetive) {
			result.insert(0, 1, '-');
		}
		return result;
	}
private:
	vector<T> data;
	char util_transIntToChar(const unsigned int &i) {
		if (i >= 0 && i <= 9) {
			return i + '0';
		}
		if (i >= 10 && i <= 35) {
			return 'A' + (i-10);
		}
		return '#';
	}
};
template<typename T>
BigIntResult<T> mutiply(T a, T b) {
	constexpr const size_t lowBitSize = sizeof(T) * 4; // 1/2 bits of T
	bool positive = true;
	if (a < 0) {
		a = -a;
		positive = !positive;
	}
	if (b < 0) {
		b = -b;
		positive = !positive;
	}
	vector<T> v(3);
	constexpr const T lowMask = (static_cast<decltype(lowMask)>(1) << lowBitSize) - 1;
	T ah = a >> lowBitSize, al = a & lowMask,
		bh = b >> lowBitSize, bl = b & lowMask
		, carry;
	v[2] = al * bl;
	carry = v[2] >> lowBitSize; v[2] &= lowMask;
	v[1] = ah * bl + al*bh + carry;
	carry = v[1] >> lowBitSize; v[1] &= lowMask;
	v[0] = ah*bh + carry;  //v[0] &= lowMask;
	auto zeroBegin = v.begin(), zeroEnd = zeroBegin;
	while (zeroEnd != v.end() && *zeroEnd==0) {
		zeroEnd++;
	}
	v.erase(zeroBegin, zeroEnd);
	if (v.empty()) {
		return BigIntResult<T>({ 0 });
	}
	if (!positive) {
		v[0] = -v[0];
	}

	return BigIntResult<T>(v);
}

int main()
{
	uint64 a, b;
	while (scanf("%lld%lld", &a, &b)) {
		auto result = mutiply(a, b);
		cout << result.toString() << endl;
	}

}

