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

// 此处利用模板与函数化将重建BST树与重建BST镜像树的函数进行了合并，如想使用不带有模板与函数化的写法参照如下网址
// https://github.com/inkedawn/algorithm-notes-practices-solutions/blob/e2c6a64b6258856c15643693901fd6cadfdf7639/7%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E4%BA%8C/%E4%BA%8C%E5%8F%89%E6%9F%A5%E6%89%BE%E6%A0%91A1043/%E4%BA%8C%E5%8F%89%E6%9F%A5%E6%89%BE%E6%A0%91A1043.cpp

// 坑：注意，输入数据包含与根相等数据。根据题目定义，相等节点需放在右子树。
// 参数为BST的先序遍历。如不是BST将丢弃不符合规则的数据。
template<class comp1 = less<int>,
	class comp2 = greater_equal<int>
>
node* rebuildBST(const vector<int>& dataset, size_t begin, size_t end) {
	// 定位根节点：根据先序遍历特点，第一个必是树的根节点
	// 划分左右子树：根据BST特点，左子树必然全都小于（等于）根节点，右子树必然全都大于（等于）根节点
	if (begin >= end) {
		return nullptr;
	}
	node* root = new node();
	root->data = dataset[begin];
	// 此处已保证了左子树都必定小于根部。
	size_t le = find_if(dataset.begin() + begin + 1, dataset.begin() + end, bind2nd(comp2(), root->data)) - dataset.begin();
	root->left = rebuildBST<comp1, comp2>(dataset, begin+1, le);
	// 此处已保证了右子树都必定大于等于根部
	size_t re = find_if(dataset.begin() + le, dataset.begin() + end, bind2nd(comp1(), root->data)) - dataset.begin();
	root->right = rebuildBST<comp1, comp2>(dataset, le, re);
	// re != end 代表不是BST
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
	// 先尝试按BST规则建立树
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
	// 再尝试按照BST的镜像规则建立树
	root = rebuildBST<greater_equal<int>, less<int>>(preorder, 0, preorder.size());
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

