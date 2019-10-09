// 广度优先搜索codeup2078.cpp
// 未AC。题目描述似乎不清楚。
// 我在此希望输出最短路径最优解，并手动验算了是一个可行解。
// 而测试用例给出的结果步数更多。

/*

8 11 7
fill A		8 0
pour A B	0 8
fill A		8 8
pour A B	5 11
empty B		5 0
pour A B	0 5
fill A      8 5
pour A B	2 6
empty B		2 0
pour A B	0 2
fill A		8 2
pour A B	0 10
fill A		8 10
pour A B	7 11
empty B		7 0
pour A B	0 7
success
16步

测试用例解为
fill B
pour B A
empty A
pour B A
fill B
pour B A
empty A
pour B A
fill B
pour B A
empty A
pour B A
empty A
pour B A
fill B
pour B A
empty A
pour B A
fill B
pour B A
success
20步
*/


#include <iostream>
#include <map>
#include <queue>
#include <utility>
#include <tuple>
#include <cmath>
#include <string>
using namespace std;

// BFS保证了首先找到的一定是最短路径，同时也保证了时间效率。

// (1) you can fill a jug,
// (2) you can empty a jug, 
// (3) you can pour from one jug to the other.
void bfs(int ca, int cb, int goal) {
	queue< tuple<int, int, queue<const char*> > > q;
	map<pair<int, int>, bool> visited; // 重要，否则大量的重复情况是不可接受的时间消耗。
	q.emplace(0, 0, queue<const char*>());
	visited[make_pair<>(0, 0)] = true; // 不要忘记为初始点设置visited
	while (!q.empty()) {
		auto state = q.front(); q.pop();
		int &sa = get<0>(state), &sb = get<1>(state);
		queue<const char*>& spath = get<2>(state);
		if (sa == goal && sb == goal) {
			while (!spath.empty()) {
				cout << spath.front() << endl;
				spath.pop();
			}
			cout << "success\n";
			return;
		}
		static auto tryTrans = [&](int na, int nb, const char* name) {
			if (visited[make_pair<>(na, nb)]) {
				return;
			}
			q.emplace(na, nb, spath);
			get<2>(q.back()).emplace(name);
			visited[make_pair<>(na, nb)] = true;
		};
		if (sa < ca)
		{
			tryTrans(ca, sb, "fill A");
		}
		if (sb < cb)
		{
			tryTrans(sa, cb, "fill B");
		}
		if (sa > 0)
		{
			tryTrans(0, sb, "empty A");
		}
		if (sb > 0)
		{
			tryTrans(sa, 0, "empty B");
		}
		if (sa > 0 && sb < cb)
		{
			int transfer = min(sa, cb - sb);
			tryTrans(sa - transfer, sb + transfer, "pour A B");
		}
		if (sa < ca && sb > 0) {
			int transfer = min(sb, ca - sa);
			tryTrans(sa + transfer, sb - transfer, "pour B A");
		}
	}
}

int main()
{
	cout.sync_with_stdio(0);
	int ca, cb, n;
	while (cin >> ca >> cb >> n) {
		bfs(ca, cb, n);
	}
}

