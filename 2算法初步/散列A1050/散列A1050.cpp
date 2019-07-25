// 散列A1050.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main()
{
	string s1; getline(cin, s1);
	unordered_set<char> extract;
	for (char ch = cin.get(); ch != '\n'; ch = cin.get()) {
		extract.insert(ch);
	}
	string result; result.reserve(s1.size());
	for (char& c : s1) {
		if (extract.count(c) == 0) {
			result.append(1, c);
		}
	}
	cout << result << endl;
}