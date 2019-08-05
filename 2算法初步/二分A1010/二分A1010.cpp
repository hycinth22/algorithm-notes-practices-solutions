// 二分A1010.cpp
/*
8 1000 1 10 2 
8 1000 2 2 9
8 1000 2 3
1s 1000000 1 36 2
1s 1000000000 2 10 999999972
1s 1000000001 2 10 999999973
1as 1000000001 2 10
0 0 1 100 1
1 0 1 100
11 4 2 100 3
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 注意base不仅仅是[2, 36]，更大的值此题中也是合法的。
long long parseLongLong(const string& str, long long base) {
	long long result = 0;
	long long weight = 1;
	for (auto it = str.crbegin(); it != str.crend(); it++) {
		long long t;
		if (isdigit(*it)) {
			t = *it - '0';
		}
		else {
			t = 10 + (*it - 'a');
		}
		result += t * weight;
		weight *= base;
	}
	return result;
}

long long searchRadix(const string& unk, const long long& k) {
	long long l, r;
	char maxChar = *max_element(unk.begin(), unk.end());
	l = (isdigit(maxChar) ? maxChar - '0' : maxChar - 'a' + 10) + 1;
	if (l < 2) {
		l = 2;
	}
	r = max(l, k);
	long long result = 0;
	while (l <= r) { // 注意此处要写等号
		long long mid = (l + r) / 2;
		long long unk_t = parseLongLong(unk, mid);
		if (unk_t == k) {
			result = mid;
			break;
		}
		// 注意可能溢出，判断方法：<0
		if (unk_t<0 || unk_t > k) {
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return result;
}

int main()
{
	string n1, n2; long long tag, radix;
	cin >> n1 >> n2 >> tag >> radix;
	long long resultRadix;
	if (tag == 1) {
		resultRadix = searchRadix(n2, parseLongLong(n1, radix));
	}
	else {
		resultRadix = searchRadix(n1, parseLongLong(n2, radix));
	}
	if (resultRadix!=0) {
		cout << resultRadix << endl;
	}
	else {
		cout << "Impossible" << endl;
	}
	
}

