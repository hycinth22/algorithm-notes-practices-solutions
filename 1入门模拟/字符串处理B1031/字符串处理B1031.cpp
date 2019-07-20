// ﻿// 字符串处理B1031.cpp
//

#include <iostream>
#include <string>
using namespace std;


bool verifyID(const string& id) {
	const int contentLength = 17, verifylength = 1;
	const int length = contentLength + verifylength;
	if (id.size() != length) {
		return false;
	}
	int sum = 0; 
	{
		const int weight[contentLength] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
		for (string::size_type i = 0; i < contentLength; i++) {
			sum += (id[i] - '0') * weight[i];
			//cout << (id[i] - '0') << "*"<<weight[i] << endl;
		}
	}
	const int maxZ = 11;
	int z = sum % maxZ;
	const char zmRelation[maxZ] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
	char m = zmRelation[z];
	char expectM = id.back();
	return m == expectM;
}

int main()
{
	int n; cin >> n;
	int cnt = 0;
	cin.get(); // notice this
	while (n--) {
		string id; getline(cin, id);
		if (!verifyID(id)) {
			cout << id << endl;
			cnt++;
		}
	}
	if (cnt == 0) {
		cout << "All passed" << endl;
	}
}

