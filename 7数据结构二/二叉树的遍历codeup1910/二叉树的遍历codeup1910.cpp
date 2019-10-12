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

node* rebuild(const string& preorder, const string &midorder) {
	node* root = new node();
	if (preorder.empty() || midorder.empty()) {
		return nullptr;
	}
	root->data = preorder.front();
	auto pos = midorder.find(root->data);
	string midleft = midorder.substr(0, pos),
		midright = midorder.substr(pos+1);
	string preleft = preorder.substr(1, midleft.size()),
		preright = preorder.substr(1+midleft.size());
	// assert(preright.size() == midright.size())
	root->left = rebuild(preleft, midleft);
	root->right = rebuild(preright, midright);
	return root;
}

int main()
{
	string preorder, midorder;
	while (getline(cin, preorder), getline(cin, midorder)) {
		auto root = rebuild(preorder, midorder);
		traversalPostOrder(root);
		cout << endl;
	}
}

