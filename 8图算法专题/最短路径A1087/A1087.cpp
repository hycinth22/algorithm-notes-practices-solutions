#include <bits/stdc++.h>

using namespace std;

int n, k;
string start;
const string target = "ROM";
unordered_map<string, int> hap;
unordered_map<string, unordered_map<string, int> > cost;
unordered_map<string, string> pre;
unordered_map<string, int> d, h, l, c;

void dijkstra() {
    constexpr const int inf = numeric_limits<int>::max();
    d.reserve(n);
    h.reserve(n);
    l.reserve(n);
    c.reserve(n);
    unordered_map<string, bool> visited;
    visited.reserve(n);
    pre[start] = "";
    d[start] = 0;
    h[start] = hap[start];
    l[start] = 0;
    c[start] = 1;

    for (int cnt = 0; cnt < n; ++cnt) {
        string s;
        for (const auto &p: hap) {
            const string &t = p.first;
            if (!d.count(t)) {
                d[t] = inf; // 初始map。d找最小，而h/l/c找最大。找最大初为0初始也可接受，故不显式初始其他map
            }
            if (visited[t]) continue;
            if (s.empty() || d[t] < d[s]) {
                s = t;
            }
        }
        if (s.empty()) {
            break; // 剩余顶点不可达
        }
        visited[s] = true;
        for (const auto &p: hap) {
            const string &t = p.first;
            if (visited[t] || !cost[s].count(t))continue;
            // 更新路径条数。必须写在优化（下面的optimize）前面，否则d在优化后变了使得判断错误
            if (d[t] > d[s] + cost[s][t]) {
                c[t] = c[s];
            } else if (d[t] == d[s] + cost[s][t]) {
                c[t] += c[s]; // 注意是相加，不要写成简单+1
            }
            bool moreOptimize = false;
            moreOptimize = moreOptimize ||
                           (d[t] > d[s] + cost[s][t]);
            moreOptimize = moreOptimize ||
                           (d[t] == d[s] + cost[s][t] &&
                            h[t] < h[s] + p.second);
            moreOptimize = moreOptimize ||
                           (d[t] == d[s] + cost[s][t] &&
                            h[t] == h[s] + p.second &&
                            double(h[s] + hap[t]) / (l[s] + 1) > double(h[t]) / l[t]);
            if (moreOptimize) {
                d[t] = d[s] + cost[s][t]; // 路径距离
                h[t] = h[s] + p.second; // 路径幸福度
                l[t] = l[s] + 1; // 路径长度（除起点）
                pre[t] = s;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> start;
    hap.reserve(n);
    cost.reserve(n);
    pre.reserve(n);
    hap[start] = 0;
    for (int i = 0; i < n - 1; ++i) {
        static string city; int h;
        cin >> city >> h;
        hap[city] = h;
    }
    for (int i = 0; i < k; ++i) {
        static string c1, c2;
        int co;
        cin >> c1 >> c2 >> co;
        cost[c1][c2] = cost[c2][c1] = co;
    }
    dijkstra();
    cout << c[target] << " " << d[target] << " " << h[target] << " " << int(h[target] / l[target]) << endl;
    stack<string> route;
    string city = target;
    while (city != start) {
        route.push(city);
        city = pre[city];
    }
    cout << start;
    while (!route.empty()) {
        cout << "->" << route.top();
        route.pop();
    }
}
