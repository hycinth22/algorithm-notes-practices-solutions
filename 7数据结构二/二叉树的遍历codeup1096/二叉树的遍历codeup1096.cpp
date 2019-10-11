// 二叉树的遍历codeup1096.cpp
// 此题涉及二叉树的三种遍历方式，以及从先序+中序遍历字符串中重建二叉树

#include <iostream>
#include <string>
using namespace std;

struct node{
	node* left = nullptr;
	node* right = nullptr;
	char data;
};

// 注意理解并记住，从中序遍历字符串和先/后序遍历字符串，重建二叉树的方法。
node* rebuild(const string& preorder, const string& midorder) {
	node* root = new node();
	if (preorder.empty() || midorder.empty()) {
		return nullptr;
	}
	root->data = preorder.front();
	auto midIndex = midorder.find(root->data);
	if (midIndex == string::npos) {
		return nullptr;
	}
	// 理清楚此处的关系：从先序获得中间元素，然后根据中间元素从中序分离中序的左右子树，而后根据中序的左右子树，分离先序的左右子树
	// 循环进行此过程。
	// 尽管这几行代码有些相似，但最好不要复制代码再修改，易出错。

	// 此处取子树，不要忘记+1以跳过中间的当前节点元素。
	string midorderLeft = midorder.substr(0, midIndex), // left subtree
		midorderRight = midorder.substr(midIndex+1); // right subtree
	// 无论何序遍历，某子树的长度一致。
	string preorderLeft = preorder.substr(1, midorderLeft.size()), // left subtree
		preorderRight = preorder.substr(1+ midorderLeft.size()); // right subtree

	root->left = rebuild(preorderLeft, midorderLeft);
	root->right = rebuild(preorderRight, midorderRight);
	return root;
}

void postorder(node* root) {
	if (root->left) {
		postorder(root->left);
	}
	if (root->right) {
		postorder(root->right);
	}
	cout << root->data;
}

int main()
{
	string preorder, midorder;
	while (cin >> preorder >> midorder) {
		auto root = rebuild(preorder, midorder);
		postorder(root);
		cout << endl;
	}
}

