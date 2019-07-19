// 查找元素B1028.cpp
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct {
	string name;
	int year, month, day;
} person;

bool isValid(int year, int month, int day) {
	const int todayYear = 2014, todayMonth = 9, todayDay = 6;
	// not born
	if (year > todayYear) {
		return false;
	}
	else if (year == todayYear) {
		if (month > todayMonth) {
			return false;
		}
		else if (month == todayMonth) {
			if (day > todayDay) {
				return false;
			}
		}
	}
	// over 200 years old
	if (todayYear - year > 200) {
		return false;
	}
	else if (todayYear - year == 200) {
		if (month < todayMonth) {
			return false;
		}
		else if (month == todayMonth) {
			if (day < todayDay) {
				return false;
			}
		}
	}
	return true;
}

bool personCompare(const person &l, const person& r) {
	if (l.year != r.year) {
		return l.year > r.year;
	}
	else {
		if (l.month != r.month) {
			return l.month > r.month;
		}
		else {
			return l.day > r.day;
		}
	}
}

int main()
{
	/*istringstream cin(R"(5
John 2001/05/12
Tom 1814/09/06
Ann 2121/01/30
James 1814/09/05
Steve 1967/11/20)");*/


	int n; cin >> n;
	vector<person> all;
	while (n--) {
		string name;
		int year, month, day;
		cin >> name;
		cin >> year; cin.get();
		cin >> month; cin.get();
		cin >> day; 
		if (isValid(year, month, day)) {
			all.push_back({ name, year, month, day });
		}
	}
	cout << all.size();
	if (!all.empty()) { // 特例！！ empty时返回结果为end迭代器，进而会出错
		cout  << " "
			<< max_element(all.cbegin(), all.cend(), personCompare)->name << " "
			<< min_element(all.cbegin(), all.cend(), personCompare)->name;
	}

}

