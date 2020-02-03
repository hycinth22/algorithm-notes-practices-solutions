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
vector<vector<int> > dis;
constexpr const int maxdis = 0x3f3f3f3f;

int prim() {
    int ans = 0;
    vector<int> d(n + 1, maxdis);
    vector<bool> visited(n + 1);
    d[1] = 0;
    for (int cnt = 0; cnt < n; ++cnt) {
        int s = -1;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i])
                if (s == -1 || d[i] < d[s]) {
                    s = i;
                }
        }
        if (s == -1 || d[s] == -1) {
            return -1;
        }
        visited[s] = true;
        ans += d[s];
        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && dis[s][i] != maxdis)
                if (dis[s][i] < d[i]) {
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
        dis.clear();
        dis.resize(n + 1, vector<int>(n + 1, maxdis));
        for (int i = 1; i <= n; ++i) {
            dis[i][i] = 0;
        }
        for (int i = 1; i <= n * (n - 1) / 2; ++i) {
            int a, b, d, built;
            cin >> a >> b >> d >> built;
            if (built) {
                d = 0; // 已建造的直接置0即可，这样既满足了最小生成树一定包含此路，也满足了不会计入最后成本
            }
            dis[a][b] = d;
            dis[b][a] = d;
        }
        cout << prim() << endl;
    }
}
