// 递归-n皇后问题.cpp
// 求解n皇后的可行方案数

#include <iostream>
#include <unordered_set>
#include <functional>
#include <utility>
#include <vector>
using namespace std;

void outputChess(const vector<size_t>& e, size_t n) {
	size_t l = e.size();
	for (size_t row = 0; row < n; row++) {
		for (size_t col = 0; col < n; col++) {
			if (col < l && e[col] == row) {
				cout << "x";
			}
			else {
				cout << "*";
			}
		}
		cout << endl;
	}
	for (size_t k : e) {
		clog << k << "|";
	}
	clog << endl << endl;
}

size_t f(size_t n) {
	int cnt = 0;
	vector< vector<size_t> > results; 
	vector<size_t> e(n);
	unordered_set<size_t> isFilled;
	function<void(size_t)> f = [&](size_t i) {
		if (i == n) {
			// 递归边界
			cnt++;
			clog << "# Solution" << results.size() << endl;
			// 此时e中保存的即为一种有效方案
			outputChess(e, n);
			results.push_back(e);
			return;
		}
		for (size_t j = 0; j < n; ++j) {
			bool canput = true;
			// 检测此行是否还没有放
			if (isFilled.count(j)) {
				canput = false;
			}
			else {
				// 检测是否已与前面的冲突，递归剪枝
				for (size_t m = 0; m < i; ++m) {
					// x1,y1: m,e[m]
					// x2,y2: i,j
					size_t x1 = m, x2 = i,
						y1 = e[m], y2 = j;
					if (x1 < x2) {
						swap(x1, x2);
					}
					if (y1 < y2) {
						swap(y1, y2);
					}
					if (x1 - x2 == y1 - y2) {
						// 在对角线上: |x1-x2|==|y1-y2|
						canput = false;
					}
				}
			}
			if (canput) {
				isFilled.insert(j);
				e[i] = j;
				// clog << "fill " << i << " " << j << endl;
				// outputChess(vector<size_t>(e.data(), e.data() + i + 1), n);
				f(i+1);
				isFilled.erase(j);
				// clog << "back " << i << " " << j << endl;
			}
		}
	};
	f(0);
	// return results;
	return cnt;
}

int main()
{
	while (1) {
		int n; cin >> n;
		cout << "Amount:" << f(n) << endl;
	}
}

