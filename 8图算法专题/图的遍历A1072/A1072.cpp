// 测试点4偶尔超时
#include <bits/stdc++.h>

using namespace std;

struct vertex {
    bool isStation;
    int id;

    inline bool operator==(const vertex &v) const {
        return isStation == v.isStation && id == v.id;
    }
};

struct vertexhash {
    inline unsigned long operator()(const vertex &v) const {
        return std::hash<int>()(v.id) ^ std::hash<bool>()(v.isStation);
    }
};
int n, m, k, ds;
vector<unordered_map<vertex, int, vertexhash>> roadFromHouse, roadFromStation;
vector<int> distanceHouse, distanceStation;
vector<bool> visitedHouse, visitedStation;
inline int getDistance(const vertex &v) {
    if (v.isStation) {
        return distanceStation[v.id];
    }
    return distanceHouse[v.id];
}

void dijkstra(const int &station) {
    constexpr const int inf = numeric_limits<int>::max();
    fill_n(visitedHouse.begin(), n+1, false);
    fill_n(visitedStation.begin(), m+1, false);
    distanceHouse.clear();
    distanceHouse.resize(n + 1, inf);
    distanceStation.clear();
    distanceStation.resize(m + 1, inf);
    distanceStation[station] = 0;

    for (int cnt = 0; cnt < n + m; ++cnt) {
        vertex s{.id=-1};
        for (int i = 1; i <= n; ++i) {
            if (!visitedHouse[i]) {
                if (s.id == -1 || distanceHouse[i] < getDistance(s)) {
                    s.isStation = false;
                    s.id = i;
                }
            }
        }
        for (int i = 1; i <= m; ++i) {
            if (!visitedStation[i]) {
                if (s.id == -1 || distanceStation[i] < getDistance(s)) {
                    s.isStation = true;
                    s.id = i;
                }
            }
        }
        if (s.id == -1) {
            break;
        }
        if (s.isStation) {
            visitedStation[s.id] = true;
        } else {
            visitedHouse[s.id] = true;
        }
        for (int i = 1; i <= n; ++i) {
            if (!visitedHouse[i] && roadFromHouse[i].count(s)) {
                if (distanceHouse[i] > getDistance(s) + roadFromHouse[i][s]) {
                    distanceHouse[i] = getDistance(s) + roadFromHouse[i][s];
                }
            }
        }
        for (int i = 1; i <= m; ++i) {
            if (!visitedHouse[i] && roadFromStation[i].count(s)) {
                if (distanceStation[i] > getDistance(s) + roadFromStation[i][s]) {
                    distanceStation[i] = getDistance(s) + roadFromStation[i][s];
                }
            }
        }
    }
}

bool allInRange(vector<int> &allDistance) {
    for (int i = 1; i <= n; i++) {
        if (allDistance[i] > ds) {
            // exceed service range
            return false;
        }
    }
    return true;
}

double calcMinDistance(vector<int> &allDistance) {
    double r = numeric_limits<double>::max();
    for (int i = 1; i <= n; i++) {
        double d = allDistance[i];
        if (d < r) {
            r = d;
        }
    }
    return r;
}

double calcAvgDistance(vector<int> &allDistance) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        sum += allDistance[i];
    }
    return sum / n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k >> ds; roadFromHouse.resize(n+1); roadFromStation.resize(m+1);
    visitedHouse.resize(n+1); visitedStation.resize(m+1);
    for (int i = 0; i < k; ++i) {
        string p1, p2;
        int len;
        cin >> p1 >> p2 >> len;
        vertex v1, v2;
        v1.isStation = p1[0] == 'G';
        v1.id = v1.isStation ? stoi(p1.substr(1)) : stoi(p1);
        v2.isStation = p2[0] == 'G';
        v2.id = v2.isStation ? stoi(p2.substr(1)) : stoi(p2);
        if (v1.isStation) {
            roadFromStation[v1.id].reserve(n+m); //重要，否则重建哈希表消耗大量时间
            roadFromStation[v1.id][v2] = len;
            v1.id = stoi(p1.substr(1));
        } else {
            roadFromHouse[v1.id].reserve(n+m); //重要，否则重建哈希表消耗大量时间
            roadFromHouse[v1.id][v2] = len;
            v1.id = stoi(p1);
        }
        if (v2.isStation) {
            roadFromStation[v2.id].reserve(n+m); //重要，否则重建哈希表消耗大量时间
            roadFromStation[v2.id][v1] = len;
        } else {
            roadFromHouse[v2.id].reserve(n+m); //重要，否则重建哈希表消耗大量时间
            roadFromHouse[v2.id][v1] = len;
        }
    }
    int ans = -1;
    double ansMinDistance = numeric_limits<double>::min(), ansAvgDistance = numeric_limits<double>::max();
    for (int i = 1; i <= m; ++i) {
        dijkstra(i);
        if (allInRange(distanceHouse)) {
            double minDistance = calcMinDistance(distanceHouse);
            double avgDistance = calcAvgDistance(distanceHouse);
            if (minDistance > ansMinDistance
                || (minDistance == ansMinDistance && avgDistance < ansAvgDistance)
                    ) {
                ans = i;
                ansMinDistance = minDistance;
                ansAvgDistance = avgDistance;
            }
        }
    }
    if (ans == -1) {
        cout << "No Solution" << endl;
        return 0;
    }
    cout << "G" << ans << endl;
    cout << fixed << setprecision(1)
         << ansMinDistance << " " << ansAvgDistance << endl;
}
