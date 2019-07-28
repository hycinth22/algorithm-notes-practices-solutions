// 贪心A1037.cpp
// 
// 局部最优解：做出一次选择时，同符号中选择价值最高的coupon和价值最高的product收益最高。
// 最优子结构（扩展到多次选择可以构成整体最优解）此处不予证明。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int nc; cin >> nc;
	vector<int> cs(nc);
	for(int&i: cs) {
		cin >> i;
	}
	int np; cin >> np;
	vector<int> ps(np);
	for (int& i : ps) {
		cin >> i;
	}
	sort(cs.begin(), cs.end());
	sort(ps.begin(), ps.end());
	int ans = 0;
	for (int i = 0; i < ps.size() && i < cs.size() && ps[i] < 0 && cs[i] < 0; i++) {
		ans += ps[i] * cs[i];
	}
	reverse(cs.begin(), cs.end());
	reverse(ps.begin(), ps.end());
	for (int i = 0; i < ps.size() && i < cs.size() && ps[i]>0 && cs[i]>0; i++) {
		ans += ps[i] * cs[i];
	}
	cout << ans << endl;
}

