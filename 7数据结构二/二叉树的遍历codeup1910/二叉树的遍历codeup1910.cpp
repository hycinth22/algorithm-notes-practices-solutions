// 二叉树的遍历codeup1910.cpp
//

#include <iostream>
#include <string>
using namespace std;

struct node {
	node *left, *right;
	char data;
};

void traversalPostOrder(node* root) {
	if (root->left) {
		traversalPostOrder(root->left);
	}
	if (root->right) {
		traversalPostOrder(root->right);
	}
	cout << root->data;
}

node* rebuild(const string& preorder, const string &inorder) {
	node* root = new node();
	if (preorder.empty() || inorder.empty()) {
		return nullptr;
	}
	root->data = preorder.front();
	auto pos = inorder.find(root->data);
	string inleft = inorder.substr(0, pos),
		inright = inorder.substr(pos+1);
	string preleft = preorder.substr(1, inleft.size()),
		preright = preorder.substr(1+inleft.size());
	// assert(preright.size() == inright.size())
	root->left = rebuild(preleft, inleft);
	root->right = rebuild(preright, inright);
	return root;
}

int main()
{
	string preorder, inorder;
	while (getline(cin, preorder), getline(cin, inorder)) {
		auto root = rebuild(preorder, inorder);
		traversalPostOrder(root);
		cout << endl;
	}
}

