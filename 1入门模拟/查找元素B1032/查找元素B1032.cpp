// 查找元素B1032.cpp
//

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	int n; cin >> n;
	map<int, int, greater<int> > scores;
	while (n--) {
		int id, score; cin >> id >> score;
		scores[id] += score;
	}
	if (!scores.empty()) {
		auto highest = max_element(scores.cbegin(), scores.cend(), 
			[](map<int, int, greater<int> >::value_type a, map<int, int, greater<int> >::value_type b)
			{
				return a.second < b.second;
			});
		cout << highest->first << " " << highest->second;
	}
	
}

