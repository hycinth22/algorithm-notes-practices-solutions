// 散列B1038.cpp
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype>
using namespace std;

int main()
{
	cin.sync_with_stdio(false); cout.sync_with_stdio(false); // 加快io速度, 散列题比较要求速度，最好调用
	unordered_map<int, int> v;
	int n; cin >> n;
	// 这种写法适用于这种较简单的题目，循环结束后n是-1
	while (n--) {
		int score; cin >> score;
		v[score]++;
	}
	int k; cin >> k;
	if (k > 0) {
		int score; cin >> score;
		cout << v[score];
		--k;
	}
	while (k--) {
		int score; cin >> score;
		cout << " " << v[score];
	}
}

