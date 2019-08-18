// vector_A1047.cpp
//

#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

vector<char*> stunames;
struct cmp {
	bool operator()(const int& a, const int& b) const {
		return strcmp(stunames[a], stunames[b]) < 0; 
	};
};
 
int main()
{
	int n, k; scanf("%d%d", &n, &k); 
	stunames.resize(n + 1); // index 0 is unused
	vector < vector<int> > courseStu(k + 1); // index 0 is unused
	for (int i = 1; i <= n; i++) {
		// cin >> stunames[i];
		static int c; //cin >> c;
		stunames[i] = new char[5];
		scanf("%4s%d", stunames[i], &c);
		for (int j = 1; j <= c; j++) {
			int cid; // cin >> cid;
			scanf("%d", &cid);
			courseStu[cid].push_back(i);
		}
	}
	// index 0 is unused, so intentionally ignored
	for (int i = 1; i <= k; i++) {
		// cid == i
		printf("%d %u\n", i, courseStu[i].size());
		//cout << i << " " << courseStu[i].size() << endl;
		sort(courseStu[i].begin(), courseStu[i].end(), cmp());
		for (const int& stuid : courseStu[i]) {
			//cout << stunames[stuid] << endl;
			printf("%4s\n", stunames[stuid]);
		}
	}
}

