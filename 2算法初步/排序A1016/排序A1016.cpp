// 排序A1016.cpp

#include <iostream>
#include <cstdio>
#include <sstream>
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

struct CallOper {
	string user;
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
	vector<CallOper> records(n);
	for (int i = 0; i < n; i++) {
		auto& t = records[i];
		cin >> t.user;
		cin >> t.time.month; cin.get();
		cin >> t.time.day; cin.get();
		cin >> t.time.hour; cin.get();
		cin >> t.time.minute;
		cin >> t.type;
	}
	sort(records.begin(), records.end(), [](const CallOper& a, const CallOper& b) {
		if (a.user != b.user) {
			return a.user < b.user;
		}
		return a.time < b.time;
		});
	// output
	if (records.empty()) {
		return 0;
	}
	double userFee = 0.0; // 单位是美分
	int lastOnlineIndex = -1; // 当前用户上一个On-line记录
	bool newuser = true,  // 用于切换统计的用户，重置相关量。
		newUserOutputed = false; // 用于去除空记录用户。检测到新用户并不立即输出表头，延迟至第一对记录匹配成功，才输出。同样如表头未输出，则表尾也不输出。
	for (size_t i = 0; i < records.size(); i++) {
		CallOper& op = records[i];
		if (newuser) {
			userFee = 0.0;
			lastOnlineIndex = -1;
			newuser = false;
			newUserOutputed = false;
		}
 		// assert(user == records[i].user);
		if (op.type == "on-line") {
			lastOnlineIndex = i;
		}
		else if (op.type == "off-line") {
			if (lastOnlineIndex != -1) {
				// valid pair
				// calc time & fee
				if (!newUserOutputed)
				{
					// output head
					printf("%s %02d\n", op.user.c_str(), op.time.month);
					/* cout << op.user << " "
						<< setfill('0') << setw(2) << op.time.month
						<< endl;*/
					newUserOutputed = true;
				}
				int timeInMinute = 0;
				double fee = 0.0; // 单位是美分
				CallOper& prevOn = records[lastOnlineIndex];
				{
					Date t = prevOn.time;
					while (t != op.time) {
						fee += feePMatHour[t.hour];
						timeInMinute++;
						t.minute++;
						if (t.minute == 60) {
							t.minute = 0;
							t.hour++;
						}
						if (t.hour == 24) {
							t.hour = 0;
							t.day++;
						}
					}
				}
				userFee += fee;
				// output the Call
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", 
					prevOn.time.day, prevOn.time.hour, prevOn.time.minute,
					op.time.day, op.time.hour, op.time.minute,
					timeInMinute,
					fee /100
					);
			}
			lastOnlineIndex = -1;
		}
		else {
			cerr << "illgeal type" << endl;
		}
		// 如果采用for-range写法，并不手动管理i而无法感知当前元素的位置与相邻元素的情况，反而代码更繁杂。
		if (i == records.size() - 1 || records[i].user != records[i+1].user) {
			if (newUserOutputed) {
				printf("Total amount: $%.2f\n", userFee / 100);
				// cout << "Total amount: $" << fixed << setprecision(2) << userFee / 100 << endl;
			}
			// reset flag for next user
			newuser = true;
		}
	}
}

