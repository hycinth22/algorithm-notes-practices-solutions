// 链表处理codeup2421.cpp
// codeup Contest100000607 

#include <cstdio>
#include <list>
using namespace std;

int main()
{
	list<int> l1, l2;
	int n; scanf("%d", &n);
	while (n--) {
		int t;  scanf("%d", &t);
		l1.push_back(t);
	}
	int m; scanf("%d", &m);
	while (m--) {
		int t;  scanf("%d", &t);
		l2.push_back(t);
	}
	l1.splice(l1.end(), l2);
	if (!l1.empty()) {
		for (auto it = l1.begin(); it != --l1.end(); ++it) {
			printf("%d ", *it);
		}
		printf("%d", l1.back());
	}
}

