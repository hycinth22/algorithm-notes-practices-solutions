// 模板.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <map>
#include <string>
#include <utility>
using namespace std;

typedef struct {
	string cardID;
	int testID;
	int examID;
} student;

int main()
{
	int n; cin >> n;
	map<int, student> m;
	while (n--) {
		string cardID; cin >> cardID;
		int testID; cin >> testID;
		int examID; cin >> examID;
		m.emplace(make_pair(testID, student{ cardID, testID, examID }));
	}

	cin >> n;
	while (n--) {
		int testID; cin >> testID;
		cout << m[testID].cardID  << " " << m[testID].examID << endl;
	}
}

