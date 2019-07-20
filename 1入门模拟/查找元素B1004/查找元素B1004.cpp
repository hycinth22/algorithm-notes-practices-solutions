// 查找元素B1004.cpp
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef struct {
	string name;
	string id;
	int score;
} stduent;

bool stduentScoresCompare(const stduent& a, const stduent& b) {
	return a.score > b.score;
}

int main()
{
	int n; cin >> n;
	vector<stduent> scores(n);
	int i = 0;
	while (n--) {
		cin >> scores[i].name >> scores[i].id >> scores[i].score;
		i++;
	}
	sort(scores.begin(), scores.end(), stduentScoresCompare);
	auto& high = scores.front();
	auto& low = scores.back();
	cout << high.name << " " << high.id << endl
		<< low.name << " " << low.id << endl;
}

