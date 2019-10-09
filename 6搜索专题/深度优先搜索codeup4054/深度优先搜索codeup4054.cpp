// 深度优先搜索codeup4054.cpp
//


#include <iostream>
#include <utility>
#include <vector>
#include <array>
using namespace std;

constexpr auto row = 8, col = 8;

vector<vector<bool>> visited(row, vector<bool>(col));
constexpr array<pair<int, int>, 9 > direct = {
	pair<int, int>
	{0, -1}, {0, 1}, {-1, 0}, {1, 0},
	{-1, -1}, {1,-1}, {-1, 1}, {1, 1},
	{0, 0} // 注意题意，也可以原地不动
};

void output(vector<vector<char>>& area) {
	for (auto& l : area) {
		for (auto& d : l) {
			cout << d;
		}
		cout << endl;
	}
	cout << endl;
}

bool dfs(int x, int y, vector<vector<char>> area) {
	//clog << "pos " << " " << x << "," << y << endl;
	//output(area);
	int cntStone = 0;
	bool disableVisited = false; // 为true时visited无效
	if (area[x][y]!='U') // 注意起始时刻，不会进行落石。后面才每开始一轮进行一次落石。
	{
		for (int j = col - 1; j >= 0; j--) {
			if (area.back()[j] == 'S') {
				area.back()[j] = '.';
				disableVisited = true;
			}
		}
		for (int i = row - 2; i >= 0; i--) {
			for (int j = col - 1; j >= 0; j--) {
				if (area[i][j] == 'S') {
					area[i + 1][j] = 'S';
					area[i][j] = '.';
					cntStone++;
					disableVisited = true;
				}
			}
		}
		if (cntStone == 0) { // 石头全部落下以后还没有被砸到，只剩下空格，即一定可以到达，直接返回true。
			return true;
		}
	}
	else {
		area[x][y] = '.'; // 必须将起始点U更新为普通的空格，否则后面原地不动时，判断会漏。
		// 当然，选择修改后面的代码，增加后面判断起始点U也可以。不这么做的原因是，落石也会把起始点U修改为空格. 统一起见，一致将起始点修改为普通空格。
		disableVisited = true; // 由于起始时刻不进行落石，上面的代码无法生效，此处强行禁用visited
	}
	for (auto& dir : direct) {
		int nx = x + dir.first, ny = y + dir.second;
		if (nx >= 0 && nx < row &&
			ny >= 0 && ny < col &&
			(disableVisited || !visited[nx][ny])		// 不要遗漏条件
			) {
			if (area[nx][ny] == 'A') {
				return true;
			}
			if (area[nx][ny] == '.' && 
				(nx==0|| area[nx-1][ny]!='S')
			) {
				// 无石头时才开始使用visited过滤。
				if (cntStone == 0) {
					visited[nx][ny] = true;
				}
				//clog << "move to " << " " << nx << "," << ny ;
				//clog << "from " << " " << x << "," << y << endl;
				if (dfs(nx, ny, area)) {
					visited[nx][ny] = false;
					return true;
				}
				visited[nx][ny] = false;
			}
		}
	}
	return false;
}

int main()
{
	int t; cin >> t;
	pair<int, int> init, tar;
	vector<vector<char>> area(row, vector<char>(col));
	for (int k=1; k<=t; k++) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> area[i][j];
				if (area[i][j] == 'U') {
					init = {i, j};
				}
				else if (area[i][j] == 'A') {
					tar = { i, j };
				}
				else if (area[i][j] == 'S') {
				}
				else if (area[i][j] == '.') {
				}
				else {
					cerr << "unknown input: " << area[i][j] << endl;
				}
			}
		}
		visited[init.first][init.second] = true;
		cout << "Case #" << k << ": " << (dfs(init.first, init.second, area) ? "Yes" : "No") << endl;
		visited[init.first][init.second] = false;
		cin.get(); // 注意有一空行间隔
	}
}

