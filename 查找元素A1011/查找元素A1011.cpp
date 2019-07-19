// 查找元素A1011.cpp
//

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
using namespace std;

/*
1.1 2.5 1.7
1.2 3.0 1.6
4.1 1.2 1.1

T T W 37.98
*/
int main()
{
	const int N = 3;
	const double fee = 2.0;
	const double hitrate = 0.65;

	double maxrate[N];
	char maxratewhat[N];

	int n = N;
	int i = 0;
	while (n--) {
		double win, tie, lost; cin >> win >> tie >> lost;
		if (win >= tie && win >= lost) {
			maxrate[i] = win;
			maxratewhat[i] = 'W';
		}
		else {
			if (tie >= lost) {
				maxrate[i] = tie;
				maxratewhat[i] = 'T';
			}
			else {
				maxrate[i] = lost;
				maxratewhat[i] = 'L';
			}
		}
		i++;
	}
	cout << maxratewhat[0] << " " << maxratewhat[1] << " " << maxratewhat[2] << " "
		<< fixed << setprecision(2) << (maxrate[0]* maxrate[1] * maxrate[2]* hitrate-1)*fee << endl; 
	// 四舍五入错误 实际37.9750被舍入为37.97，与样例不同
	// 查看标准没有问题，暂时怀疑是编译器实现问题
}

