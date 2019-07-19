// 字符串处理B1009.cpp
//

#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
	vector<string> v;
	string t;
	while (cin >> t) {
		v.push_back(t);
	}
	//ostream_iterator会在每个后面都插入分隔符，因此特别处理最后一个
	auto end = --v.crend();
	copy(v.crbegin(), end, ostream_iterator<string>(cout, " "));
	cout << *end;
}

