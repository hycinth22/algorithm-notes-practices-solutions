// 大整数运算B1017.cpp
//

#include <iostream>
#include <string>
using namespace std;

int devide(string n1, int n2, string& division, int& remainer) {
	if (n2 == 0) return 1;
	if (n2 < 0 || n2 > 9) return 2;
	remainer = 0;
	for (char& c: n1) {
		int t = (c - '0') + remainer * 10;
		remainer = t % n2;
		t /= n2;
		if (t != 0 || division.size() != 0) {
			division.append(1, '0' + t);
		}
	}
	// 注意点，n1为0会导致结果为空
	if (division.empty()) {
		division = "0";
	}
	return 0;
}

int main()
{
	string n1; int n2; cin >> n1 >> n2;
	string q; int r;
	devide(n1, n2, q, r);
	cout << q << " " << r << endl;
}

