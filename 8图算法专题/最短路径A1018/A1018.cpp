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
constexpr const int infdistance = numeric_limits<int>::max();
bool dijkstra(const vector<unordered_map<int, int>> &roads, size_t n, int target,
              vector<vector<int> > &prev
) {
    prev.clear(); prev.resize(n);
    vector<int> distance(n, infdistance);
    vector<bool> visited(n);
    distance[0] = 0;
    for (int cnt = 0; cnt < n; cnt++) {
        int s = -1;
        for (int i=0; i<n; i++) {
            if (!visited[i] && (s==-1 || distance[i] < distance[s])) {
                s = i;
            }
        }
        if (s == -1) break; // 剩余点不可达
        visited[s] = true; clog << "select " << s << endl;
        auto &r = roads[s];
        for (int i = 0; i < n; i++) {
            if (!visited[i] && r.count(i)) {
                if (distance[s] + r.at(i) < distance[i]) {
                    distance[i] = distance[s] + r.at(i);  clog << "reach " << i << " in distance " << distance[i] << "by " << s << endl;
                    prev[i] = {s};
                } else if (distance[s] + r.at(i) == distance[i]) {
                    prev[i].push_back(s);   clog << "reach " << i << " in distance " << distance[i] << "by " << s << endl;
                }
            }
        }
    }
    return distance[target] != infdistance;
}

int minExtra = infdistance, minBack = infdistance;
vector<int> anspath;
void dfs(const vector<int> &bikes, const vector<vector<int> > &prev,
         const int &start, vector<int> &pathk) {
    pathk.push_back(start); // 加入路径
    if (start == 0) {
        // 已知整条路径，在此计算出发时需要带走和带回的数量
        int extra = 0, remain = 0;
        // 因为DFS顺序是从终点到起点，所以路径pathk也是终点到起点
        // 以下模拟，逆向遍历才是模拟起点到终点
        for (int i = pathk.size() - 1; i >= 0; i--) {
            int id = pathk[i];
            if (bikes[id] < 0) {
                int vertexNeed = -bikes[id];
                if (remain < vertexNeed) {
                    extra += vertexNeed - remain; // 不够补充，修正出发应该多带相应数量差
                    remain = 0;
                } else {
                    remain -= vertexNeed; // 足够补充
                }
            } else {
                remain += bikes[id]; // 带走多余
            }
        }
        if (extra < minExtra ||
            (extra == minExtra && remain < minBack)) {
            minExtra = extra;
            minBack = remain;
            anspath = pathk;
        }
    } else {
        // 递归得到整条路径
        for (const int &k : prev[start]) {
            dfs(bikes, prev, k, pathk);
        }
    }
    pathk.pop_back(); // 回溯
}

// dijkstra 找出所有最短路径 + dfs 优选最少带出和带回
bool solve(const vector<int> &bikes, const vector<unordered_map<int, int>> &roads, int target,
           int &minSend, int &takeBack, vector<int> &path) {
    vector<vector<int> > prev;
    if (!dijkstra(roads, bikes.size(), target, prev)) return false;
    {
        minExtra = infdistance; minBack = infdistance; anspath.clear();
        dfs(bikes, prev, target, path);
        path = move(anspath); reverse(path.begin(), path.end());
        minSend = minExtra;
        takeBack = minBack;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    int cmax, n, sp, m;
    cin >> cmax >> n >> sp >> m;
    vector<int> bikes(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> bikes[i];
        bikes[i] -= cmax / 2;
    }
    vector<unordered_map<int, int>> roads(n + 1);
    for (int i = 1; i <= m; i++) {
        int si, sj, tij;
        cin >> si >> sj >> tij;
        roads[si].insert(make_pair(sj, tij));
        roads[sj].insert(make_pair(si, tij));
    }
    int minSend, takeBack;
    vector<int> path;
    bool ok = solve(bikes, roads, sp, minSend, takeBack, path);
    assert(ok); // 输入数据无解会触发
    assert(!path.empty());
    cout << minSend << " ";
    cout << path[0];
    for (int i = 1; i < path.size(); i++) {
        cout << "->" << path[i];
    }
    cout << " ";
    cout << takeBack << endl;
}
