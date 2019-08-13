// 简单数学A1049.cpp
// 关于上限数字限制：先确定高位，再确定低位。
// 高位没有达到最大值，低位可以就取进制内任意数；高位数字到达最大值时，低位也会受限于最大值
// 从高到低（左、当前、右），只有先确定了高位的取值，才能确定低位数字的取值范围。

#include <iostream>
#include <cmath>
using namespace std;


int f(int n, int base = 10) {
	int weight = 1, ans = 0;
	// 逐位计算，1-n的过程中，每一位取1的次数。
	// （两侧排列数的变种，区别是：最大数字n影响，高位没有达到最大值，低位可以取进制内任意数；高位数字到达最大值时，低位也会受限于最大值）
	while (n >= weight) {
		int leftMax = n / weight / base;
		int curPosMax = n / weight % base; // 当前位
		int rightMax = n % weight;
		if (curPosMax == 0) {
			// 最大数的此位为0，则左侧取最大时，此位取不到1  -> 左侧取[00..00, leftMax)时此位可以取1 -> 左侧共有leftMax种方案可以使此位取1
			// 左侧取上述值，且当前位取1时，
			// 对于右侧而言，高位（左+中）未达上限，右侧可取所有值
			// 右侧可以取[00..00, 99..99] -> 右侧共有weight种方案可以使此位取1
			// 共leftMax*weight种
			ans += leftMax * weight; // 左侧有leftMax种可能性。
		}
		else if (curPosMax == 1) {
			// 最大数的此位为1，则左侧取最大时，此位可以取到1 -> // 左侧取[00..00, leftMax]时此位可以取1 -> 左侧共有leftMax+1种方案可以使此位取1

			// 由于左侧是否取最大值，右侧取值范围不同。将左侧[00..00, leftMax]分为取[00..00, leftMax)和取leftMax再次分别讨论

			// 左侧取[00..00, leftMax)，且当前位取1时，
			// 对于右侧而言，高位（左+中）未达上限，右侧可取所有值
			// 右侧可以取[00..00, 99..99] -> 右侧共有weight种方案可以使此位取1
			// 共leftMax*weight种
			 
			// 左侧取leftMax，且当前位取1时，
			// 对于右侧而言，高位（左+中）已上限，右侧可取right为上限的值。
			// 右侧取[00..00, rightMax]时此位可以取1 -> 右侧共有rightMax+1种方案可以使此位取1
			// 共1*(rightMax+1)=rightMax+1种方案

			// 结合上面两种子情况，共有leftMax*weight+rightMax+1种
			ans += leftMax * weight + rightMax + 1;
		}
		else {
			// 最大数的此位>=2，则左侧取最大时，此位可以取到1 -> 左侧取[00..00, leftMax]时此位可以取1 -> 左侧共有leftMax+1种方案可以使此位取1
			// 左侧取上述值，且当前位取1时，
			// 对于右侧而言，高位（左+中）未达上限，右侧可取所有值
			// 右侧可以取[00..00, 99..99] -> 右侧共有weight种方案可以使此位取1
			ans += (leftMax + 1) * weight;
		}
		weight *= base;
	}
	return ans;
}

int main()
{
	int n; cin >> n;
	cout << f(n) << endl;
}

