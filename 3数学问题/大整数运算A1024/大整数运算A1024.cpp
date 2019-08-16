// 大整数运算A1024.cpp
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string bigPlus(const string& a, const string& b) {
	string r;
	int carry = 0;
	auto ia = a.crbegin(), ib = b.crbegin(),
		ae = a.crend(), be = b.crend();
	while (ia!=ae&&ib!=be) {
		int t = (*ia - '0') + (*ib - '0') + carry;
		carry = t / 10;
		t %= 10;
		r.insert(0, 1, '0'+t);
		ia++;
		ib++;
	}
	while (ia != ae) {
		int t = (*ia - '0') + carry;
		carry = t / 10;
		t %= 10;
		r.insert(0, 1, '0' + t);
		ia++;
	}
	while (ib != be) {
		int t = (*ib - '0') + carry;
		carry = t / 10;
		t %= 10;
		r.insert(0, 1, '0' + t);
		ib++;
	}
	if (carry != 0) {
		r.insert(0, 1, '0' + carry);
	}
	return r;
}

bool is(const string& a) {
	size_t  i= 0, j = a.size()-1;
	while (i < j) {
		if (a[i] != a[j]) {
			return false;
		}
		j--;
		i++;
	}
	return true;
}

int main()
{
	string n; cin >> n;
	int cnt = 0, k; cin >> k;
	while (cnt<k &&!is(n)) {
		string re = n; reverse(re.begin(), re.end());
		n = bigPlus(n, re);
		cnt++;
	}
	cout << n << endl
		<< cnt << endl;
}

