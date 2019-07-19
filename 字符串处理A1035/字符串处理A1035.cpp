// 字符串处理A1035.cpp
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

using account = struct {
	string username;
	string password;
};

int main()
{
	int n; cin >> n;
	vector<account> modified;
	for (int i = 0; i < n; i++) {
		account acc; cin >> acc.username >> acc.password;
		bool modifiedFlag = false;
		if (n != 1) {
			for (char& c : acc.password) {
				const char replaceGroup[][2] = {
					{'1', '@'}, {'0', '%'},
					{'l' , 'L'}, {'O', 'o'},
				};
				for (auto replace : replaceGroup) {
					if (c == replace[0]) {
						c = replace[1];
						modifiedFlag = true;
					}
				}
			}
		}
		if (modifiedFlag) {
			modified.push_back(acc);
		}
	}
	size_t cntModified = modified.size();
	if (cntModified == 0) {
		if (n == 1) { // 注意1的单独处理，单复数不同(is/are account/accounts)
			cout << "There is 1 account and no account is modified" << endl;
		}
		else {
			cout << "There are " << n << " accounts and no account is modified" << endl;
		}
	}
	else {
		cout << cntModified << endl;
		for (auto m : modified) {
			cout << m.username << " " << m.password << endl;
		}
	}
}

