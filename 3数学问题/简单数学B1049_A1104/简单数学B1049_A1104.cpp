// 简单数学B1049_A1104.cpp
//

#include <cstdio>
using namespace std;

int main()
{
	size_t n; scanf("%ud", &n);
	double ans = 0.0;
	for (size_t i=0; i<n; i++) {
		// 对于i位置的数字，这个数字必定被包含在这个连续组合中。
		// 左侧有i个数字，则向左延伸，左侧连续组合有i+1种可能（其中一种左侧为空）
		// 右侧有n-(i+1)=n-i-1个数字，则左侧连续组合有n-i种可能（其中一种右侧为空）
		// 结合左右两侧，相乘。
		double times = (i+1u) * (n-i); // 注意：此处不能用int，会溢出。也可以long long，推荐直接用double
		static double t;
		scanf("%lf", &t);
		// printf("%f appears %d times\n", t, times);
		ans += t * times;
	}
	printf("%.2f", ans);
}

