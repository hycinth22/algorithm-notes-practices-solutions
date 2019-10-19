// 二叉查找树A1043.cpp
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

struct node {
	node* left, * right;
	int data;
};

// 坑：注意，输入数据包含与根相等数据。根据题目定义，相等节点需放在右子树。
// 参数为BST的先序遍历。如不是BST将丢弃不符合规则的数据。
node* rebuildBST(const vector<int>& dataset, size_t begin, size_t end) {
	// 定位根节点：根据先序遍历特点，第一个必是树的根节点
	// 划分左右子树：根据BST特点，左子树必然全都小于（等于）根节点，右子树必然全都大于（等于）根节点
	if (begin >= end) {
		return nullptr;
	}
	node* root = new node();
	root->data = dataset[begin];
	// 此处已保证了左子树都必定小于根部。
	size_t le = find_if(dataset.begin() + begin + 1, dataset.begin() + end, bind2nd(greater_equal<int>(), root->data)) - dataset.begin();
	root->left = rebuildBST(dataset, begin+1, le);
	// 此处已保证了右子树都必定大于根部
	size_t re = find_if(dataset.begin() + le, dataset.begin() + end, bind2nd(less<int>(), root->data)) - dataset.begin();
	root->right = rebuildBST(dataset, le, re);
	// re != end 代表不是BST
	return root;
}


// 参数为BST镜像的先序遍历。如不是BST镜像将丢弃不符合规则的数据。
// 镜像中相当数据处于左子树
node* rebuildBSTMirror(const vector<int>& dataset, size_t begin, size_t end) {
	if (begin >= end) {
		return nullptr;
	}
	node* root = new node();
	root->data = dataset[begin];
	// 此处已保证了左子树都必定大于根部
	size_t le = find_if(dataset.begin() + begin + 1, dataset.begin() + end, bind2nd(less<int>(), root->data)) - dataset.begin();
	root->left = rebuildBSTMirror(dataset, begin + 1, le);
	// 此处已保证了右子树都必定大于根部
	size_t re = find_if(dataset.begin() + le, dataset.begin() + end, bind2nd(greater_equal<int>(), root->data)) - dataset.begin();
	root->right = rebuildBSTMirror(dataset, le, re);
	// re != end 代表不是BST镜像
	return root;
}


void getpostorderin(node* tree, vector<int> &result) {
	if (tree->left) {
		getpostorderin(tree->left, result);
	}
	if (tree->right) {
		getpostorderin(tree->right, result);
	}
	result.push_back(tree->data);
}
inline vector<int> getpostorder(node* tree) {
	vector<int> result;
	getpostorderin(tree, result);
	return result;
}

int main()
{
	int n; cin >> n;
	vector<int> preorder(n);
	for (int i = 0; i < n; ++i) {
		cin >> preorder[i];
	}
	// 先判断是否BST
	node* root = rebuildBST(preorder, 0, preorder.size()); // 参数不是BST则结果不完整。
	vector<int> postorder = getpostorder(root);
	if (preorder.size() == postorder.size()) {
		cout << "YES\n";
		if (!postorder.empty()) {
			cout << postorder.front();
			for (size_t i = 1; i < postorder.size(); ++i) {
				cout << " " << postorder[i];
			}
		}
		cout << endl;
		return 0;
	}
	// 工程中此处需要释放BST空间
	// deleteTree(root);
	// 再判断是否是BST的镜像
	root = rebuildBSTMirror(preorder, 0, preorder.size());
	postorder = getpostorder(root);
	if (preorder.size() == postorder.size()) {
		cout << "YES\n";
		if (!postorder.empty()) {
			cout << postorder.front();
			for (size_t i = 1; i < postorder.size(); ++i) {
				cout << " " << postorder[i];
			}
		}
		cout << endl;
		return 0;
	}
	cout << "NO" << endl;
}

