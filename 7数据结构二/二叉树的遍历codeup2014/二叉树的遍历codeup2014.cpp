// 二叉树的遍历codeup2014.cpp
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct node {
	node* left, * right;
	char data;
};

void traversalMidOrder(node* root) {
	if (root->left) {
		traversalMidOrder(root->left);
	}
	cout << root->data << " ";
	if (root->right) {
		traversalMidOrder(root->right);
	}
}

node* rebuildsubtree(const string& preorder, size_t& begin) {
	if (begin >= preorder.size()) {
		return nullptr;
	}
	if (preorder[begin] == '#') {
		++begin;
		return nullptr;
	}
	node* root = new node();
	root->data = preorder[begin];
	++begin;
	root->left = rebuildsubtree(preorder, begin);
	root->right = rebuildsubtree(preorder, begin);
	return root;
}

inline node* rebuild(const string& preorder) {
	size_t b = 0;
	return rebuildsubtree(preorder, b);
}

int main()
{
	string input; 	
	while (getline(cin, input)) {
		auto root = rebuild(input);
		traversalMidOrder(root);
		cout << endl;
	}
}
