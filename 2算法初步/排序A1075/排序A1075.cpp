// 排序A1075.cpp
// 排序A1075.cpp

#include <iostream>
#include <vector>
#include <algorithm> 
#include <unordered_map>
#include <utility>
using namespace std;

const int score_none = -99999;

struct userinfo {
	userinfo() = default;
	userinfo(const int& cntProblems)
		: scores(cntProblems, score_none)
	{}
	userinfo(const userinfo&o) 
		: total(o.total), perfect(o.perfect), rank(o.rank)
	{}
	userinfo(userinfo&&o) 
		: total(o.total), perfect(o.perfect), rank(o.rank),
		scores(move(o.scores))
	{}
	int total = 0;
	int perfect = 0;
	int rank;
	vector<int> scores;
};

int main()
{
    ios_base::sync_with_stdio(0);
	int cntUser, cntProblems, cntSubmission;
	cin >> cntUser >> cntProblems >> cntSubmission;
	vector<int> fullMarks(cntProblems);
	for (int i = 0; i < cntProblems;i++) {
		cin >> fullMarks[i];
	}
	vector<string> users; users.reserve(cntUser);
	unordered_map<string, userinfo > usersinfo; usersinfo.reserve(cntUser);
	{
		string user_id(5, '0'); int problem_id, partial_score_obtained;
		for (int i = 0; i < cntSubmission; i++) {
			cin >> user_id >> problem_id >> partial_score_obtained; // scanf("%5s%d%d", (char*)user_id.data(), &problem_id, &partial_score_obtained);
			 // 注意，此处不能用find_if遍历users的方法，时间复杂度过高会导致超时，
			// 借用unordered_map（hash_map）可O(1)完成查找
			if (usersinfo.count(user_id) == 0) {
				// 初始化用户信息
				users.push_back(user_id);
				usersinfo.emplace(user_id, cntProblems);
				usersinfo[user_id].perfect = 0;
				usersinfo[user_id].scores.resize(cntProblems, score_none);
			}
			// 不能超出满分 & 满分计数
			if (partial_score_obtained >= fullMarks[problem_id - 1]) {
				partial_score_obtained = fullMarks[problem_id - 1];
				if (usersinfo[user_id].scores[problem_id - 1] < fullMarks[problem_id - 1]) {
					// 该题未获得过满分，计满分1
					usersinfo[user_id].perfect++;
				}
			}
			// 取多次提交的最大分
			if (partial_score_obtained > usersinfo[user_id].scores[problem_id - 1]) {
				usersinfo[user_id].scores[problem_id - 1] = partial_score_obtained;
			}
		}
	}
	// 计算总分
	for (string& uid : users) {
		usersinfo[uid].total = 0;
		bool hasTotal = false; // 是否有过有效提交
		for (int score : usersinfo[uid].scores) {
			if (score >= 0) { // <0为特殊标志，代表无效分数，数值区分不同无效情形
				usersinfo[uid].total += score;
				hasTotal = true;
			}
		}
		if (!hasTotal) {
			usersinfo[uid].total = score_none;
		}
	}
	sort(users.begin(), users.end(), [&usersinfo](string& a, string& b) {
		if (usersinfo[a].total != usersinfo[b].total) {
			return usersinfo[a].total > usersinfo[b].total;
		}
		if (usersinfo[a].perfect != usersinfo[b].perfect) {
			return usersinfo[a].perfect > usersinfo[b].perfect;
		}
		return a < b;
		}
	);
	if (usersinfo.empty()) {
		return 0;
	}
	for (size_t i = 0; i < users.size(); i++) {
		const string& uid = users[i];
		userinfo& u = usersinfo[uid];
		// assign rank
		if (i != 0 && usersinfo[uid].total == usersinfo[users[i-1]].total) {
			u.rank = usersinfo[users[i - 1]].rank;
		}
		else {
			u.rank = i+1;
		}
		// output
		if (u.total == score_none) {
			// 无有效成绩，跳过该用户的输出
			continue;
		}
		printf("%d %s %d", u.rank, uid.c_str(), u.total); // cout << u.rank << " " << uid << " " << u.total;
		int len = usersinfo[uid].scores.size();
		for (int i = 0; i < len; ++i) {
			int& score = usersinfo[uid].scores[i];
			if (score == score_none) {
				printf(" -");  // cout << " -";
			}
			else {
				if (score < 0) {
					score = 0;
				}
				printf(" %d", score); // cout << " " << score;
			}
		}
		printf("\n"); // cout << endl;
	}
}
