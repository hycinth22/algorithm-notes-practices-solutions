// 树的遍历A1090.cpp
//
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
struct seller {
	int supplier;
	double price;
};
void assureCalc(vector<seller> &tree, int i, double r) {
	if (tree[i].price != -1.00) {
		return;
	}
	if (tree[i].supplier != -1) {
		assureCalc(tree, tree[i].supplier, r);
		tree[i].price = tree[tree[i].supplier].price * r;
	}
}
int main()
{
	int n; double p, r; scanf("%d %lf %lf", &n, &p, &r);
	r = r / 100 + 1;
	vector<seller> all(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &all[i].supplier);
		all[i].price = -1.0;
		if (all[i].supplier == -1) {
			all[i].price = p;
		}
	}
	for (int i = 0; i < n; ++i) {
		assureCalc(all, i, r);
	}
	double maxprice = max_element(all.cbegin(), all.cend(), [](const seller& a, const seller& b) {return a.price < b.price; })->price;
	int cnt = count_if(all.cbegin(), all.cend(), [maxprice](const seller& s) {return s.price == maxprice; });
	printf("%.2f %d", maxprice, cnt);
}

