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

int n;
vector< vector<int> > dis;
constexpr const int maxdis = 0x3f3f3f3f;

int prim() {
    int ans = 0;
    vector<int> d(n + 1, maxdis);
    vector<bool> visited(n + 1, false);
    d[1] = 0; // 不要忘记选取一个起始点
    for (int cnt = 1; cnt <= n; ++cnt) {
        // 选择最近的未加入节点
        int s = -1;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i])
                if (s == -1 || d[i] < d[s]) {
                    s = i;
                }
        }
        if (s == -1 || d[s] == maxdis) return -1; // 存在不可达点
        clog << "select " << s << " (" << d[s] << endl;
        ans += d[s];
        visited[s] = true;
        // 更新各个未加入节点到树的最短距离
        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && dis[s][i] != maxdis && dis[s][i] < d[i])
                d[i] = dis[s][i];
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
        dis.clear();
        dis.resize(n + 1, vector<int>(n + 1, maxdis));
        for (int i = 1; i <= n; ++i) {
            dis[i][i] = 0;
        }
        for (int i = 1; i <= n * (n - 1) / 2; ++i) {
            int a, b, d;
            cin >> a >> b >> d;
            dis[a][b] = d;
            dis[b][a] = d;
        }
        cout << prim() << endl;
    }
}
