// 散列B1005.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	unordered_set<int> covered;
	vector<int> seq;
	{
		int n, t; cin >> n; seq.reserve(n);
		while (n--) {
			cin >> t;
			seq.push_back(t);
		}
	}
	sort(seq.begin(), seq.end(), greater<int>());
	for (int num : seq) {
		while (num != 1) {
			if (num % 2 == 0) {
				num /= 2;
			}
			else {
				num += (num+1) / 2;
			}
			if (covered.count(num)) {
				break; // infer that's true
			}
			covered.insert(num);
		}
	}
	bool first = true;
	for (int i = 0; i < seq.size(); i++) {
		if (!covered.count(seq[i])) {
			if (!first) {
				cout << " ";
			}
			first = false;
			cout << seq[i];
		}
	}
}