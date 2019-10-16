// 树的遍历A1094.cpp
//

#include <cstdio>
#include <vector>
using namespace std;

struct person {
	int id;
	vector<int> children;
};
vector<person> tree;
vector<int> population(1, 0); // level 0 is empty. level 1 has only root
void cntGroupByLevel(int root, int depth = 1) {
	if (population.size() <= depth) { // 注意多1情况下如何判断
		population.resize(depth+1, 0); // 注意多1情况下如何扩容
	}
	++population[depth];
	for (int child : tree[root].children) {
		cntGroupByLevel(child, depth+1);
	}
}

int main()
{
	int n, m; scanf("%d %d", &n, &m);
	vector<bool> isChild(n+1);
	tree.resize(n+1);
	for (int i = 1; i <= m; ++i) {
		int id, k; scanf("%d %d", &id, &k);
		tree[id].children.reserve(k);
		for (int j = 0; j < k; ++j) {
			int child; scanf("%d", &child);
			tree[id].children.push_back(child);
			isChild[child] = true;
		}
	}
	int root = -1;
	for (int i = 1; i <= n; ++i) {
		if (!isChild[i]) {
			root = i;
			break;
		}
	}
	if (root == -1) {
		return 1;
	}
	cntGroupByLevel(root);
	int maxv = -1, maxi;
	for (int i = 0; i < population.size(); ++i) {
		if (population[i] > maxv) {
			maxv = population[i];
			maxi = i;
		}
	}
	// 注意第二个输出的是有几个叶子节点达到最大价格，而不是最高价格路径有多长
	printf("%d %d\n", maxv, maxi);
}

