// 排序A1025.cpp
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct testee {
	string id;
	int score;
	int location_number;
	int local_rank, total_rank;
	bool operator<(const testee& b) {
		if (score != b.score) {
			return score > b.score;
		}
		return id < b.id;
	}
};

int main()
{
	int n; cin >> n;
	vector<testee> v;
	vector<testee>::size_type locbegin, locend = 0;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		locbegin = locend;
		while (k--) {
			testee t; cin >> t.id >> t.score;
			t.location_number = i;
			v.push_back(t);
		}
		locend = v.size();
		sort(v.data() + locbegin , v.data() + locend);
		int rankcnt = 1;
		for (auto i = locbegin; i != locend; ++i) {
			if (i != locbegin && v[i].score == v[i - 1].score) {
				v[i].local_rank = v[i - 1].local_rank;
			}
			else {
				v[i].local_rank = rankcnt;
			}
			rankcnt++;
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << endl;
	int totalrank = 1;
	for (size_t i = 0; i < v.size(); i++) {
		testee& t = v[i];
		if (i != 0 && t.score==v[i-1].score) {
			t.total_rank = v[i - 1].total_rank;
		}
		else {
			t.total_rank = totalrank;
		}
		cout << t.id << " " << t.total_rank
			<< " " << t.location_number
			<< " " << t.local_rank
			<< endl;
		totalrank++;
	}
}

