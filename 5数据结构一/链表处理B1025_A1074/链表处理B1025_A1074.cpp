// 链表处理B1025_A1074.cpp
// 不需要真的去做链表反转操作。
// 用线性表表示链表关系，然后对关系进行操作。

#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct node {
	int data;
	int next;
};
struct nodeex : node {
	nodeex(const node& n) {
		this->data = n.data;
		this->next = n.next;
	}
	size_t order;
	int addr;
	bool operator< (const nodeex& rhs) {
		return order < rhs.order;
	}
};

int main()
{
	int head; cin >> head;
	size_t n, k; cin >> n >> k;
	// use unordered_map to emuluate system memory
 	unordered_map<int, node> m;
	for (size_t i = 0; i < n; i++) {
		int addr; cin >> addr;
		static node t; cin >> t.data >> t.next;
		m.insert(make_pair<>(addr, t));
	}
	// link sqeuence
	vector<int> seq; seq.reserve(m.size());
	int cur = head; size_t order = 0;
	while (cur != -1) {
		seq.push_back(cur);
		cur = m[cur].next;
	}
	// reverse sqeuence each group
	for (size_t i = 0; i < seq.size() - seq.size()%k; i+=k) {
		reverse(&seq[i], &seq[i+k]);
	}
	// output
	printf("");
	for (size_t i = 0; i < seq.size()-1; i++) {
		printf("%05d %d %05d\n", seq[i], m[seq[i]].data, seq[i+1]);
	}
	printf("%05d %d -1\n", seq.back(), m[seq.back()].data);
}

