// 深度优先搜索A1103.cpp
// 第4个测试点是1 1 2

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;



// 编写要点：参数放状态转移量小对象，这样可以免于编写这些变化量的前进后退代码，避免出错。
// 而小对象拷贝的时间开销和空间开销都不大。
// 
// 数组等大对象最好放在全局共享，并手动管理前进后退，
// 否则在传递时造成大量拷贝，不仅浪费空间，更重要的是*浪费时间*。
// 如果全程可以共用，也可以用引用。
//
// 整个过程中的不变量（如被搜索的总数据集），最好放在全局，或者也可以用引用。
// 
// 剪枝时，最好判断某数据对下一层构成无效解就直接跳过，而不是进入下一层后判断当前层构成的解无效再返回，这样会多调用堆栈开销。

// 目标是n = sum_selectedPow
//（sum_selectedPow = ΣselectedPow[selectIstart], selectedPow[selectIstart]=selectedFac[selectIstart]^p）
// 当前在检索结果集的第c个数 c的范围[0, k)
// 共需检索k个数，（selectedFac.size()==selectedPow.size()）
// 数据总集为powers，当前索引为i。（索引同时也是factor, 数据为对应factor^p）
// 参数前3个是全过程不变量，后面是动态变化量。全局中的也是动态变化量。

vector<int> resultFac; int sum_resultFac;
void dfs(const int& n, const int& k, const vector<int>& powers, 
	int ansI, int selectIstart, 
	vector<int>& selectedFac, vector<int> &selectedPow,
	int sum_selectedFac, int sum_selectedPow) {
	// 提前剪枝
	if (sum_selectedPow > n || selectIstart >= powers.size()) {
		return;
	}
	// 该组达到数量
	if (ansI == -1) {
		// 必须注释掉clog，虽然clog（cerr）不影响输出结果（只判断cout stdout），但会消耗运行时间。
		/*
		for (auto& d : selectedPow) {
			clog << d << "+";
		}
		clog << "=" << sum_selectedPow << endl;
		*/
		if (sum_selectedPow == n) {
			if (sum_selectedFac > sum_resultFac) {
				resultFac = selectedFac;
				sum_resultFac = sum_selectedFac;
			}
			else if (sum_selectedFac == sum_resultFac) {
				int i = 0;
				while (selectedFac[i] == resultFac[i]) {
					i++;
				}
				if (i<k && selectedFac[i] > resultFac[i]) {
					resultFac = selectedFac;
					sum_resultFac = sum_selectedFac;
				}
			}
		}
		return;
	}
	for (int selectI = powers.size() - 1; selectI >= selectIstart; selectI--) {
		// 剪枝
		if (sum_selectedPow + powers[selectI] <= n) {
			// pick powers[selectIstart] (selectIstart^p)
			selectedFac[ansI] = selectI;
			selectedPow[ansI] = selectI;
			dfs(n, k, powers, ansI-1, selectI, 
				selectedFac, selectedPow,
				sum_selectedFac+ selectI, sum_selectedPow+ powers[selectI]);
		}
	}
}

inline vector<int> search(int n, int k, const vector<int>& powers) {
	vector<int> v; int sum = 0;
	resultFac.clear();
	vector<int> selectedFac(k), selectedPow(k);
	sum_resultFac = 0;
	dfs(n, k, powers, k-1, 1,
		selectedFac, selectedPow,
		0, 0);
	return resultFac;
}

// 整数快速幂
int pow(int n, int p) {
	switch (p) {
	case 0:
		return 1;
	case 1:
		return n;
	case 2:
		return n * n;
	default:
		break;
	}
	if (p&1==0) {
		int t = pow(n, p>>1);
		t *= t;
		return t;
	}
	else {
		int t = pow(n, p>>1);
		t *= t * n;
		return t;
	}
}

int main()
{
	// 必须调用。否则超时。
	// 如果打算用c++ io，那么最好调用这个，并且不能混用c++和c的io（但是可以输入用c++的，输出用c的这样）
	cin.sync_with_stdio(false); cout.sync_with_stdio(false);
	int n, k, p; cin >> n >> k >> p;
	vector<int> powers; // powers[selectIstart] is selectIstart^p
	powers.reserve(n + 1); // [0, n]
	// 注意要写i <= n
	for (int i = 0; i <= n; i++) {
		int t = pow(i, p);
		powers.push_back(t);
		if (t >= n) {
			break;
		}
	}
	auto r = search(n, k, powers);
	if (!r.empty()) {
		cout << n << " = " << r.front() << "^" << p;
		for (auto i = ++r.cbegin(); i != r.cend(); ++i) {
			cout << " + " << *i << "^" << p;
		}
	}
	else {
		cout << "Impossible";
	}
	cout << endl;
}

