// 排序A1080.cpp
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Examee {
	int id;
	int exam, interview;
	int final;
	int rank;
};

int main()
{
	int nExamee, nCollege, nPreferred; cin >> nExamee >> nCollege >> nPreferred;
	vector<int> quotas(nCollege);
	for (int i = 0; i < nCollege; i++) {
		cin >> quotas[i];
	}
	vector<Examee> examees(nExamee);
	vector< vector<int> > choices(nExamee, vector<int>(nPreferred) );
	for(int i=0; i< nExamee; i++) {
		examees[i].id = i;
		cin >> examees[i].exam >> examees[i].interview;

		// calc final grade
		examees[i].final = examees[i].exam + examees[i].interview;

		for (int &prefer: choices[i]) {
			cin >> prefer;
		}
	}
	// 注意，此后数组下标均不再对应id
	sort(examees.begin(), examees.end(), [](Examee&a, Examee&b) {
		if (a.final != b.final) {
			return a.final > b.final;
		}
		return a.exam > b.exam;
	});

	// assign rank
if (!examees.empty()) {
	examees.front().rank = 1;
		clog << "rank id" << endl;
		clog << examees[0].rank << "\t\t"<< examees[0].id << endl;
	}
	for (int i = 1; i < examees.size(); ++i) {
		if (examees[i].final == examees[i-1].final &&
			examees[i].exam == examees[i - 1].exam
			) {
			examees[i].rank = examees[i - 1].rank;
		}
		else {
			examees[i].rank = i+1;
		}
		clog << examees[i].rank << " "<< examees[i].id << endl;
	}
	// admit
	clog << "admit" << endl;
	vector< vector<int> > admitteds(nCollege);
	vector<int> lowestAdmittedRank(nCollege, 0);
	for (int i = 0; i < examees.size(); ++i) {
		const Examee& e = examees[i];
		const int& eid = e.id;
		for (int j = 0; j < choices[eid].size(); ++j) {
			const int& preferSchool = choices[eid][j];
			if (admitteds[preferSchool].size() < quotas[preferSchool]
				) {
				admitteds[preferSchool].push_back(e.id);
				lowestAdmittedRank[preferSchool] = e.rank;
				break;
			}
			else if (!admitteds[preferSchool].empty()){
				// 注意，此时即使知道该学校上一个录取的id，也不知道这个id对应下标及其rank，因此单独开vector为每个学校记录最低rank
				if (e.rank == lowestAdmittedRank[preferSchool]) {
					// special admit for justice
					admitteds[preferSchool].push_back(eid);
					break;
				}
			}
		}
	}
	// sort & output
	for (vector<int>& list : admitteds) {
		sort(list.begin(), list.end());
		if (!list.empty()) {
			cout << list.front();
		}
		for (int i = 1; i < list.size(); ++i) {
			cout << " " << list[i];
		}
		cout << endl;
	}
}

