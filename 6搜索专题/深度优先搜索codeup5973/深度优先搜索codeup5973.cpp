// 深度优先搜索codeup5973.cpp
// cid=100000608

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void output(const vector<int>& v) {
	if (!v.empty()) {
		cout << v.front();
		for (size_t i = 1; i < v.size(); i++) {
			cout << " " << v[i];
		}
	}
	cout << endl;
}

vector<int> dataset, subset; int r;
// static: dataset, r
// dynamic: i for subset filling, j for dataset start, subset
void dfs(int i, int j) {
	if (i == r) {
		output(subset);
		return;
	}
	for (int ci = j; ci < dataset.size(); ci++) {
		subset[i] = dataset[ci];
		dfs(i + 1, ci+1);
	}
}
void search(vector<int>& v, int p_r) {
	r = p_r;
	dataset = v;
	subset.resize(r);
	dfs(0, 0);
}

int main()
{
	int n, r; cin >> n >> r;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}
	sort(v.begin(), v.end());
	search(v, r);
}


