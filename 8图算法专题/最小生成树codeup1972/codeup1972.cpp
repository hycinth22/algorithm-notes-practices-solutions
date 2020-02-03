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
unordered_map<char, unordered_map<char, int> > road;
unordered_set<char> p;

int prim() {
    int ans = 0;
    constexpr const int maxdis = 0x3f3f3f3f;
    unordered_map<char, int> d;
    unordered_map<char, bool> visited;
    for (char i: p) {
        d[i] = maxdis;
    }
    d[*p.begin()] = 0;
    for (int cnt = 0; cnt < n; ++cnt) {
        char s = '#';
        for (char i: p) {
            if (!visited[i])
                if (s == '#' || d[i] < d[s])
                    s = i;
        }
        if (s=='#' || d[s]==maxdis) return -1;
        visited[s] = true;
        ans += d[s];
        for (auto rp: road.at(s)) {
            char i = rp.first;
            int rd = rp.second;
            if (!visited[i] && rd < d[i]) {
                d[i] = rd;
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
        road.clear();
        road.reserve(n);
        for (int c = 0; c < n - 1; ++c) {
            char a;
            int nRoad;
            cin >> a >> nRoad;
            p.insert(a);
            for (int cr = 0; cr < nRoad; ++cr) {
                char b;
                int cost;
                cin >> b >> cost;
                road[(a)][(b)] = cost;
                road[(b)][(a)] = cost;
                p.insert(b);
            }
        }
        cout << prim() << endl;
    }
}
