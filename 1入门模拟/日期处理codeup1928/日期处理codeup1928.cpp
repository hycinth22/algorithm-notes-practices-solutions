// 日期处理codeup1928.cpp
//
#include <cstdio>
#include <utility>
using namespace std;

const int normalYear_monthDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int leapYear_monthDays[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

inline bool isLeapYear(int year) {
	return ((year % 4 == 0 && year % 100 != 0)
		|| (year % 400 == 0)
		);
}
inline int getMonthDaysCnt(int y, int m) {
	return isLeapYear(y) ? leapYear_monthDays[m - 1] : normalYear_monthDays[m - 1];
}
inline int getYearDaysCnt(int y) {
	return isLeapYear(y) ? 366 : 365;
}

struct date{
	int y, m, d;
	bool operator<(const date& rhs) {
		if (y != rhs.y) {
			return y < rhs.y;
		}
		if (m != rhs.m) {
			return m < rhs.m;
		}
		return d < rhs.d;
	}
};

int main()
{
	date a, b;
	scanf("%4d%2d%2d", &a.y, &a.m, &a.d);
	scanf("%4d%2d%2d", &b.y, &b.m, &b.d);

	// make sure that a<b 
	if (b < a) {
		swap(a, b);
	}
	// calculate
	int sum = 0;
	// year part
	if (a.y != b.y) {
		// 不同年
		sum += getMonthDaysCnt(a.y, a.m) - a.d + 1; // reach month end
		for (int m = a.m + 1; m <= 12; m++) {
			sum += getMonthDaysCnt(a.y, m);
		} // whole months
		for (int y = a.y+1; y < b.y; y++) {
			sum += getYearDaysCnt(y);
		} // whole years
		for (int m = 1; m < b.m; m++) {
			sum += getMonthDaysCnt(b.y, m);
		} // whole months
		sum += b.d;
	}
	else {
		if (a.m != b.m) {
			// 同年不同月
			sum += getMonthDaysCnt(a.y, a.m) - a.d + 1; // reach month end
			for (int m = a.m+1; m < b.m; m++) {
				sum += getMonthDaysCnt(a.y, m);
			} // whole months
			sum += b.d;
		}
		else {
			// 同年同月
			sum += (b.d - a.d + 1);
		}
	}
	printf("%d", sum);
}

