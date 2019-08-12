// 递推B1040_A1093.cpp
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	const size_t m = 1000000007;
	string str; getline(cin, str);
	size_t nChar = str.size();
	// 要查询的只有三位字符PAT，因此我们可以统计每一位左侧的P数量nP和右侧的T数量nT。然后对每一位A，乘以左侧P数量nP乘以右侧T数量nT。
	// 根据题目条件64 MB内存足以存放这些数据。
	vector<size_t> nP(nChar), nT(nChar); // 左侧P数量（不含当前位），右侧T数量（不含当前位）
	if (!nP.empty()) {
		nP[0] = 0u;
		for (size_t i = 1; i < nP.size(); i++) {
			// 利用递推显著降低时间
			if (str[i - 1] == 'P') {
				nP[i] = nP[i - 1] + 1;
			}
			else {
				nP[i] = nP[i - 1];
			}
		}
	}
	size_t ans = 0;
	if (!nT.empty()) {
		nT.back() = 0u;
		for (int i = nT.size()-2; i >=0; i--) {
			// 利用递推显著降低时间
			if (str[i + 1] == 'T') {
				nT[i] = nT[i + 1] + 1;
			}
			else {
				nT[i] = nT[i + 1];
			}
			// 此时已经可以得出结论，顺便也扫描A，可以少一次循环遍历。
			if (str[i] == 'A') {
				ans += (nP[i] * nT[i]) % m; // 不要忘记取模
			}
		}
	}
	cout << ans;
}


 