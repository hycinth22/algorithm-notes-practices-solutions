// 广度优先搜索A1091.cpp
//

#include <cstdio>
#include <queue>
#include <vector>
#include <array>
#include <iostream>

using namespace std;

using pos = array<int, 3>;

vector<vector<vector<bool>> > visited;
int volumeAt(int x, int y, int z, int l, int m, int n, const vector<vector<vector<int>> >& slices) {
	queue<pos> q; q.push({x, y, z}); visited[x][y][z] = true;
	constexpr array<pos, 6> directions = {
		pos
		{1, 0, 0}, {-1, 0, 0},
		{0, 1, 0}, {0, -1, 0},
		{0, 0, 1}, {0, 0, -1},
	};
	int volume = 0;
	while (!q.empty()) {
		pos& p = q.front();
		volume++;
		for (auto & dir: directions) {
			pos np { p[0]+dir[0], p[1]+dir[1], p[2]+dir[2] };
			if (np[0] >= 0 && np[0] < l &&
				np[1] >= 0 && np[1] < m &&
				np[2] >= 0 && np[2] < n &&
				slices[np[0]][np[1]][np[2]] == 1 &&
				!visited[np[0]][np[1]][np[2]]
				) {
				q.push({np[0], np[1], np[2]});
				visited[np[0]][np[1]][np[2]] = true;
			}
		}
		q.pop();
	}
	clog << "volume " << volume << " at " << x << " " << y << " " << z << endl;
	return volume;
}

int totalVolume(int l, int m, int n, int t, const vector<vector<vector<int>> >& slices) {
	int total = 0;
	visited.clear();
	visited.resize(l, vector<vector<bool>>(m, vector<bool>(n, false)));
	for (int i1 = 0; i1 < l; i1++) {
		for (int i2 = 0; i2 < m; i2++) {
			for (int i3 = 0; i3 < n; i3++) {
				if (slices[i1][i2][i3]==1 && !visited[i1][i2][i3]) {
					int volume = volumeAt(i1, i2, i3, l, m, n, slices);
					if (volume >= t) {
						total += volume;
					}
					else {
						clog << "less than t" << endl;
					}
				}
			}
		}
	}
	return total;
}

int main()
{
	int m, n, l, t;
	scanf("%d %d %d %d", &m, &n, &l, &t);
	vector<vector<vector<int>> > slices(l, vector<vector<int>>(m, vector<int>(n, 0)));
	for (int i1 = 0; i1 < l; i1++) {
		for (int i2 = 0; i2 < m; i2++) {
			for (int i3 = 0; i3 < n; i3++) {
				scanf("%d", &slices[i1][i2][i3]);
			}
		}
	}
	printf("%d", totalVolume(l, m, n, t, slices));
}

