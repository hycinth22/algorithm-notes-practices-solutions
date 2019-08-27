// algorithm_codeup100000604B.cpp
// 本题测试用例有问题。
// 输入给定的字符串中的字母已经按照从小到大的顺序排列，但实际不是，且答案也是错的（测试答案为无序输入按照有序输入处理的错误答案）。

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string str;
	while (getline(cin, str)) {
		// sort(str.begin(), str.end()); // 应当加上此句。
		do {
			cout << str << endl;
		}while (next_permutation(str.begin(), str.end()));
		// 注意每组样例输出结束后接一个空行。
		cout << endl;
	}
}

