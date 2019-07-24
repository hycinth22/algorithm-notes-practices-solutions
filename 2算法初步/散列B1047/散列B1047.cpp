// 散列B1047.cpp
//

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
	cin.sync_with_stdio(0); cout.sync_with_stdio(0);
	int n; cin >> n;
	unordered_map<int, int> v;
	while (n--) {
		int team, pep, score;
		cin >> team; cin.get();
		cin >> pep;
		cin >> score;
		// 此处用哈希表可以O(1)时间完成累加，则整体O(n)
		// 如果用顺序容器，每次循环都需要嵌套遍历逐个判来找到要为哪个元素增加，时间复杂度过高O(n^2)。
		v[team] += score;
	}
	// 遍历哈希表查找最大值，唯一冠军可以直接调用函数
	auto p = max_element(v.cbegin(), v.cend(), [](auto& a, auto& b) {
		return a.second < b.second;
	});
	cout << p->first << " " << p->second;
} 

