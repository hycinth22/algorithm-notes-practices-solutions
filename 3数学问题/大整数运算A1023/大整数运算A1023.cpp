// 大整数运算A1023.cpp
//

#include <iostream>
#include <algorithm>
using namespace std;

string myplus(const string& a, string& b) {
	string r;
	auto ia = a.crbegin(), ib = b.crbegin(),
		ae = a.crend(), be = b.crend();
	int carry = 0;
	while (ia != ae && ib != be) {
		int t = (*ia-'0') + (*ib-'0') + carry;
		carry = t / 10;
		t %= 10;
		r.insert(0, 1, '0' + t);
		ia++;
		ib++;
	}
	while (ia != ae) {
		int t = *ia + carry;
		carry = t / 10;
		t %= 10;
		r.insert(0, 1, '0' + t);
	}
	while (ib != be) {
		int t = *ib + carry;
		carry = t / 10;
		t %= 10;
		r.insert(0, 1, '0' + t);
	}
	// 注意点，容易忘记，如果最后还有进位，需要增一位
	if (carry != 0) {
		r.insert(0, 1, '0' + carry);
	}
	return r;
}

int main()
{
	string a, b; 
	cin >> a;
	b = myplus(a, a);
	string sa = a, sb = b;
	sort(sa.begin(), sa.end());
	sort(sb.begin(), sb.end());
	cout << (sa == sb ? "Yes" : "No") << endl
		<< b << endl;
}

