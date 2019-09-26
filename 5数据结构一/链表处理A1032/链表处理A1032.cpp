// 链表处理A1032.cpp
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct node {
	char data;
	int next;
};

int main()
{
	unordered_map<int, node> m;
	int head1, head2; scanf("%d%d", &head1, &head2);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int addr; static node n;  scanf("%5d %c %5d", &addr, &n.data, &n.next);
		m.insert(make_pair<>(addr, n));
	}
	vector<int> seq1; seq1.reserve(n);
	int c = head1;
	while (c != -1) {
		seq1.push_back(c);
		c = m.at(c).next;
	}
	vector<int> seq2; seq2.reserve(n);
	c = head2;
	while (c != -1) {
		seq2.push_back(c);
		c = m.at(c).next;
	}
	int ir = -1;
	for (auto i1 = seq1.rbegin(), i2 = seq2.rbegin(); i1 != seq1.rend() && i2 != seq2.rend(); i1++, i2++) {
		if (*i1 == *i2) {
			ir = *i1;
		}
	}
	if (ir != -1) {
		printf("%05d", ir);
	}
	else {
		printf("-1");
	}
}

