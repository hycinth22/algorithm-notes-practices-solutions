// map_set_A1039.cpp
//

#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main()
{
	// 循环内static变量是为了节省时间，防止反复申请空间，及防止大型类（如string）反复运行构造/析构函数
	int n, k; cin >> n >> k;
	map<string, set<int>> courses;
	for (int i = 1; i <= k; i++) {
		static int cid, nStu; cin >> cid >> nStu;
		for (int i = 1; i <= nStu; i++) {
			static string stu; cin >> stu;
			courses[stu].insert(cid);
		}
	}
	for (int i = 1; i <= n; i++) {
		static string stu; cin >> stu;
		cout << stu << " ";
		if (courses.count(stu)) {
			cout << courses[stu].size();
			for (const int& cid : courses[stu]) {
				cout << " " << cid;
			}
		}
		else {
			cout << "0";
		}
		cout << endl;
	}
}