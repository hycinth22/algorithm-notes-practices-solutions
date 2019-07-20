// 排列B1015.cpp
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct testee {
	int id;
	int scoreDe;
	int scoreCai;
	int clazz;
};

// 1德才过H、2德过H才过L、3德过L才过L但德不低于才、4德才均过L
int classify(const testee& a, int h) {
	if (a.scoreDe >= h && a.scoreCai >= h) {
		return 1;
	}
	else if (a.scoreDe >= h) {
		return 2;
	}
	else if (a.scoreDe >= a.scoreCai) {
		return 3;
	}
	return 4;
}

int main()
{
	int n, l, h; cin >> n >> l >> h;
	vector<testee> v;
	v.reserve(n);
	testee t;
	while (n--) {
		cin >> t.id >> t.scoreDe >> t.scoreCai;
		if (t.scoreDe >= l &&  t.scoreCai >= l) {
			t.clazz = classify(t, h);
			v.push_back(t);
		}
	}
	sort(v.begin(), v.end(), [](const testee& a, const testee& b) {
		if (a.clazz != b.clazz) {
			return a.clazz < b.clazz;
		}
		int totalScoreA = a.scoreDe + a.scoreCai,
			totalScoreB = b.scoreDe + b.scoreCai;
		if (totalScoreA != totalScoreB) {
			return totalScoreA > totalScoreB;
		}
		if (a.scoreDe != b.scoreDe) {
			return a.scoreDe > b.scoreDe;
		}
		return a.id < b.id;
		});
	cout << v.size() << endl;
	for (testee& t : v) {
		cout << t.id << " " << t.scoreDe << " " << t.scoreCai << endl;
	}
}

