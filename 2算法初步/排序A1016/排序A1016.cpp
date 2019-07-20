// 排序A1016.cpp
// still cannot pass all case
// Todo: pass case 3/4

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm> 
using namespace std;

struct Date {
	int month = 0, day = 0;
	int hour = 0, minute = 0;
	bool operator==(const Date& rhs) const {
		return month == rhs.month &&
			day == rhs.day &&
			hour == rhs.hour &&
			minute == rhs.minute;
	}
	bool operator!=(const Date& rhs) const {
		return !operator==(rhs);
	}
	bool operator<(const Date& rhs) const {
		if (month != rhs.month) {
			return month < rhs.month;
		}
		if (day != rhs.day) {
			return day < rhs.day;
		}
		if (hour != rhs.hour) {
			return hour < rhs.hour;
		}
		return minute < rhs.minute;
	}
};

struct Call {
	string name;
	Date begin, end;
	bool hasPair = false;
};
struct CallRecord {
	string name;
	Date time;
	string type;
};

int main()
{
	/*istringstream cin(R"(10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
10
CYLL 01:01:06:01 on-line
CYLL 01:28:16:05 off-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:08:03 off-line
CYJJ 01:01:05:59 on-line
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:04:23:59 off-line)");*/
	/*istringstream cin(R"(10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
5
aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
CYLL 01:28:15:41 on-line
aaa 01:05:02:24 on-line
aaa 01:02:00:02 off-line)");*/
	double feePMatHour[24];
	for (double& fee : feePMatHour) {
		cin >> fee;
	}
	int n; cin >> n;
	vector<CallRecord> records;
	CallRecord t;
	while (n--) {
		cin >> t.name;
		cin >> t.time.month; cin.get();
		cin >> t.time.day; cin.get();
		cin >> t.time.hour; cin.get();
		cin >> t.time.minute;
		cin >> t.type;
		records.push_back(t);
	}
	sort(records.begin(), records.end(), [](const CallRecord& a, const CallRecord& b) {
		return a.time < b.time;
		});
	vector<Call> v; Call tc; int cnt = 0;
	for(CallRecord& r: records) {
		tc.name = r.name;
		if (r.type == "on-line") {
			tc.begin = r.time;
			tc.hasPair = false;
			v.push_back(tc);
		}
		else if (r.type == "off-line") {
			Call* p = nullptr;
			for (Call& c : v) {
				if (c.name == r.name) {
					if (!c.hasPair) {
						if (r.time< c.begin) {
							break;
						}
						p = &c;
					}
				}
			}
			if (p != nullptr) {
				p->end = r.time;
				p->hasPair = true;
				cnt++;
			}
		}
		else {
			cerr << "illgeal type";
		}
	}
	sort(v.begin(), v.end(), [](const Call& a, const Call& b) {
		if (a.hasPair && !b.hasPair) {
			return true;
		}
		if (!a.hasPair && b.hasPair) {
			return false;
		}
		if (a.name != b.name) {
			return a.name < b.name;
		}
		return a.begin < b.begin;
	});
	v.resize(cnt);

	// output
	if (v.empty()) {
		return 0;
	}
	string calcUser; double sum = 0.0;
	for (Call& c : v) {
		if (!c.hasPair) {
			continue;
		}
		if (calcUser.empty() || c.name != calcUser) {
			if (!calcUser.empty()) {
				// end previous user
				cout << "Total amount: $" << fixed << setprecision(2) << sum / 100 << endl;
			}
			// new user
			calcUser = c.name;
			sum = 0.0;
			cout << calcUser << " "
				<< setfill('0') << setw(2) << c.begin.month
				<< endl;
		}
		cout << setw(2) << c.begin.day << ":"
			<< setw(2) << c.begin.hour << ":"
			<< setw(2) << c.begin.minute << " ";
		cout << setw(2) << c.end.day << ":"
			<< setw(2) << c.end.hour << ":"
			<< setw(2) << c.end.minute << " ";
		Date t = c.begin; int dur = 0; double fee = 0.0;
		while (t != c.end) {
			t.minute++;
			dur++;
			//clog << t.hour << " " << t.minute << " " << feePMatHour[t.hour] << endl;
			fee += feePMatHour[t.hour];
			if (t.minute == 60) {
				t.minute = 0;
				t.hour++;
			}
			if (t.hour == 24) {
				t.hour = 0;
				t.day++;
			}
		}
		sum += fee;
		cout << dur << " $" << fixed << setprecision(2) << fee/100 << endl;
	}
	cout << "Total amount: $" << fixed << setprecision(2) << sum/100 << endl;
}

