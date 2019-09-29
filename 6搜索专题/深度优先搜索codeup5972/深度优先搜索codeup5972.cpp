// 深度优先搜索codeup5972.cpp
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

// 静态量：n 范围上限（范围[1, n]）
// 动态量：ans 当前的全排列，i当前处理的第i位数索引
int n;
void dfs(int i, vector<int> ans) {
	if (i == ans.size()) {
		output(ans);
		return;
	}
	dfs(i + 1, ans);
	for (int ci = i+1; ci < ans.size(); ci++) {
		swap(ans[i], ans[ci]);
		stable_sort(ans.begin()+i+1, ans.end()); // 字典序
		dfs(i+1, ans);
	}
}
void traversal_by_dfs(const vector<int>& v) {
	if (v.empty()) {
		return;
	}
	n = v.back();
	dfs(0,  v);
}

// STL提供了字典序遍历全排列的算法next_permutation
void traversal_by_STL(vector<int>& v) {
	do {
		output(v);
	} while (next_permutation(v.begin(), v.end()));
}

int main()
{
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		v[i] = i+1;
	}
	sort(v.begin(), v.end());
	// traversal_by_STL(v);
	traversal_by_dfs(v);
}

