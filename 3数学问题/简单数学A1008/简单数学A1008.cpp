// 简单数学A1008.cpp
//

#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	int cur = 0, ans = 0;
	while (n--) {
		static int f;
		cin >> f;
		if (f > cur) {
			ans += 6 * (f - cur);
		}
		else if (f < cur) {
			ans += 4 * (cur - f);
		}
		cur = f;
		ans += 5;
	}
	cout << ans;
}

