//
// Created by inked on 2020/1/17 0017.
//
#include <bits/stdc++.h>
using namespace std;
using relDB = unordered_map<int, vector<int> >;

int maxPotentialForwards(const relDB &follower,
        int uid, int maxUID, int maxDepth) {
    if (!follower.count(uid)) return 0;
    queue<int> q, p;
    vector<bool> visited(maxUID+1);
    assert(uid <= maxUID); visited[uid] = true; // 易忽略点，要过滤起点（自己）
    for (const int &f : follower.at(uid)) {
        //clog << " direct follower " << f << " (level 0)" << endl;
        q.push(f);
        assert(f <= maxUID); visited[f] = true;// 易忽略点
    }
    int cnt = 0, cntDepth = 1;
    while (!p.empty() || !q.empty()) {
        while (!q.empty()) {
            int t = q.front(); q.pop();
            ++cnt;
            if (cntDepth < maxDepth) {
                if (follower.count(t))
                for (const int &f : follower.at(t)) {
                    //clog << " indirect follower " << f << " at level " << cntDepth + 1 << " from " << t;
                    assert(f <= maxUID);
                    if (visited[f]) {
                        //clog << " duplicated" << endl;
                        continue;
                    }
                    //clog << endl;
                    visited[f] = true;
                    p.push(f);
                }
            }
        }
        if (!p.empty()) {
            q.swap(p);
            cntDepth++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    // relation input
    int n, l; cin >> n >> l;
    relDB follower(n+1);
    for (int i = 1; i <= n; i++) {
        int mi; cin >> mi;
        for (int j = 1; j <= mi; j++) {
            int follow; cin >> follow;
            follower[follow].push_back(i);
        }
    }
    // query
    int k; cin >> k;
    while (k--) {
        int uid; cin >> uid;
        cout << maxPotentialForwards(follower, uid, n, l) << endl;
    }
}