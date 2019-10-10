// 广度优先搜索codeup5997.cpp
//

#include <iostream>
#include <unordered_map>
#include <array>
#include <queue>
#include <utility>
#include <climits>
using namespace std;

typedef pair<size_t, size_t> pos;
struct state{
	typedef long long dhash;
	int step;
	array<array<int, 3>, 3> data;
	pos empty; // index for empty grid
	bool operator==(state& rhs) {
		return data == rhs.data;
	}
	dhash datahash() {
		// 由于不处理哈希冲突，此处编写的hash函数必须保证在所给数据下不会产生哈希冲突。
		constexpr auto dataMaxVal = 9; // 输入数据最大值
		long long hash = 0;
		for (size_t i = 0; i < data.size(); ++i) {
			for (size_t j = 0; j < data[i].size(); ++j) {
				hash = (hash + data[i][j]) % LLONG_MAX;
				hash = (hash * (dataMaxVal+1)) % LLONG_MAX;
			}
		}
		// clog << hash << endl;
		return hash;
	}
};

inline size_t visitedIndex(int i, int j) {
	return i * 3 + j;
}

int bfs(state& init, state& target) {
	constexpr array<pos, 4> direct = {
		pos{-1, 0}, {1, 0}, {0, -1}, {0, 1},
	};
	unordered_map<state::dhash, bool> visited; //注意，visited的对应的是整个矩阵的情况，任一不同则情形都不同，为节省空间，使用hash对应。
	visited[init.datahash()] = true;
	queue<state> q; q.push(init);
	while (!q.empty()) {
		state& s = q.front();
		if (s == target) {
			return s.step;
		}
		for (auto& dir : direct) {
			pos next { s.empty.first + dir.first , s.empty.second + dir.second };
			if (next.first >= 0 && next.first < s.data.size() &&
				next.second >= 0 && next.second < s.data[next.first].size()
				) {
				state nexts = s;
				swap(nexts.data[s.empty.first][s.empty.second], nexts.data[next.first][next.second]);
				if (!visited[nexts.datahash()]) {
					nexts.empty = next;
					nexts.step++;
					q.push(nexts);
					visited[nexts.datahash()] = true;
				}
			}
		}
		q.pop();
	}
	return 0;
}

int main()
{
	state init, target;
	init.step = 1;
	for (size_t i = 0; i < init.data.size(); ++i) {
		for (size_t j = 0; j< init.data[i].size(); ++j) {
			cin >> init.data[i][j];
			if (init.data[i][j] == 0) {
				init.empty = {i, j};
			}
		}
	}
	for (auto& row : target.data) {
		for (auto& data : row) {
			cin >> data;
		}
	}
	cout << bfs(init, target);
}

