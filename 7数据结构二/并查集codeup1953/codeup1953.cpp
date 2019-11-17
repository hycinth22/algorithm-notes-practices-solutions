//
// Created by inked on 2019/11/17 0017.
//

#include <bits/stdc++.h>
#define OPTIMIZE_COMPRESS_PATH
#define OPTIMIZE_UNION_BY_RANK
using namespace std;

vector<int> represent;
vector<int> rak; // 只有根节点的rank是有效的。

void init(int n) {
    represent.resize(n + 1, 0);
    rak.resize(n+1, 0);
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
#ifdef OPTIMIZE_UNION_BY_RANK
    if (rak[a] < rak[b]) {
        swap(a, b);
    }
    rak[a] += rak[b];
#endif
    represent[b] = a;
#ifdef OPTIMIZE_COMPRESS_PATH
    while (represent[rb] != a && represent[rb] != rb) {
        ra = represent[rb]; // reuse ra as temporary variety
        represent[rb] = a;
        rb = ra;
    }
#endif
}

int main() {
#ifdef _DEBUG
    freopen("test0.in", "r", stdin);
#endif
    int n, m;
    while (cin >> n >> m && n != 0) {
        init(n);
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            // merge
            unionSet(a, b);
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            //clog << i << " is representd by " << ancestor(i) << endl;
            if (ancestor(i) == i) {
                cnt++;
            }
        }
        cout << cnt - 1 << endl;
    }
}