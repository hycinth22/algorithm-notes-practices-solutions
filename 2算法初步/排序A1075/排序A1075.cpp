// 排序A1075.cpp
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm> 
#include <numeric> 
#include <map>
using namespace std;

struct user {
	string id;
	vector<int> scores;
};

int main()
{
	int cntUser, cntProblems, cntSubmission;
	cin >> cntUser >> cntProblems >> cntSubmission;
	vector<int> fullMarks(cntProblems);
	for (int i = 0; i < cntProblems;i++) {
		cin >> fullMarks[i];
	}
	map<string, user> mapUsers;
	for (int i = 0; i < cntSubmission; i++) {
		string user_id;
		int problem_id, partial_score_obtained;
		cin >> user_id >> problem_id >> partial_score_obtained;
		if (mapUsers.count(user_id) == 0) {
			mapUsers.insert_or_assign(user_id, user{
					user_id,
					vector<int>(cntProblems, -2)
				});
		}
		mapUsers[user_id].scores[problem_id - 1] = partial_score_obtained;
	}
	// not implement
	// todo: rank
	for (auto pair : mapUsers) {
		int sum = 0;
		for (auto s : pair.second.scores) {
			if (s >= -1) {
				sum += s;
			}
		}
		cout << pair.first << " " << sum;
		for_each(pair.second.scores.begin(), pair.second.scores.end(), [&](int score)
			{
				if (score > -2) {
					cout << " " << score;
				}
				else {
					cout << " -";
				}
			});
		cout << endl;
	}
}

