// 二叉树的遍历A1086.cpp
//

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct node {
	node* left, * right;
	int data;
};

node* rebuild(vector<int>::const_iterator preorder_begin,
	vector<int>::const_iterator preorder_end,
	vector<int>::const_iterator inorder_begin,
	vector<int>::const_iterator inorder_end) {
	if (preorder_begin == preorder_end ||
		inorder_begin == inorder_end) {
		return nullptr;
	}
	node* root = new node();
	root->data = *(preorder_begin++);
	// 找到根元素在中序遍历的位置
	auto itMid = find(inorder_begin, inorder_end, root->data);
	// 根据根元素，从中序遍历中区分左右子树
	auto itInLBegin = inorder_begin,
		itInLEnd = itMid;
	auto itInRBegin = itMid + 1,
		itInREnd = inorder_end;
	// 从中序遍历中计算左右子树长度
	size_t lenL = itInLEnd - itInLBegin,
		lenR = itInREnd - itInRBegin;
	// 根据左右子树长度，从后序遍历中区分左右子树
	auto itPreLBegin = preorder_begin,
		itPreLEnd = preorder_begin + lenL;
	auto itPreRBegin = itPreLEnd,
		itPreREnd = preorder_end;
	root->left = rebuild(itPreLBegin, itPreLEnd, itInLBegin, itInLEnd);
	root->right = rebuild(itPreRBegin, itPreREnd, itInRBegin, itInREnd);
	return root;
}

bool first = true;
void traversalPostOrder(node* root) {
	if (!root) return;
	traversalPostOrder(root->left);
	traversalPostOrder(root->right);
	if (!first) {
		cout << " ";
	}
	cout << root->data;
	first = false;
}

int main()
{
	int n; cin >> n; n <<= 1;
	vector<int> preorder, inorder;
	preorder.reserve(n); inorder.reserve(n);
	stack<int> s;
	while (n--) {
		string op;
		cin >> op;
		if (op == "Push") {
			int data; cin >> data;
			preorder.push_back(data);
			s.push(data);
		}
		else if (op == "Pop") {
			inorder.push_back(s.top());
			s.pop();
		}
	}
	auto root = rebuild(preorder.cbegin(), preorder.cend(), inorder.cbegin(), inorder.cend());
	traversalPostOrder(root);
}

