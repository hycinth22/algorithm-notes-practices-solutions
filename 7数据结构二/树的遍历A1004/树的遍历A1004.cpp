// 树的遍历A1004.cpp
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct one {
	vector<int> children;
	int lv; // level
};
inline size_t index(int id) { return id - 1; }
inline int id(size_t index) { return index + 1; }
int setLv(vector<one>& tree, int root) {
	int maxLv = tree[index(root)].lv; // 取最大值初始条件，也是递归的边界条件。
	for (auto& child : tree[index(root)].children) {
		tree[index(child)].lv = tree[index(root)].lv + 1;
		maxLv = max(maxLv, setLv(tree, child));
	}
	return maxLv;
}
int main()
{
	int n, m; cin >> n >> m;
	vector<one> all(n); vector<bool> isChild(n);
	// 接收输入，同时建立树，并寻找root
	for (int i = 0; i < m; ++i) {
		int id, k; cin >> id >> k;
		for (int j = 0; j < k; ++j) {
			int cid; cin >> cid;
			all[index(id)].children.push_back(cid);
			isChild[index(cid)] = true;
		}
	}
	// 寻找root结果
	int root = -1;
	for (size_t i = 0; i < all.size(); ++i) {
		if (!isChild[i]) {
			root = id(i);
			break;
		}
	}
	if (root == -1) return -1;
	// 从root向下赋值lv
	all[index(root)].lv = 0;
	int maxlv = setLv(all, root);
	// bfs计数每层叶子节点
	vector<int> ans(maxlv+1);
	queue<int> q; q.push(root);
	while (!q.empty()) {
		one& o = all[index(q.front())];
		if (o.children.empty()) { // 注意对应题目，一定要是叶子节点才计数
			ans[o.lv]++;
		}
		for (auto& cid: o.children) {
			q.push(cid);
		}
		q.pop();
	}
	// 输出结果
	if (!ans.empty()) {
		cout << ans.front();
		for (size_t i = 1; i < ans.size(); i++) {
			cout << " " << ans[i];
		}
	}
	cout << endl;
}
