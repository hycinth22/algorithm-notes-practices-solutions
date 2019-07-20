// 查找元素B1027.cpp
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const char spaceChar = ' ';
	int total; char fillChar; cin >> total >> fillChar;
	int used = 0;
	int cntBar = sqrt(2 * (1 + total)) - 1;
	for (int k = cntBar; k > 0; k -= 2) {
		used += k;
		int cntSpace = (cntBar - k) / 2;
		for (int i = 0; i < cntSpace; i++) {
			cout << spaceChar;
		}
		for (int i = 0; i < k; i++) {
			cout << fillChar;
		}
		cout << endl;
	}
	for (int k = 3; k <= cntBar; k += 2) {
		used += k;
		int cntSpace = (cntBar - k) / 2;
		for (int i = 0; i < cntSpace; i++) {
			cout << spaceChar;
		}
		for (int i = 0; i < k; i++) {
			cout << fillChar;
		}
		cout << endl;
	}
	cout << total-used << endl;
}

