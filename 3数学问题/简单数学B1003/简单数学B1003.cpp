// 简单数学B1003.cpp
//

#include <iostream>
#include <string>
using namespace std;

bool f(const string& str) {
	size_t left = 0, mid = 0, right = 0;
	size_t i = 0, n = str.size();
	while (i < n && str[i]=='A') {
		left++;
		i++;
	}
	if (str[i]!='P') {
		return false;
	}
	i++;
	while (i < n && str[i] == 'A') {
		mid++;
		i++;
	}
	if (str[i] != 'T') {
		return false;
	}
	i++;
	while (i < n && str[i] == 'A') {
		right++;
		i++;
	}
	if (i!=n) {
		return false;
	}
	while (mid > 0) {
		// case 1 & 2，注意题意中左右都是x，必须相等
		if (mid == 1 && left==right) {
			return true;
		}
		// case 3
		else if (right >= left && mid > 0) {
			right -= left;
			mid--;
		}
		else {
			break; // 没有变化，则直接中断（否则死循环）
		}
	}
	return false;
}

int main()
{
	int n; cin >> n; cin.get();
	while (n--) {
		string str;
		getline(cin, str);
		cout << (f(str) ? "YES" : "NO") << endl;
	}
}

