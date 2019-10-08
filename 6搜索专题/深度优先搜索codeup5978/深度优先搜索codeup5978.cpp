// 深度优先搜索codeup5978.cpp
//

/*
注意，题目描述中的剪枝方法是错的。
4 4
0 1 0 0
0 1 0 0
0 1 0 1
0 1 1 1
1 2
3 4

起点（1，2）到终点（3，4）的矩形
1 0 0
1 0 0
1 0 1
有一列为0，但有一解
(1,2)->(2,2)->(3,2)->(4,2)->(4,3)->(4,4)->(3,4)
https://blog.csdn.net/a845717607/article/details/81324163
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <list>
#include <utility>
using namespace std;

int n, m;
vector<vector<int>> area;
vector<vector<bool>> visited; // 路径的搜索，一定记住要处理环状路径搜索的死循环。即是否访问过。
list<pair<int, int>> path;
pair<int, int> init, target;
const array<pair<int, int>, 4> direction = {
	pair<int, int>{0, -1},
	pair<int, int>{-1, 0},
	pair<int, int>{0, 1},
	pair<int, int>{1, 0},
};
bool hassolu = false;
// 静态量：area n,m init,target direction
// 动态量：visited path
// 需自行维护状态的：visited path
void dfs(pair<int, int>& pos) {
	path.push_back(pos);
	if (pos == target) {
		auto it = path.cbegin(), end = path.cend();
		printf("(%d,%d)", it->first, it->second);
		++it;
		for (; it != end; ++it) {
			printf("->(%d,%d)", it->first, it->second);
		}
		printf("\n");
		hassolu = true;
	}
	else {
		//printf("(%d,%d)", pos.first, pos.second);
		for (auto& dir : direction) {
			auto next = pos;
			next.first += dir.first;
			next.second += dir.second;
			if (next.first >= 1 && next.first <= n
				&& next.second >= 1 && next.second <= m
				&& area[next.first][next.second]==1  // 记得判断题目条件是否可访问
				&& !visited[next.first][next.second] // 记得判断是否访问过
				) {
				visited[next.first][next.second] = true;
				dfs(next);
				visited[next.first][next.second] = false;
			}
		}
	}
	path.pop_back();
}

int main()
{
	cin.sync_with_stdio(false); cout.sync_with_stdio(false);
	cin >> n >> m;
	area.resize(n+1, vector<int>(m + 1, -1));
	visited.resize(n + 1, vector<bool>(m + 1, false));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> area[i][j];
		}
	}
	cin >> init.first >> init.second
		>> target.first >> target.second;
	visited[init.first][init.second] = true; // 记得起始点也要设置
	pair<int, int> pos(init);
	dfs(init);
	if (!hassolu) {
		printf("-1");
	}
}

