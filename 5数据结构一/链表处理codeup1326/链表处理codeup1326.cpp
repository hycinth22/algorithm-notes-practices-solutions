// 链表处理codeup1326.cpp
// codeup Contest100000607 

#include <cstdio>
#include <cstring>
#include <list>
#include <iterator>
using namespace std;

int main()
{
	list<int> l;
	int n; scanf("%d", &n);
	while (n--) {
		int t; scanf("%d", &t);
		l.push_front(t);
	}
	int m; scanf("%d", &m); 
	getchar(); // ignore the enter
	while (m--) {
		const size_t maxOpLen = 6;
		char op[maxOpLen + 1];
		scanf("%6s", op);
		if (strcmp(op, "get") == 0) {
			int pos; scanf("%d", &pos);
			if (pos - 1 < l.size()) {
				// 注意advance用法，不是返回值式，是改变原迭代器值，无返回值。
				auto it = l.begin();
				advance(it, pos - 1); 
				printf("%d\n", *it);
			}
			else {
				printf("get fail\n");
			}
		}

		else if (strcmp(op, "insert") == 0) {
			int pos, data; scanf("%d%d", &pos, &data);
			if (pos - 1 <= l.size()) {
				auto it = l.begin();
				advance(it, pos - 1);
				l.insert(it, data);
				printf("insert OK\n");
			}
			else {
				printf("insert fail\n");
			}
		}
		else if (strcmp(op, "delete") == 0) {
			int pos; scanf("%d", &pos);
			if (pos - 1 < l.size()) {
				auto it = l.begin();
				advance(it, pos - 1);
				l.erase(it);
				printf("delete OK\n");
			}
			else {
				printf("delete fail\n");
			}
		}
		else if (strcmp(op, "show") == 0) {
			if (!l.empty()) {
				for (auto i = l.begin(); i != l.end(); ++i) {
					if (l.end()-- == i) {
						printf("%d", *i);
					}
					else
					printf("%d ", *i);
				}
				printf("\n");
			}
			else {
				printf("Link list is empty\n");
			}
		}
	}
}

