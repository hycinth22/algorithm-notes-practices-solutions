#include <bits/stdc++.h>
using namespace std;

size_t lenLCS(const string &a, const string &b) {
    if (a.empty() || b.empty()) return 0;
    vector<vector<size_t >> r(a.size(), vector<size_t>(b.size()));
    // 初始化边界
    r[0][0] = (a[0] == b[0]) ? 1 : 0;
    for (size_t i = 1; i < a.size(); ++i) {
        r[i][0] = (a[i] == b[0]) ? 1 : r[i - 1][0];
    }
    for (size_t j = 1; j < b.size(); ++j) {
        r[0][j] = (a[0] == b[j]) ? 1 : r[0][j - 1];
    }
    // 状态转移
    for (size_t i = 1; i < a.size(); ++i) {
        for (size_t j = 1; j < b.size(); ++j) {
            if (a[i] == b[j]) {
                r[i][j] = r[i - 1][j - 1] + 1;
            } else {
                r[i][j] = max(r[i][j - 1], r[i - 1][j]);
            }
        }
    }
    return r.back().back();
}

int main() {
    ios_base::sync_with_stdio(false);
    string a, b;
    while (cin >> a >> b) {
        cout << lenLCS(a, b) << endl;
    }
}
