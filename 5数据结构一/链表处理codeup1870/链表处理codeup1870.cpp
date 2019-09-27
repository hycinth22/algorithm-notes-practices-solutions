// 链表处理codeup1870.cpp
// codeup Contest100000607 

#include <cstdio>
#include <list>
using namespace std;

struct stu{
	stu(const int& number, const int& score)
		: number(number), score(score)
	{}
	int number;
	int score;
	bool operator<(stu& stu) {
		return number < stu.number;
	}
};
int main()
{
	list<stu> l1, l2;
	int n, m; scanf("%d%d", &n, &m);
	while (n--) {
		int n, g; scanf("%d%d", &n, &g);
		l1.emplace_back(n, g);
	}
	while (m--) {
		int n, g; scanf("%d%d", &n, &g);
		l2.emplace_back(n, g);
	}
	l1.splice(l1.end(), l2);
	l1.sort();
	for (auto& o:l1) {
		printf("%d %d\n", o.number, o.score);
	}
}

