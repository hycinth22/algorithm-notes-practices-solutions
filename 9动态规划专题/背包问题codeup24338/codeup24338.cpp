#include <bits/stdc++.h>
using namespace std;

int solution(int cap, const vector<int> &items) {
    if (items.empty()) return cap;
    vector<vector<int>> r(items.size(), vector<int>(cap + 1));
    for (int c = 0; c <= cap; ++c) {
        if (c >= items[0]) {
            r[0][c] = items[0];
        } else {
            r[0][c] = 0;
        }
    }
    for (size_t i = 1; i < items.size(); ++i) {
        for (int c = 0; c <= cap; ++c) {
            // 求r[i][c]
            if (c >= items[i]) {
                r[i][c] = max(r[i - 1][c], r[i - 1][c - items[i]] + items[i]);
            } else {
                r[i][c] = r[i - 1][c];
            }
        }
    }
    return cap - r.back().back();
}

int main() {
    ios_base::sync_with_stdio(false);
    int cap, n;
    cin >> cap >> n;
    vector<int> items(n);
    for (size_t i = 0; i < n; ++i) {
        cin >> items[i];
    }
    cout << solution(cap, items) << endl;
}
