// 字符串处理A1001.cpp
//

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
	int a, b; cin >> a >> b;
	int sum = a + b;
	if (sum < 0) { // 注意负数
		cout << "-";
		sum = -sum;
	}
	if (sum < 1000) {
		cout << sum << endl;
		return 0;
	}
	vector<int> v;
	while (sum != 0) {
		v.push_back(sum%1000);
		sum /= 1000;
	}
	auto it = v.crbegin();
	cout << *it++;
	for (; it != v.crend(); ++it) {
		cout << "," << setw(3) << setfill('0') << *it;
	}
}

