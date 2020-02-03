// CODEUP测试数据有问题
#include <bits/stdc++.h>
using namespace std;

struct vertex {
    vertex(long double x, long double y) : x(x), y(y) {};
    long double x, y;

    bool operator==(const vertex &v) const {
        return x == v.x && y == v.y;
    }
};
struct vertexhasher {
    unsigned long operator()(const vertex &v) const {
        return std::hash<long double>()(v.x) ^ std::hash<long double>()(v.y);
    }
};
int n;
vector<vertex> vertexs;
unordered_map<vertex, unordered_map<vertex, long double, vertexhasher>, vertexhasher> edges;

long double prim() {
    constexpr const long double maxdis = numeric_limits<long double>::max();
    long double ans = 0.0;
    unordered_map<vertex, long double, vertexhasher> d;
    unordered_map<vertex, bool, vertexhasher> visited;
    d.reserve(n);
    visited.reserve(n);
    for (auto &v: vertexs) {
        d[v] = maxdis;
    }
    d[*vertexs.begin()] = 0.0;
    for (int cnt = 0; cnt < n; ++cnt) {
        const vertex *s = nullptr;
        for (auto &v: vertexs) {
            if (!visited[v])
                if (s == nullptr || d[v] < d[*s]) {
                    s = &v;
                }
        }
        if (!s || d[*s] == maxdis) return -1;
        visited[*s] = true;
        ans += d[*s];
        if (edges.count(*s)) {
            for (auto p : edges.at(*s)) {
                if (!visited[p.first] && edges[*s][p.first] < d[p.first]) {
                    d[p.first] = edges[*s][p.first];
                }
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        vertexs.clear();
        edges.clear();
        vertexs.reserve(n);
        edges.reserve(n * n);
        for (int i = 0; i < n; ++i) {
            long double x, y;
            cin >> x >> y;
            vertexs.emplace_back(x, y);
        }
        // 预计算每两个点的距离
        for (auto ita = vertexs.cbegin(); ita != vertexs.cend(); ++ita) {
            auto itb = ita;
            ++itb;
            for (; itb != vertexs.cend(); ++itb) {
                long double dis = sqrt((ita->x - itb->x) * (ita->x - itb->x) + (ita->y - itb->y) * (ita->y - itb->y));
                edges[*ita][*itb]
                        = edges[*itb][*ita]
                        = dis;
            }
        }
        cout << fixed << setprecision(2) << prim() << endl;
    }
}
