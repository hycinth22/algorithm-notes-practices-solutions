// algorithm_codeup100000604A.cpp
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	// 注意多组数据
	while (cin >> n) {
		vector<int> v; v.reserve(n);
		for (int i = 0; i < n;i++) {
			int k;
			cin >> k;
			v.push_back(k);
		}
		sort(v.begin(), v.end());
		cout << v.back() << " " << v.front() << endl; // 注意换行
	}	
}

