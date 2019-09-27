// 链表处理codeup2453.cpp
// codeup Contest100000607 

#include <cstdio>
#include <list>
#include <utility>
using namespace std;

int main()
{
	int x;  scanf("%d", &x);
	list<int> l1;
	int n; scanf("%d", &n);
	while (n--) {
		int t;  scanf("%d", &t);
		l1.push_back(t);
	}
	bool found = false;
	for (auto it = l1.begin(); it != --l1.end(); it++) {
		if (*it == x) {
			swap(*it, *(++it));
			printf("%d\n", x);
			found = true;
			break;
		}
		if (*it > x) {
			l1.insert(it, x);
			break;
		}
	}
	if (!found) {
		printf("no\n");
	}
	if (!l1.empty()) {
		for (auto it = l1.begin(); it != --l1.end(); ++it) {
			printf("%d ", *it);
		}
		printf("%d", l1.back());
	}
}

