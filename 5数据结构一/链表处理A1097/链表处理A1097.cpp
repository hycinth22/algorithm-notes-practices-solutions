// 链表处理A1097.cpp
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	int head; int n; cin >> head >> n;
	unordered_map<int, pair<int, int> > m;
	for (int i = 0; i < n; i++) {
		int addr, key, next; cin >> addr >> key >> next;
		m[addr].first = key;
		m[addr].second = next;
	}
	// 逻辑关系线性化
	vector<int> seq1 , seq2;
	unordered_set<int> keys;
	int cur = head;
	while (cur != -1) {
		auto& node = m.at(cur);
		int key = abs(node.first);
		if (keys.count(key)) {
			seq2.push_back(cur);
		}
		else {
			seq1.push_back(cur);
			keys.insert(key);
		}
		cur = m.at(cur).second;
	}
	// 输出。注意事项同A1052
	if (!seq1.empty()) {
		for (size_t i = 0; i < seq1.size() - 1; i++) {
			printf("%05d %d %05d\n", seq1[i], m.at(seq1[i]).first, seq1[i+1]);
		}
		printf("%05d %d -1\n", seq1.back(), m.at(seq1.back()).first);
	}
	if (!seq2.empty()) {
		for (size_t i = 0; i < seq2.size() - 1; i++) {
			printf("%05d %d %05d\n", seq2[i], m.at(seq2[i]).first, seq2[i + 1]);
		}
		printf("%05d %d -1\n", seq2.back(), m.at(seq2.back()).first);
	}
}

