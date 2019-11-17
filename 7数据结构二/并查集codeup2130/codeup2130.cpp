//
// Created by inked on 2019/11/17 0017.
//

#include <bits/stdc++.h>

#define OPTIMIZE_COMPRESS_PATH
using namespace std;

const int n = 10000000;
array<int, n + 1> represent;
array<int, n + 1> rak; // 只有根节点的rank是有效的。

void init() {
    for (int i = 1; i <= n; i++) {
        represent[i] = i;
        rak[i] = 1;
    }
}

int ancestor(int x) {
    while (x != represent[x]) {
        x = represent[x];
    }
    return x;
}

void unionSet(int ra, int rb) {
    int a = ancestor(ra), b = ancestor(rb);
    if (a != b) { // 此处必须验证是否已同集合，调用方不会保证这点。
        if (rak[a] < rak[b]) {
            swap(a, b);
        }
        rak[a] += rak[b];
        represent[b] = a;
#ifdef OPTIMIZE_COMPRESS_PATH
        while (represent[rb] != a && represent[rb] != rb) {
            ra = represent[rb]; // reuse ra as temporary variety
            represent[rb] = a;
            rb = ra;
        }
#endif
    }
}

int maxSetSize() {
    int r = 0;
    for (int i = 1; i <= n; i++) {
        r = max(r, rak[i]);
    }
    return r;
}

int main() {
#ifdef _DEBUG
    freopen("test0.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    int m;
    while (cin >> m) {
        init();
        for (int i = 1; i <= m; ++i) {
            int a, b;
            cin >> a >> b;
            unionSet(a, b);
        }
        cout << maxSetSize() << endl;
    }
}