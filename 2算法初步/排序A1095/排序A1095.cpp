// 排序A1095.cpp
//

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <cassert>
using namespace std;

struct itime {
	itime() = default;
	itime (int t)
		: t(t)
	{
		/*s = t % 60;
		t /= 60; 
		m = t % 60;
		t /= 60;
		h = t;*/
	}
	bool operator<(const itime& r) const {
		return t < r.t;
		/*
		if (h != r.h) {
			return h < r.h;
		}
		if (m != r.m) {
			return m < r.m;
		}
		if (s != r.s) {
			return s < r.s;
		}
		return false;*/
	}
	bool operator<=(const itime& r) const {
		return t <= r.t;
		/*
		if (h != r.h) {
			return h <= r.h;
		}
		if (m != r.m) {
			return m <= r.m;
		}
		if (s != r.s) {
			return s <= r.s;
		}
		return true;*/
	}
	int operator-(const itime& r) const {
		return t - r.t;
		//int result = (3600 * h + 60 *m + s) - (3600 * r.h + 60 * r.m + r.s);
		//return result;
	}
	int h() {
		return t / 3600;
	}
	int m() {
		return (t / 60) % 60;
	}
	int s() {
		return t % 60;
	}
	int t;
private:
	// int h, m, s;

};
ostream& operator<<(ostream& o, itime& t) {
	return o << setfill('0')
		<< setw(2) << t.h() << ":" 
		<< setw(2) << t.m() << ":" 
		<<setw(2) << t.s();
}

enum type {in, out};
struct record {
	record() {
		plate.reserve(7);
	}
	string plate;
	itime time;
	type type;
};

int main()
{
	// 此题采用c++io会超时，此代码输入采用cin（因为同时采用了string），输出则采用c的printf来提高速度
	//cin.sync_with_stdio(false);  cout.sync_with_stdio(false); cerr.sync_with_stdio(false); clog.sync_with_stdio(false);
	size_t nRecord, nQuery; cin >> nRecord >> nQuery;
	vector<record> v;
	for (size_t i = 0; i < nRecord; i++) {
		static record r; static string type; 
		int h, m, s;;
		cin >> r.plate;
		cin >> h; cin.get();
		cin >> m; cin.get();
		cin >> s; cin.get();
		r.time.t = 3600*h + 60*m + s;
		cin >> type;
		if (type == "in") {
			r.type = in;
		}
		else if (type == "out") {
			r.type = out;
		}
		else {
			cerr << "illgeal type" << endl;
		}
		v.push_back(r);
	}
	vector<itime> querys;
	for(size_t i=0; i<nQuery; i++) {
		static itime t;
		int h, m, s;
		cin >> h; cin.get();
		cin >> m; cin.get();
		cin >> s;
		t.t = 3600 * h + 60 * m + s;
		querys.push_back(t);
	}
	sort(v.begin(), v.end(), [](record& a, record& b) {
		if (a.plate != b.plate) {
			return a.plate < b.plate;
		}
		return a.time < b.time;  
		});
	//for (auto& t : v) {
	//	clog << t.time << " " << t.plate << " " << (t.type==in?"in":"out") << endl;
	//}
	vector<int> queryscnt(nQuery, 0);
	unordered_map<string, int> carsTimes;
	set<string> maxTimeCars; int maxTime = 0;
	{
		for (size_t i = 0; i < nRecord; i++) {
			record& r1 = v[i];
			if (r1.type != in) {
				continue;
			}
			bool valid = false;
			int pairOut;
			for (size_t j = i + 1; j < nRecord; j++) {
				record& r2 = v[j];
				if (r2.plate == r1.plate) {
					if (r2.type == out) {
						valid = true;
						pairOut = j;
					}
					else if (r2.type == in) {
						valid = false;
					}
					break;
				}
			}
			if (valid) {
				assert(r1.time <= v[pairOut].time);
				// clog << r1.plate << " in at " << r1.time <<endl;
				// 计算此对记录区间是否包含各个查询时间点，并相应计数
				for (size_t i = 0; i < nQuery; i++) {
					// 判断查询时间点querys[i]是否在记录对中。
					if (querys[i] < r1.time) {
						// clog << r1.plate << " not in for " << querys[i] << endl;
						continue;
					}
					else {
						// clog << r1.plate << " in for " << querys[i] << endl;
						if (querys[i] < v[pairOut].time) {
							// clog << r1.plate << " not out for" << querys[i] << endl;
							queryscnt[i]++;
						}
						else {
							// clog << r1.plate << " out for" << querys[i] << endl;
							break; // 由于查询时间是递增顺序，保证无关之后的都无关，可以提前break
						}
					}

				}
				int& time = carsTimes[r1.plate];
				time += v[pairOut].time - r1.time;
				if (time > maxTime) {
					maxTime = time;
					maxTimeCars.clear();
					maxTimeCars.insert(r1.plate);
				}
				else if (time == maxTime) {
					maxTimeCars.insert(r1.plate);
				}
			}
		}
	}
	for (auto& cnt : queryscnt) {
		printf("%d\n", cnt);
		// cout << cnt << endl;
	}
	// 注意题意，按字母顺序输出，不要忽略这点。在这里，set已自动排序
	// sort(maxTimeCars.begin(), maxTimeCars.end());
	for (auto &car: maxTimeCars) {
		printf("%s ", car.c_str());
		// cout << car <<" ";
	}
	itime maxT(maxTime);
	printf("%02d:%02d:%02d\n", maxT.h(), maxT.m(), maxT.s());
	//cout << maxT << endl;
}

