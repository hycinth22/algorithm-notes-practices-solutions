// 广度优先搜索codeup5999.cpp
//

#include <iostream>
#include <queue>
#include <array>
#include <unordered_map>
using namespace std;

using state = array<int, 3>;
constexpr auto maxVal = 100;
int hash(state& s) {
	return s[0] * (maxVal + 1) * (maxVal + 1) + s[1] * (maxVal + 1) + s[2];
}

int bfs(const state& full, int k) {
	struct bfsinfo {
		state s;
		int step;
	};
	queue<bfsinfo> q; q.push({ {full[0], 0, 0}, 0 });
	unordered_map<int, bool> visited;

	while (!q.empty()) {
		bfsinfo& si = q.front();
		state& s = si.s;
		if (s[0] == k || s[1] == k || s[2] == k) {
			return si.step;
		}
		// pour form i into j
		for (size_t i = 0; i < s.size(); ++i) {
			for (size_t j = 0; j < s.size(); ++j) {
				if (i != j && s[i]>0 && s[j]<full[j]) {
					state ns = s;
					int amount = min(s[i], full[j]-s[j]);
					ns[i] -= amount;
					ns[j] += amount;
					int statehash = ::hash(ns);
					if (!visited[statehash]) {
						q.push({move(ns), si.step+1});
						visited[statehash] = true;
					}
				}
			}
		}
		q.pop();
	}
	return -1;
}

int main()
{
	int a, b, c, k;
	while (cin >> a >> b >> c >> k) {
		int s = bfs({ a, b, c }, k);
		if (s != -1) {
			cout << "yes\n" << s << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
}

