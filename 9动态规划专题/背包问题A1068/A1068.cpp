#include <bits/stdc++.h>
using namespace std;

vector<int> f(int m, const vector<int> &items) {
    if (items.empty() || m == 0) return {};
    vector<vector<int>> r(items.size(), vector<int>(m + 1));
    vector<vector<bool>> s(items.size(), vector<bool>(m + 1));
    for (int c = 0; c <= m; ++c) {
        s[0][c] = c >= items[0];
        if (s[0][c]) {
            r[0][c] = items[0];
        } else {
            r[0][c] = 0;
        }
    }
    for (size_t i = 1; i < items.size(); ++i) {
        for (int c = 0; c <= m; ++c) {
            // 求r[i][c]
            if (c >= items[i]) {
                if (r[i - 1][c] > r[i - 1][c - items[i]] + items[i]) {
                    s[i][c] = false;
                    r[i][c] = r[i - 1][c];
                } else {
                    s[i][c] = true;
                    r[i][c] = r[i - 1][c - items[i]] + items[i];
                }
            } else {
                s[i][c] = false;
                r[i][c] = r[i - 1][c];
            }
        }
    }
    if (r.back().back() != m) return {};
    vector<int> ans;
    size_t i = items.size() - 1;
    for (int c = m; c != 0; ) {
        if (s[i][c]) {
            ans.push_back(items[i]);
            c -= items[i];
        }
        --i;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    sort(coins.begin(), coins.end(), greater<int>());
    auto ans = f(m, coins);
    if (!ans.empty()) {
        cout << ans[0];
        for (size_t i = 1; i < ans.size(); ++i) {
            cout << " " << ans[i];
        }
    } else {
        cout << "No Solution";
    }
    cout << endl;
}
