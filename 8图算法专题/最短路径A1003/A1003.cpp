//
// Created by inked on 2020/1/21 0021.
//
// 需要注意审题，第一个输出数据是最短路径的个数，而不是最短路径的距离
// 测试点1是起点终点相同，注意最短路径数是1而不是0，队伍数量就是起点的数量而不是0
#include <bits/stdc++.h>
using namespace std;

#ifndef _DEBUG
struct fakeOSType {
    template<class contentType>
    inline fakeOSType &operator<<(const contentType &cont) {return *this;}
    inline fakeOSType &operator<<(ostream &op(ostream &)) {return *this;}
} nullos;
#define clog nullos
#endif

int dijkstra(const vector<int> &teams, const map<pair<int, int>, int> &roads,
             int n, int start, int target,
             int &cntShortestPath, int &maxTeamsAmount
) {
    if (start == target) {
        cntShortestPath = 1;
        maxTeamsAmount = teams[start];
        return 0;
    }
    constexpr const int maxDistance = 0x3f3f3f3f;
    vector<bool> visited(n);
    vector<int> distance(n, maxDistance); // distance[i]：从起点到点i的距离（维护其最小）
    vector<int> cntPath(n);
    vector<int> weight(n, 0); // weight[i]：从起点到点i的集结人手（维护其最大）

    // 起点需要特殊处理。但是不要给起点设置visited，需要以起点为中间点先得到起点周围点。
    distance[start] = 0;
    cntPath[start] = 1;
    weight[start] = teams[start];

    for (int c = 0; c < n; ++c) {
        // 从未访问过的点中选取起点可到达的最近的点，存在距离相同的点时则选取weight较大的
        int next = -1;
        for (int i=0; i<n; i++) {
            if (!visited[i] && (next==-1 || distance[i] < distance[next])) {
                next = i;
            }
        }
        if (next == -1) break; // 剩余点不可达

        for (int i = next + 1; i < n; ++i) {
            if (!visited[i] &&
                (distance[i] < distance[next] ||
                 (distance[i] == distance[next] && weight[i] > weight[next])
                )) {
                next = i;
            }
        }
        visited[next] = true;
        clog << " select " << next << " as intermediate" << endl;
        // 以此点(next)为中介，尝试优化起点到所有各点的距离和集结人手
        for (int i = 0; i < n; ++i) {
            auto p = make_pair(next, i);
            if (!visited[i] && roads.count(p)) {
                int quasiDistance = distance[next] + roads.at(p),
                        quasiWeight = weight[next] + teams[i];

                if (quasiDistance < distance[i]) {
                    distance[i] = quasiDistance;
                    cntPath[i] = cntPath[next];
                    weight[i] = quasiWeight;
                    clog << "[SHORTER DISTANCE] now we can reach " << i << " in " << quasiDistance << " distance and "
                          << quasiWeight << " hands" << endl;
                } else if (quasiDistance == distance[i]) {
                    cntPath[i] += cntPath[next]; // 增加路径计数。易错点：不要把这句放在weight的判断里，它与weight无关。
                    clog << "[NEW EQUAL-DISTANCE WAY] the way is " << i << " in " << quasiDistance << " distance and "
                          << quasiWeight << " hands" << endl;
                    // 这个if和上面距离的if要分开，以便于计数path
                    if (quasiWeight > weight[i]) {
                        weight[i] = quasiWeight;
                        clog << "[MORE HANDS] now we can reach " << i << " in " << quasiDistance << " distance and "
                              << quasiWeight << " hands" << endl;
                    }
                }
            }
        }
    }
    cntShortestPath = cntPath[target];
    maxTeamsAmount = weight[target];
    return distance[target];
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
    dijkstra(teams, roads, n, c1, c2, cntPath, amount);
    cout << cntPath << " " << amount << endl;
}