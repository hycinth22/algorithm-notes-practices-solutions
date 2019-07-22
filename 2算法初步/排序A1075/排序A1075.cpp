// 排序A1075.cpp
//

#include <iostream>
#include <vector>
#include <algorithm> 
#include <functional>
#include <map>
using namespace std;

const int score_none = -99999;
struct user {
	user(int cntProblems) 
		: scores(cntProblems, score_none)
	{}
	string id;
	vector<int> scores;
	int total = 0;
	int perfect = 0;
	int rank;
};


int main()
{
	int cntUser, cntProblems, cntSubmission;
	scanf("%d%d%d", &cntUser, &cntProblems, &cntSubmission);
	//cin >> cntUser >> cntProblems >> cntSubmission;
	vector<int> fullMarks(cntProblems);
	for (int i = 0; i < cntProblems;i++) {
		scanf("%d", &fullMarks[i]);
		// cin >> fullMarks[i];
	}
	vector<user> users;
	map<string, vector<int> > scores;
	users.reserve(cntUser);
	string user_id(5, '0'); int problem_id, partial_score_obtained;
	for (int i = 0; i < cntSubmission; i++) {
		scanf("%5s%d%d", user_id.data(), &problem_id, &partial_score_obtained);
		// cin >> user_id >> problem_id >> partial_score_obtained;
		auto iteruser = find_if(users.begin(), users.end(), [user_id](user& u) {return u.id == user_id; });
		if (iteruser == users.end()) {
			iteruser = users.emplace(users.end(), cntProblems);
			iteruser->id = user_id;
			iteruser->perfect = 0;
		}
		// 不能超出满分 & 满分计数
		if (partial_score_obtained >= fullMarks[problem_id - 1]) {
			partial_score_obtained = fullMarks[problem_id - 1];
			iteruser->perfect++;
		}
		// 取多次提交的最大分
		if (partial_score_obtained > iteruser->scores[problem_id - 1]) {
			iteruser->scores[problem_id - 1] = partial_score_obtained;
		}
	}
	// 计算总分
	for (user& u : users) {
		u.total = 0;
		for (int& score : u.scores) {
			if (score >= 0) { // <0为特殊标志
				u.total += score;
			}
		}
	}
	sort(users.begin(), users.end(), [](user& a, user& b) {
		if (a.total != b.total) {
			return a.total > b.total;
		}
		if (a.perfect != b.perfect) {
			return a.perfect > b.perfect;
		}
		return a.id < b.id; 
		}
	);
	if (users.empty()) {
		return 0;
	}
	// 此处也不适合用for-range
	for (size_t i = 0; i < users.size(); i++) {
		user& u = users[i];
		if (i != 0 && users[i].total == users[i-1].total) {
			u.rank = users[i - 1].rank;
		}
		else {
			u.rank = i+1;
		}
		if (find_if(u.scores.begin(), u.scores.end(), bind(greater_equal<int>(), placeholders::_1, 0)) == u.scores.end()) {
			continue;
		}
		printf("%d %s %d", u.rank, u.id.c_str(), u.total);
		// cout << u.rank << " " << u.id << " " << u.total;
		for_each(u.scores.begin(), u.scores.end(), [&](int score)
			{
				if (score == score_none) {
					printf(" -");
					//cout << " -";
				}
				else{
					if (score<0) {
						score = 0;
					}
					printf(" %d", score);
					// cout << " " << score;
				}
			});
		printf("\n");
		// cout << endl;
	}
}

