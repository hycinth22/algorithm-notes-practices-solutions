// 深度优先搜索codeup5976.cpp
// cid=100000608

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

inline bool noconflict(vector<pair<int, int>> placed, pair<int, int> pos) {
	for (auto& ep: placed) {
		if (ep.first == pos.first || ep.second == pos.second) {
			return false;
		}
		// 判断斜线：|y1-y2| / |x1-x2| = tan 45° = 1
		if ( abs(ep.second- pos.second) == abs(ep.first - pos.first)) {
			return false;
		}
	}
	return true;
}

void output(vector<pair<int, int>>& selected) {
	if (!selected.empty()) {
		cout << selected.front().second+1;
		for (size_t i = 1; i < selected.size(); i++) {
			cout << " " << selected[i].second+1;
		}
	}
	cout << endl;
}

// 静态量：n
// 动态量：s（棋盘） i（放置皇后索引， 也是行索引，上限为n），selected（已放置的皇后位置，用来判断放置下一个是否冲突）
int n, cnt;
void dfs(int i, vector<vector<int>>& s, vector<pair<int, int>>& selected) {
	if (i >= n) {
		cnt++;
		output(selected);
		return;
	}
	for (int k = 0; k < n; k++) {
		if (s[i][k] == 0 && noconflict(selected, make_pair<>(i, k))) {
			s[i][k] = 1;
			selected.push_back(make_pair<>(i, k));
			dfs(i + 1, s, selected);
			s[i][k] = 0;
			selected.pop_back();
		}
	}
}

int search(int n_) {
	n = n_;
	cnt = 0;
	vector<vector<int>> s(n, vector<int>(n, 0));
	vector<pair<int, int>> sel;
	dfs(0, s, sel);
	if (cnt == 0) {
		cout << "no solute!" << endl;
	}
	return cnt;
}

int main()
{
	cout.sync_with_stdio(0);
	int n; cin >> n;
	search(n);
}

