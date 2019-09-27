// 链表处理codeup3596.cpp
// codeup Contest100000607 

#include <cstdio>
#include <list>
#include <utility>
using namespace std;

void output(const list<int>& l1) {
	if (!l1.empty()) {
		for (auto it = l1.begin(); it != --l1.end(); ++it) {
			printf("%d ", *it);
		}
		printf("%d", l1.back());
	}
	printf("\n");
}

int main()
{
	int n; list<int> l1;
	while (scanf("%d", &n)) {
		if (n == 0) {
			printf("list is empty\n");
			continue;
		}
		while (n--) {
			int t;  scanf("%d", &t);
			l1.push_back(t);
		}
		output(l1);
		l1.reverse();
		output(l1);
		l1.clear();
	}
}

