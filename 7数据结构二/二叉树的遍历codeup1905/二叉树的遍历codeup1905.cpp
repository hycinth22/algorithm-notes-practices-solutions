// 二叉树的遍历codeup1905.cpp
//

#include <iostream>
// #include <stack>
using namespace std;

// DFS
// 二叉树层数(n)深之后，BFS每层宽度2*n，而DFS遍历深度n，更为节省空间。
// 无论DFS还是BFS都需要遍历整个子树，时间效率应该没有太大差别
int cnt(int n, int m) {
	if (n > m) {
		return 0;
	}
	if (n == m) {
		return 1;
	}
	return cnt(2*n, m) + cnt(2*n+1, m) + 1;
}

// BFS内存超限
/*
int cnt(int n, int m) {
	int cnt = 0;
	queue<int> q; q.push(n);
	while (!q.empty()) {
		int& k = q.front();
		++cnt;
		if (2 * k <= m) {
			q.push(2*k);
			if (q.back()+1 <= m) {
				q.push(q.back() + 1);
			}
		}
		q.pop();
	}
	return cnt;
}
*/

int main()
{
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) {
			break;
		}
		cout << cnt(n, m) << endl;
	}
}

