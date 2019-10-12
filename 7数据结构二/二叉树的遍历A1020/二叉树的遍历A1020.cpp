// 二叉树的遍历A1020.cpp
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
	node* left, * right;
	int data;
};

node* rebuild(vector<int>::const_iterator postorder_begin,
			vector<int>::const_iterator postorder_end,
	vector<int>::const_iterator inorder_begin,
	vector<int>::const_iterator inorder_end) {
	if (postorder_begin== postorder_end ||
		inorder_begin==inorder_end) {
		return nullptr;
	}
	node* root = new node();
	root->data = *(--postorder_end);
	// 找到根元素在中序遍历的位置
	auto itMid = find(inorder_begin, inorder_end, root->data);
	// 根据根元素，从中序遍历中区分左右子树
	auto itInLBegin = inorder_begin,
		itInLEnd = itMid;
	auto itInRBegin = itMid+1,
		itInREnd = inorder_end;
	// 从中序遍历中计算左右子树长度
	size_t lenL = itInLEnd - itInLBegin,
		lenR = itInREnd - itInRBegin;
	// 根据左右子树长度，从后序遍历中区分左右子树
	auto itPostLBegin = postorder_begin,
		itPostLEnd = postorder_begin + lenL;
	auto itPostRBegin = itPostLEnd,
		itPostREnd = postorder_end;
	root->left = rebuild(itPostLBegin, itPostLEnd, itInLBegin, itInLEnd);
	root->right = rebuild(itPostRBegin, itPostREnd, itInRBegin, itInREnd);
	return root;
}

void levelTraversal(node* root) {
	queue<node*> q; q.push(root);
	while (!q.empty()) {
		auto& n = q.front();
		if (n != root) {
			cout << " ";
		}
		cout << n->data;
		if (n->left) {
			q.push(n->left);
		}
		if (n->right) {
			q.push(n->right);
		}
		q.pop();
	}
	cout << endl;
}

int main()
{
	int n; cin >> n;
	vector<int> postorder(n), inorder(n);
	for (int i = 0; i < n; i++) {
		cin >> postorder[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> inorder[i];
	}
	auto root = rebuild(postorder.cbegin(), postorder.cend(), inorder.cbegin(), inorder.cend());
	levelTraversal(root);
}

