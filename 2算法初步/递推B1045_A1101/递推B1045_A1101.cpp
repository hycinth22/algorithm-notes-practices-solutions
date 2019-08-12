// 递推B1045_A1101.cpp
// 200 ms 如果直接暴力扫描O(n^2)超时，需要优化
// 此题利用递推关系优化为O(n)

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	vector<int> d(n);
	for (int i = 0; i < n;i++) {
		scanf("%d", &d[i]);
	}
	vector<int> leftMax(n), rightMin(n); // 左侧最大元素（含当前位），右侧最小元素（含当前位）
	if (!leftMax.empty())
	{
		assert(leftMax.size() == d.size());
		// 利用递推关系显著降低复杂度
		leftMax[0] = d[0];
		for (int i = 1; i < n; i++) {
			leftMax[i] = max(leftMax[i - 1], d[i]);
		}
	}
	if (!rightMin.empty())
	{
		// 利用递推关系显著降低复杂度
		assert(rightMin.size() == d.size());
		rightMin.back() = d.back();
		for (int i = rightMin.size()-2; i >=0; i--) {
			rightMin[i] = min(d[i], rightMin[i + 1]);
		}
	}
	int ans = 0; vector<int> results;
	for (int i = 0; i < n; i++) {
		// 只需要d[i]等于左侧（含自身）最大的元素（也即d[i]大于左侧（不含自身）最大的元素），即可判断d[i]大于左侧所有元素
		// 只需要d[i]等于右侧（含自身）最小的元素（也即d[i]小于右侧（不含自身）最小的元素），即可判断d[i]小于右侧所有元素
		if (leftMax[i]==d[i] && rightMin[i]==d[i]) {
			ans++;
			results.push_back(d[i]);
		}
	}
	printf("%d\n", ans);
	if (!results.empty()) {
		printf("%d", results[0]);
		for (size_t i = 1; i < ans; i++) {
			printf(" %d", results[i]);
		}
	}
	printf("\n");
}

