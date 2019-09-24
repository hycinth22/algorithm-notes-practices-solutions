// 队列的应用A1056.cpp
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	unsigned np, ng; cin >> np >> ng;
	vector<unsigned> weights(np);
	vector<unsigned> ranks(np);
	for (auto& w : weights) {
		cin >> w;
	}
	queue<size_t> q;
	for (size_t i = 0; i < np; i++) {
		size_t id; cin >> id;
		q.push(id);
	}
	unsigned rank = np+1;
	while (q.size() > 1) {
		// new turn
		clog << "----new turn ---" << endl;
		clog << "the turn has " << q.size() << " players" << endl;
		// calc the loser rank
		unsigned nGroup = ((q.size()%ng) ? (q.size() / ng + 1) : (q.size() / ng));
		clog << nGroup << " groups" << endl;
		unsigned nLosers = q.size()- nGroup; // the number of winners is same as the group
		clog << nLosers << " losers" << endl;
		rank -= nLosers;
		clog << rank << " rank" << endl;

		// process every group
		queue<size_t> nextTurn;
		while (!q.empty()) {
			// pop a group, assign all rank and find the winner
			size_t winner = q.front();
			for (size_t i = 0; i < ng && !q.empty(); i++) {
				auto id = q.front(); q.pop();
				if (weights[id] > weights[winner]) {
					clog << id << "win" << winner << endl;
					winner = id;
				}
				ranks[id] = rank;
			}
			nextTurn.push(winner);
			clog << "winner" << winner << endl;
		}
		// over a turn
		q.swap(nextTurn);
	}
	ranks[q.front()] = 1;
	cout << ranks.front();
	for (size_t i = 1; i < np; i++) {
		cout << " " << ranks[i];
	}
	cout << endl;
}

