// 散列B1039_A1092.cpp
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
	cin.sync_with_stdio(false); cout.sync_with_stdio(false); // 加快io速度, 散列题比较要求速度，最好调用
	string s1, s2; getline(cin, s1); getline(cin, s2);
	unordered_map<char, int> has;
	for (char& c : s1) {
		has[c]++;
	}
	for (char& c : s2) {
		has[c]--;
	}
	int redun = 0, miss = 0;
	for (auto& p : has) {
		if (p.second < 0) {
			miss -= p.second;
		}
		else if (p.second > 0) {
			redun += p.second;
		}
	}
	if (miss == 0) {
		cout << "Yes " << redun << endl;
	}
	else {
		cout << "No " << miss << endl;
	}
}

