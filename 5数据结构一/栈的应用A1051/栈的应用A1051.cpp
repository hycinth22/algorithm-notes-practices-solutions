// 栈的应用A1051.cpp
//

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	int m, n, k; cin >> m >> n >> k;
	while (k--) {
		stack<int> s; // 数据栈
		queue<int> q; // 输入的尝试模拟序列
		for (int i = 1; i <= n; i++) {
			int t; cin >> t;
			q.push(t);
		}
		// 模拟弹出。i是输入序列，尝试拟合q
		for (int i=1; i<=n; i++) {
			if (s.size() < m) {
				s.push(i);
			}
			else {
				goto no;
			}
			// pop randomly -> 尝试拟合q
			while (!s.empty() && !q.empty() && s.top() == q.front()) {
				s.pop(); q.pop(); // acknowledge it
			}
		}
		if (q.empty()) {
			cout << "YES" << endl;
		}
		else {
			no:
			cout << "NO" << endl;
		}
	}
}

