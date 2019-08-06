// 散列A1048.cpp
//

#include <iostream>
#include <map>
using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	int nCoins, pay; cin >> nCoins >> pay;
	map<int, int> cnt; // 使用map（红黑树）降低查找时间，此处使用散列表或者二分查找也可以。
	while (nCoins--) {
		static int par; cin >> par;
		++cnt[par];
	}
	bool nosolu = true;
	for (const pair<int, int>& p : cnt) {
		int par = p.first;
		if (par > pay) {
			break;
		}
		int opar = pay - par;
		if (par == opar) {
			if (cnt[par] >= 2) {
				nosolu = false;
				cout << par << " " << par << endl;
				break;
			}
		}
		else {
			if (cnt.count(opar) && cnt[opar] >= 1) {
				nosolu = false;
				cout << par << " " << opar << endl;
				break;
			}
		}
	}
	if (nosolu) {
		cout << "No Solution" << endl;
	}
}

