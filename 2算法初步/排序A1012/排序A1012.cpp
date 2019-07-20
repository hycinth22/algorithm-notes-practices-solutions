// 排序A1012.cpp
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct testee {
	int id;
	int c, m, e;
	double a;
	int bestrank;
	char bestSubject;
};

int main()
{
	int n, m; cin >> n >> m;
	vector<testee> v; v.reserve(n);
	{
		testee t;
		while (n--) {
			cin >> t.id >> t.c >> t.m >> t.e;
			t.a = round((t.c + t.m + t.e) / 3);
			v.push_back(t);
		}
	}
	// sort by a and update
	sort(v.begin(), v.end(), [](auto a, auto b) {
		return a.a > b.a;
	});
	int cnt = 1;
	int lastscore = -1, lastrank = -1;
	for (auto&t : v) {
		int realrank = cnt;
		if (t.a == lastscore) {
			realrank = lastrank;
		}
		t.bestrank = realrank;
		t.bestSubject = 'A';
		cnt++;
		lastscore = t.a;
		lastrank = realrank;
	}
	// sort by c and update
	sort(v.begin(), v.end(), [](auto a, auto b) {
		return a.c > b.c;
		});
	cnt = 1;
	lastscore = -1, lastrank = -1;
	for (auto& t : v) {
		int realrank = cnt;
		if (t.c == lastscore) {
			realrank = lastrank;
		}
		if (realrank < t.bestrank) {
			t.bestrank = realrank;
			t.bestSubject = 'C';
		}
		cnt++;
		lastscore = t.c;
		lastrank = realrank;
	}
	// sort by m and update
	sort(v.begin(), v.end(), [](auto a, auto b) {
		return a.m > b.m;
		});
	cnt = 1;
	lastscore = -1, lastrank = -1;
	for (auto& t : v) {
		int realrank = cnt;
		if (t.m == lastscore) {
			realrank = lastrank;
		}
		if (realrank < t.bestrank) {
			t.bestrank = realrank;
			t.bestSubject = 'M';
		}
		cnt++;
		lastscore = t.m;
		lastrank = realrank;
	}
	// sort by e and update
	sort(v.begin(), v.end(), [](auto a, auto b) {
		return a.e > b.e;
		});
	cnt = 1;
	lastscore = -1, lastrank = -1;
	for (auto& t : v) {
		int realrank = cnt;
		if (t.e == lastscore) {
			realrank = lastrank;
		}
		if (realrank < t.bestrank) {
			t.bestrank = realrank;
			t.bestSubject = 'E';
		}
		cnt++;
		lastscore = t.e;
		lastrank = realrank;
	}
	while (m--) {
		int id; cin >> id;
		bool found = false;
		int bestrank; char bestSubject;
		for (auto& t : v) {
			if (t.id == id) {
				bestrank = t.bestrank;
				bestSubject = t.bestSubject;
				found = true;
				break;
			}
		}
		if (found) {
			cout << bestrank << " " << bestSubject << endl;
		}
		else {
			cout << "N/A" << endl;
		}
	}
}

