// map_A1054.cpp
//

#include <iostream>
#include <map>
using namespace std;

using color = long long;
int main()
{
	map<color, size_t> colorCnt;
	int m, n; cin >> m >> n;
	for(int i=0; i<n; i++) {
		for (int j = 0; j < m; j++) {
			static color t; cin >> t;
			colorCnt[t]++;
		}
	}
	if (!colorCnt.empty()) {
		color domi = 0; size_t cnt = 0;
		for (auto& p : colorCnt) {
			if (p.second >= cnt) {
				domi = p.first;
				cnt = p.second;
			}
		}
		cout << domi;
	}
}

