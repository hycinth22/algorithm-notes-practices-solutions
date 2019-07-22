// 排序A1083.cpp
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct student {
	string name, id;
	int grade;
};

int main()
{
	int n; cin >> n;
	vector<student> v; v.reserve(n);
	while (n--) {
		static student t;
		cin >> t.name >> t.id >> t.grade;
		v.push_back(t);
	}
	int grade1, grade2; cin >> grade1 >> grade2;
	auto begin = v.begin();
	auto end = partition(v.begin(), v.end(), [grade1, grade2](const student &s) {
		return s.grade >= grade1 && s.grade <= grade2;
		});
	if (begin == end) {
		cout << "NONE" << endl;
		return 0;
	}
	sort(begin, end, [](const student& a, const student& b) {
		return a.grade > b.grade;
	});
	for (auto it = begin; it != end; ++it) {
		cout << it->name << " " << it->id << endl;
	}
}

