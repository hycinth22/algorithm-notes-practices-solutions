#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>

using namespace std;


bool aCase(int n, int m) {
    vector<int> represent(n + 1, -1);
    vector<int> rank(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        represent[i] = i;
        rank[i] = 1;
    }
    bool retF = false;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        if (retF) {
            continue;
        }
        // 如果两个节点拥有相同的祖先，则再加一条边就会形成环。
        if (represent[a] == represent[b]) {
            // 不能立即返回，要接收完数据输入。
            retF = true;
            continue;
        }
        // 正常合并（按秩+路径压缩）
        if (rank[a] < rank[b]) {
            swap(a, b);
        }
        int rootpre = represent[a];
        while (represent[rootpre] != rootpre) {
            rootpre = represent[rootpre];
        }
        int t = represent[a];
        while (represent[t] != t) {
            int p = represent[t];
            represent[t] = rootpre;
            t = p;
        }
        represent[a] = represent[b] = rootpre;
    }
    if (retF) {
        return false;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (represent[i] == i) {
            cnt++;
        }
    }
    return cnt <= 1;
}

int main() {
#ifdef _DEBUG
    freopen("test.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        cout << (aCase(n, m) ? "Yes" : "No") << endl;
    }
}