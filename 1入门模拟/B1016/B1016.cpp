// B1016.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

int main()
{
	unsigned long long a, da, b, db; cin >> a >> da >> b >> db;
	unsigned long long pa = 0, pb = 0;
	while (a > 0) {
		if (a % 10 == da) {
			pa = pa * 10 + da;
		}
		a /= 10;
	}
	while (b > 0) {
		if (b % 10 == db) {
			pb = pb * 10 + db;
		}
		b /= 10;
	}
	cout << pa + pb << endl;
}