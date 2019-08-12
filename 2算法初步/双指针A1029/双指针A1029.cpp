// 双指针A1029.cpp
// incompleted
// 目前可以通过所有测试点，但是题目要求是输入long（当前代码改为long会爆内存）
//
// 下一步优化重点：由于中位数不可能存在于两个序列的前半部分，因此可以不保存前半部分。
// 但是这样需要更改后续的索引偏移量。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.sync_with_stdio(0);

	size_t n1; cin >> n1;
	vector<int> d1(n1); // 注意题目说明，在long范围内
	for (size_t i = 0; i < n1; i++) {
		cin >> d1[i];
	}


	size_t n2; cin >> n2;
	size_t midIndex = (n1+n2-1) / 2;    clog << "midIndex" << midIndex << endl;
	// 边输入边处理
	size_t i1 = 0, cnt = 0;
	int ans = 0;
	for (size_t i = 0; i < n2; i++) {
		static int t;
		cin >> t;

		while (cnt <= midIndex && i1 < n1 && d1[i1] < t) {
			clog << cnt << " " << d1[i1] << " from d1" << endl;
			if (cnt == midIndex) {
				ans = d1[i1];
				goto out;
			}
			cnt++;
			i1++;
		}

		clog << cnt << " " << t << " from d2" << endl;
		if (cnt == midIndex) {
			ans = t;
			goto out;
		}
		cnt++;
	}
	while (cnt <= midIndex) {
		if (cnt == midIndex) {
			ans = d1[i1];
			goto out;
		}
		cnt++;
		i1++;
	}
	out:
	cout << ans << endl;
}


/*
没有空间限制的偷懒做法
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n1; cin >> n1;
	vector<long> d1(n1);
	for (auto& t : d1) {
		cin >> t;
	}

	int n2; cin >> n2;
	vector<long> d2(n2);
	for (auto& t : d2) {
		cin >> t;
	}
	vector<long> r(n1+n2);
	inplace_merge(d1.cbegin(), d1.cend(), d2.cbegin(), d2.cend(), r.begin());
	cout << r[(n1 + n2) / 2];
}

*/