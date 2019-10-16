// 树的遍历A1053.cpp
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

struct node {
	int weight;
	vector<int> childs;
	bool operator<(const node& n) const {
		return weight > n.weight;
	}
};

vector<node> tree;
bool nodeIDCmpByWeight(const int& a, const int& b) {
	return tree[a].weight > tree[b].weight;
}
void findPath(list<int> &path, int weight) {
	weight -= tree[path.back()].weight;
	if (weight < 0) {
		return;
	}
	if (weight == 0 && tree[path.back()].childs.empty()) {
		bool first = true;
		for (auto& i : path) {
			if (first) {
				cout << tree[i].weight;
				first = false;
			}
			else {
				cout << " " << tree[i].weight;
			}
		}
		cout << endl;
		return;
	}
	for (auto& child : tree[path.back()].childs) {
		path.push_back(child);
		findPath(path, weight);
		path.pop_back();
	}
}

int main()
{
	cin.sync_with_stdio(0); cout.sync_with_stdio(0);
	int n, m, s; cin >> n >> m >> s;
	tree.resize(n);
	for (node& n : tree) {
		cin >> n.weight;
	}
	for (int i = 0; i < m; i++) {
		int id; cin >> id;
		node& node = tree[id];
		int k; cin >> k;
		node.childs.resize(k);
		for (int f = 0; f < k; f++) {
			cin >> node.childs[f];
		}
		sort(node.childs.begin(), node.childs.end(), nodeIDCmpByWeight);
	}
	list<int> path; path.push_back(0);
	findPath(path, s);
}

