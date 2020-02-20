#include <bits/stdc++.h>
using namespace std;

size_t f(const vector<int> &a, const vector<int> &b) {
    if (a.empty() || b.empty()) return 0;
    vector<vector<size_t >> r(a.size(), vector<size_t>(b.size()));
    // 初始化边界
    r[0][0] = (a[0] == b[0]) ? 1 : 0;
    for (size_t i = 1; i < a.size(); ++i) {
        r[i][0] = (a[i] == b[0]) ? (r[i - 1][0] + 1) : r[i - 1][0];
    }
    for (size_t j = 1; j < b.size(); ++j) {
        r[0][j] = (a[0] == b[j]) ? (r[0][j - 1] + 1) : r[0][j - 1];
    }
    // 变种LCS
    for (size_t i = 1; i < a.size(); ++i) {
        for (size_t j = 1; j < b.size(); ++j) {
            if (a[i] == b[j]) {
                r[i][j] = max(r[i][j - 1], r[i - 1][j]) + 1;
            } else {
                r[i][j] = max(r[i][j - 1], r[i - 1][j]);
            }
        }
    }
    return r.back().back();
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, l;
    cin >> n;
    cin >> m;
    vector<int> fav(m);
    for (int i = 0; i < m; i++) {
        cin >> fav[i];
    }
    cin >> l;
    vector<int> stripe(l);
    for (int i = 0; i < l; i++) {
        cin >> stripe[i];
    }
    cout << f(stripe, fav) << endl;
}
