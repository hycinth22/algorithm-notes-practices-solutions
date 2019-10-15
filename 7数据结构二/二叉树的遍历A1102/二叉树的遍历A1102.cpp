// 二叉树的遍历A1102.cpp
//

#include <iostream>
#include <unordered_map>
#include <utility>
#include <queue>
#include <functional>
using namespace std;

void levelTraversal(const unordered_map<int, pair<int, int> >& tree, int root) {
	queue<int> q;
	auto& rootnode = tree.at(root);
	cout << root;
	if (rootnode.first != -1) {
		q.push(rootnode.first);
	}
	if (rootnode.second != -1) {
		q.push(rootnode.second);
	}
	while (!q.empty()) {
		int& c = q.front();
		cout << " " << c;
		auto& node = tree.at(c);
		if (node.first != -1) {
			q.push(node.first);
		}
		if (node.second != -1) {
			q.push(node.second);
		}
		q.pop();
	}
	cout << endl;
}

void inorderTraversal(const unordered_map<int, pair<int, int> >& tree, int root) {
	bool inorderFirst = true;
	function<void(int node)> visit = [&tree, &inorderFirst, &visit] (int node) {
		auto& child = tree.at(node);
		if (child.first != -1) {
			visit(child.first);
		}
		if (inorderFirst) {
			cout << node;
			inorderFirst = false;
		}
		else {
			cout << " " << node;
		}
		if (child.second != -1) {
			visit(child.second);
		}
	};
	visit(root);
	cout << endl;
}

void invert(unordered_map<int, pair<int, int> >& tree, int root) {
	swap(tree[root].first, tree[root].second);
	if (tree[root].first != -1) {
		invert(tree, tree[root].first);
	}
	if (tree[root].second != -1) {
		invert(tree, tree[root].second);
	}
}

int main()
{
	// input
	int n; cin >> n;
	unordered_map<int, bool> isChild;
	unordered_map<int, pair<int, int> > tree;
	for (int i = 0; i < n; ++i) {
		char c1, c2; cin >> c1 >> c2;
		int k1 = (c1 == '-' ? -1 : c1-'0');
		int k2 = (c2 == '-' ? -1 : c2 - '0');
		tree[i] = {k1, k2};
		isChild[k1] = isChild[k2] = true;
	}
	// find the root node
	int root = -1;
	for (int i = 0; i < n; ++i) {
		if (!isChild.count(i) || !isChild.at(i)) {
			root = i;
			break;
		}
	}
	if (root == -1) {
		cerr << "unknown root" << endl;
		return 1;
	}
	// invert and output
	invert(tree, root);
	levelTraversal(tree, root);
	inorderTraversal(tree, root);
}

