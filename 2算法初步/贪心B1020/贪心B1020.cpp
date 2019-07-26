// 贪心B1020.cpp
// 简单贪心

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

struct Good {
	// 注意，全部都要是double，题目只说正数没说整数
	double stock; // 万吨
	double totalPrice; // 亿元
	double price; // 元/吨(万元/万吨)
};

int main()
{
	int n, d; cin >> n >> d;
	vector<Good> goods(n);
	for (int i = 0; i < n; i++) {
		cin >> goods[i].stock;
	}
	for (int i = 0; i < n; i++) {
		cin >> goods[i].totalPrice;
		goods[i].price = goods[i].totalPrice*10000.0/ goods[i].stock;
	}
	sort(goods.begin(), goods.end(), [](Good& a, Good& b) {return a.price > b.price; });
	double profit = 0.0;
	int rd = d;
	for (Good& g : goods) {
		if (g.stock > rd) {
			profit += rd*g.price / 10000.0;
			break;
		}
		rd -= g.stock;
		profit += g.totalPrice;
	}
	cout << fixed << setprecision(2) << profit << endl;
}

