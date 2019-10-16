#include <cstdio>
#include <vector>
using namespace std;
struct seller {
	double price;
	vector<int> buyers;
	int amount;
};

double calcPrice(vector<seller>& tree, double raise, int root = 0) {
	if (tree[root].buyers.empty()) {
		return tree[root].price * tree[root].amount;
	}
	double sum = 0.0;
	for (int& id : tree[root].buyers) {
		tree[id].price = tree[root].price * raise;
		sum += calcPrice(tree, raise, id);
	}
	return sum;
}

int main()
{
	int n; double p, r; scanf("%d %lf %lf", &n, &p, &r); 
	r = r/100+1; // 坑，注意题目输入是增长的百分比。此处先转换成小数，然后增加1，以便直接乘 // r, the **percentage** rate of price **increment**
	vector<seller> all(n);
	for (int i = 0; i < n; ++i) {
		int k; scanf("%d", &k);
		if (k == 0) {
			scanf("%d", &all[i].amount);
		}
		else {
			all[i].buyers.reserve(k);
			for (int j = 0; j < k; ++j) {
				int buy; scanf("%d", &buy);
				all[i].buyers.push_back(buy);
			}
		}
	}
	all[0].price = p;
	double total = calcPrice(all, r);
	printf("%.1f\n", total);
}
