//
// Created by inked on 2019/11/17 0017.
//

#include <bits/stdc++.h>

using namespace std;

#define OPTIMIZE_COMPRESS_PATH
#define OPTIMIZE_UNION_BY_RANK

class disjointSets {
public:
    // O(n)
    explicit disjointSets(size_t n)
            : n(n),
#ifdef OPTIMIZE_UNION_BY_RANK
              rak(n + 1, 1),
#endif
              ancestor(n + 1, 0) {}

    // O(n)
    size_t count() {
        size_t cnt = 0;
        for (size_t i = 1; i <= n; ++i) {
            if (findAnc(i) == i) {
                ++cnt;
            }
        }
        return cnt;
    }

    void unionSet(int ua, int ub) {
        int a = findAnc(ua), b = findAnc(ub);
        if (a != b) {
#ifdef OPTIMIZE_UNION_BY_RANK
            if (rak[a] < rak[b]) {
                swap(a, b);
            }
            rak[a] += rak[b];
#endif
            ancestor[b] = a;
#ifdef OPTIMIZE_COMPRESS_PATH
            while (ancestor[ub] != a && ancestor[ub] != ub && ancestor[ub] != 0) {
                ua = ancestor[ub]; // reuse ua as temporary variety
                ancestor[ub] = a;
                ub = ua;
            }
#endif
        }
    }

    bool inSameSet(int a, int b) {
        return findAnc(a) == findAnc(b);
    }

private:
    vector<size_t> ancestor;
#ifdef OPTIMIZE_UNION_BY_RANK
    vector<int> rak; // 只有根节点的rank是有效的。
#endif
    size_t n;

    size_t findAnc(size_t x) {
        while (ancestor[x] != 0) {
            x = ancestor[x];
        }
        return x;
    }
};

int main() {
#ifdef _DEBUG
    freopen("sample.in", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        disjointSets djs(n);
        for (size_t i = 1; i <= m; ++i) {
            int a, b;
            cin >> a >> b;
            djs.unionSet(a, b);
        }
        cout << djs.count() << endl;
    }
}