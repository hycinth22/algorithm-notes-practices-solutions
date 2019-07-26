// 贪心-A1033.cpp
//

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

struct sat {
	double price;
	double distance;
	bool operator<(const sat&r) const {
		return distance < r.distance;
	}
};


int findCheaperThanCur(const vector<sat>& sats, size_t beginIndex, const double& curPrice, const double& maxDistance) {
	size_t nsat = sats.size();
	for (int i = beginIndex; i < nsat; i++) {
		if (sats[i].distance > maxDistance) {
			// 过滤掉满油也不能到达的站点。
			break;
		}
		if (sats[i].price < curPrice) {
			return i;
		}
	}
	return -1;
}

int findCheapestNext(const vector<sat>& sats, size_t beginIndex, const double& maxDistance) {
	size_t nsat = sats.size();
	int nextSat = -1;
	for (int i = beginIndex; i < nsat; i++) {
		if (sats[i].distance > maxDistance) {
			// 过滤掉满油也不能到达的站点。
			break;
		}
		if (nextSat == -1 ||
			sats[i].price < sats[nextSat].price
			) {
			nextSat = i;
		}
	}
	return nextSat;
}

int main()
{
	double cap, distance, dpg; int nsat;
	cin >> cap >> distance >> dpg >> nsat;
	vector<sat> sats(nsat);
	for(int i=0; i<nsat; i++) {
		cin >> sats[i].price >> sats[i].distance;
	}
	sort(sats.begin(), sats.end());
	if (sats.size() < 2|| sats.front().distance != 0) {
		cout << "The maximum travel distance = 0.00" << endl;
		return 0;
	}
	sats.push_back(sat{ 0.0, distance }); nsat++;
	double curPrice = sats.front().price;
	double curDistance = sats.front().distance;
	double maxDistance = cap* dpg;
	double ans = 0;
	double gas = 0;
	size_t curSat = 0;
	//clog << "maxDistance " << maxDistance << endl;
	while (curPrice != 0.00) {
		int nextSat;
		// 寻找低于当前油价的站点
		nextSat = findCheaperThanCur(sats, curSat+1, curPrice, curDistance+maxDistance);
		if (nextSat != -1) {
			// 加油恰好达到下一站点
			double needGas = (sats[nextSat].distance - curDistance) / dpg;
			//clog << "next stat" << nextSat<< " needGas " << needGas << endl;
			if (needGas > gas) {
				assert(gas <= cap);
				ans += (needGas - gas) * curPrice;
				gas = needGas;
				assert(gas <= cap);
				//clog << "add gas at " << curSat << "gas has " << gas << endl;
			}
			// 前往下一站点
			gas = 0;
			curSat = nextSat;
			//clog << "reach " << curSat << "gas remain " << gas << endl;
			curDistance = sats[curSat].distance;
			curPrice = sats[curSat].price;
			continue;
		}
		// 寻找最低
		nextSat = findCheapestNext(sats, curSat + 1, curDistance + maxDistance);
		if (nextSat != -1) {
			// 加满油
			assert(gas <= cap);
			ans += (cap - gas) * curPrice;
			gas = cap;
			// clog << "add gas at " << curSat << " full gas " << gas << endl;
			// 到达下一站点
			gas -= (sats[nextSat].distance - curDistance) / dpg;
			curSat = nextSat;
			assert(gas >= 0);
			// clog << "reach " << curSat << ", gas remain" << gas << endl;
			curDistance = sats[curSat].distance;
			curPrice = sats[curSat].price;
			continue;
		}
		else {
			// clog << "end " << endl;
			// 加满油
			assert(gas <= cap);
			ans += (cap - gas) * curPrice;
			gas = cap;
			// clog << "add gas at " << curSat << " full gas " << gas << endl;
			// 跑出尽量远
			curDistance += gas * dpg;
			cout << "The maximum travel distance = " << fixed << setprecision(2) << curDistance << endl;
			return 0;
		}
	}
	cout << fixed << setprecision(2) << ans << endl;
}

