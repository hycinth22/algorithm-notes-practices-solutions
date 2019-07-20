// B1021个位数统计.cpp
//

#include <iostream>
#include <map>
using namespace std;

int main()
{
	string n; cin >> n;
	map<char, int> m;
	for (char c : n) {
		m[c]++;
	}
	for (auto pair : m) {
		cout << pair.first << ":" << pair.second << endl;
	}
}

