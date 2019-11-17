//
// Created by inked on 2019/11/17 0017.
//

#include <bits/stdc++.h>

using namespace std;

#define OPTIMIZE_COMPRESS_PATH

template<int n>
class disjointSets {
    using size_type = int;
public:
    // O(n)
    disjointSets()
            :
            rak(*new array<size_type, n>()),
            ancestor(*new array<size_type, n>()) {
        reset();
    }

    ~disjointSets() {
        delete &rak;
        delete &ancestor;
    }
    // O(n)
    void reset() {
        for (size_type i = 1; i <= n; ++i) {
            ancestor[i] = i;
            rak[i] = 1;
        }
    }

    // O(n)
    size_type count() {
        size_type cnt = 0;
        for (size_type i = 1; i <= n; ++i) {
            if (findAnc(i) == i) {
                ++cnt;
            }
        }
        return cnt;
    }

    void unionSet(int ua, int ub) {
        int a = findAnc(ua), b = findAnc(ub);
        if (a != b) {
            if (rak[a] < rak[b]) {
                swap(a, b);
            }
            rak[a] += rak[b];
            ancestor[b] = a;
#ifdef OPTIMIZE_COMPRESS_PATH
            while (ancestor[ub] != a && ancestor[ub] != ub) {
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

    int maxSetSize() {
        int r = 0;
        for (int i = 1; i <= n; i++) {
            r = max(r, rak[i]);
        }
        return r;
    }
private:
    array<size_type, n> &ancestor;
    array<size_type, n> &rak; // 只有根节点的rank是有效的。

    size_type findAnc(size_type x) {
        while (ancestor[x] != x) {
            x = ancestor[x];
        }
        return x;
    }
};

int main() {
#ifdef _DEBUG
    freopen("test0.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    const int n = 10000000;
    int m;
    disjointSets<n> djs;
    while (cin >> m) {
        djs.reset();
        for (int i = 1; i <= m; ++i) {
            int a, b;
            cin >> a >> b;
            djs.unionSet(a, b);
        }
        cout << djs.maxSetSize() << endl;
    }
}