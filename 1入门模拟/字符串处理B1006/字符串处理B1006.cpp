// 字符串处理B1006.cpp
//

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n; cin >> n;
	int t = n;
	string result;
	for (int i = t % 10; i > 0 ; i--) {
		result.insert(0, 1, '0' + i);
	}
	t /= 10;
	if (t > 0) {
		result.insert(0, t%10, 'S');
	}
	t /= 10;
	if (t > 0) {
		result.insert(0, t % 10, 'B');
	}
	cout << result << endl;
}

