// set_A1063.cpp
//

#include <iostream>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

double similarity(const set<int>&a , const set<int>& b) {
	size_t nc = 0, nt = 0;
	for (auto& i : a) {
		if (b.count(i)) {
			nc++;
		}
		else {
			nt++;
		}
	}
	nt += b.size();
	return double(nc) / double(nt);
}

int main()
{
	int n; cin >> n;
	vector< set<int> > sets(n);
	for (int i = 0; i < n; i++) {
		static int m; cin >> m;
		for (int j = 0; j < m; j++) {
			static int k; cin >> k;
			sets[i].insert(k);
		}
	}
	int k; cin >> k;
	for (int i = 0; i < k; i++) {
		int a, b; cin >> a >> b;
		double s = similarity(sets[a - 1], sets[b - 1]);
		cout << fixed << setprecision(1) << s*100 << "%" << endl;
		// printf("%.1f%%\n", s*100);
	}
}

