// 散列A1041.cpp
//

#include <iostream>
#include <unordered_map>
#include <iterator>
#include <algorithm>
using namespace std;

struct r
{
	int cnt = 0;
	int i;
};

int main()
{
	cin.sync_with_stdio(0);
	unordered_map<int, r> cnt;
	int n; cin >> n;
	for (int i=0; i<n; i++){
		int k; cin >> k;
		cnt[k].i = i;
		++cnt[k].cnt;
	}
	auto p = min_element(cnt.begin(), cnt.end(), [](auto& pa, auto& pb) {
		if (pa.second.cnt != pb.second.cnt) {
			return pa.second.cnt < pb.second.cnt;
		}
		return pa.second.i < pb.second.i;
	});
	if (p == cnt.end() || p->second.cnt != 1) {
		cout << "None" << endl;
	}
	else {
		cout << p->first << endl;
	}
}

