#include <bits/stdc++.h>
using namespace std;

#ifndef _DEBUG
struct fakeOSType {
    template<class contentType>
    inline fakeOSType &operator<<(const contentType &cont) {return *this;}
    inline fakeOSType &operator<<(ostream &op(ostream &)) {return *this;}
} nullos;
#define clog nullos
#define cerr nullos
#endif

int bellmanford(const vector<int> &teams, const map<pair<int, int>, int> &roads,
                int n, int start, int target,
                int &cntShortestPath, int &maxTeamsAmount
) {
    constexpr const int maxDistance = 0x3f3f3f3f;
    vector<int> d(n, maxDistance);
    vector<int> cntPath(n);
    vector<int> weight(n, 0); // weight[i]：从起点到点i的集结人手（维护其最大）
    vector<unordered_set<int> > prev(n); // 辅助统计cntPath
    d[start] = 0;
    cntPath[start] = 1;
    weight[start] = teams[start];

    // 无负环保证n-1次得到最优
    for (int cnt = 0; cnt < n - 1; ++cnt) {
        for (auto p: roads) {
            auto &line = p.first;
            auto &dis = p.second;
            if (d[line.first] + dis < d[line.second]) {
                d[line.second] = d[line.first] + dis;
                cntPath[line.second] = cntPath[line.first];
                weight[line.second] = weight[line.first] + teams[line.second];
                clog << " shorter path to " << line.second << " via " << line.first << "：" << d[line.second] << endl;
                prev[line.second] = {line.first};
            } else if (d[line.first] + dis == d[line.second]) {
                prev[line.second].insert(line.first);
                cntPath[line.second] = accumulate(prev[line.second].begin(), prev[line.second].end(), 0,
                                                  [&cntPath](int acc, int i) {
                                                      return acc + cntPath[i];
                                                  });
                clog << " euqal path to " << line.second << " via " << line.first << "：" << d[line.second]
                     << endl << cntPath[line.second] << endl;
                if (weight[line.first] + teams[line.second] > weight[line.second]) {
                    weight[line.second] = weight[line.first] + teams[line.second];
                }
            }
        }
    }
    // 没有进行负环检测。
    cntShortestPath = cntPath[target];
    maxTeamsAmount = weight[target];
    return d[target];
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, c1, c2;
    cin >> n >> m >> c1 >> c2;
    vector<int> teams(n);
    for (int i = 0; i < n; i++) {
        cin >> teams[i];
    }
    map<pair<int, int>, int> roads;
    for (int i = 0; i < m; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        roads[make_pair(a, b)] = l;
        roads[make_pair(b, a)] = l;
    }
    int cntPath, amount;
    bellmanford(teams, roads, n, c1, c2, cntPath, amount);
    cout << cntPath << " " << amount << endl;
}