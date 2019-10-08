// 深度优先搜索codeup5974.cpp
// cid=100000608

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int n);
int calc(int k, const vector<int>& dataset);

int main()
{
	cin.sync_with_stdio(0); cout.sync_with_stdio(0);
	int n, k; cin >> n >> k;
	vector<int> dataset(n);
	for (int& i : dataset) {
		cin >> i;
	}
	cout << calc(k, dataset) << endl;
}

bool isPrime(int n)
{
	int edge = int(sqrt(n));
	if (n < 2) return false;
	for (int i = 2; i <= edge; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

// 静态量：k dataset
// 动态量：i（已选择的数据索引，上限为k-1）j（待选择的数据索引，上限为n-1）, sum(已选择的数据和)
int dfs(int i, int j, int sum, int k, const vector<int>& dataset) {
	if (i >= k) {
		clog << sum << endl;
		return isPrime(sum) ? 1 : 0;
	}
	int cnt = 0;
	for (size_t m = j+1; m < dataset.size(); m++) {
		cnt += dfs(i+1, m, sum+dataset[m],
			k, dataset);
	}
	return cnt;
}

int calc(int k, const vector<int>& dataset)
{
	return dfs(0, -1, 0, k, dataset);
}
