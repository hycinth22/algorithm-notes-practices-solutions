// 进制转换A1027.cpp
//

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

inline char charTransform(int single) {
	if (single >= 0 && single <= 9) {
		return '0' + single;
	}
	if (single >= 10 && single <= 35) {
		return 'A' + (single-10); // 注意减掉10
	}
	return '#';
}

string int2str(int num, int base) {
	if (base <= 1) return "";
	// 计算num在base进制下的长度：len=floor(log base num)+1 （num>0）
	// 要用floor(x)+1，不能直接ceil(x)，整数的情况下也需要多一位
	int len;
	if (num != 0) {
		len = (int)floor(log(num) / log(base)) + 1; // floor(log base num)+1
	}
	else {
		len = 1;
	}
	string dsum(len, '0');
	int i = len - 1;
	while (i >= 0) {
		dsum[i] = charTransform(num % base);
		num /= base;
		i--;
	}
	return dsum;
}

int main()
{
	int a, b,c ; cin >> a >> b >> c;
	const int base = 13;
	cout << setfill('0');
	cout << "#" 
		<< setw(2) << int2str(a, base)
		<< setw(2) << int2str(b, base)
		<< setw(2)  << int2str(c, base);
	// 注意补足2位
}


