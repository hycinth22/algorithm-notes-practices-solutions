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

int n, m;
vector<vector<int> > dis;
constexpr const int maxdis = 0x3f3f3f3f;

int prim() {
    int ans = 0;
    vector<int> d(m+1, maxdis); // 存储各点加入最小生成树之前，到集合的最短距离
    vector<bool> visited(m + 1);
    d[1] = 0;
    for (int cnt = 0; cnt < m; ++cnt) {
        int s = -1;
        for (int i = 1; i <= m; ++i) {
            if (!visited[i])
                if (s == -1 || d[i] < d[s]) {
                    s = i;
                }
        }
        if (s == -1 || d[s] == maxdis) return -1;
        visited[s] = true;
        ans += d[s];
        clog << "select " << s << " (" << d[s] << endl;
        for (int i = 1; i <= m; ++i) {
            if (!visited[i])
                if (dis[s][i] != maxdis && dis[s][i] < d[i]) {
                    d[i] = dis[s][i];
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
        cin >> m;
        dis.clear();
        dis.resize(m + 1, vector<int>(m + 1, maxdis));
        for (int i = 1; i <= m; ++i) {
            dis[i][i] = 0;
        }
        for (int i = 1; i <= n; ++i) {
            int a, b, d;
            cin >> a >> b >> d;
            dis[a][b] = d;
            dis[b][a] = d;
        }
        int ans = prim();
        if (ans != -1) {
            cout << ans;
        } else {
            cout << "?";
        }
        cout << endl;
    }
}
