// 链表处理A1052.cpp
//

#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

struct node {
	int key;
	int next;
};

int main()
{
	int n, head; cin >> n >> head;
	unordered_map<int, node> m;
	for (int i = 0; i < n; i++) {
		int addr; node t; cin >> addr >> t.key >> t.next;
		m.insert(make_pair<>(addr, t));
	}
	// 根据链表顺序取得所有结点的地址，并线性存储。
	vector<int> seq; seq.reserve(n);
	int cur = head;
	while (cur != -1) {
		seq.push_back(cur);
		cur = m.at(cur).next;
	}
	sort(seq.begin(), seq.end(), [&](int a, int b) {
		return m.at(a).key < m.at(b).key;
		});
	if (!seq.empty()) {
		// 注意要取size()而非直接输出n，因为输入节点可能并不在链表中
		printf("%d %05d\n", seq.size(), seq.front());
	}
	else {
		printf("0 -1\n");
	}
	if (!seq.empty()) {
		// 务必判空，否则size=0时会运行出错。
		// 因为size()是无符号数，size()为0时size()-1回绕到unsigned最大值，继而访问越界。
		for (size_t i = 0; i < seq.size() - 1; i++) {
			printf("%05d %d %05d\n", seq[i], m.at(seq[i]).key, seq[i + 1]);
		}
		printf("%05d %d -1\n", seq.back(), m.at(seq.back()).key);
	}
}

