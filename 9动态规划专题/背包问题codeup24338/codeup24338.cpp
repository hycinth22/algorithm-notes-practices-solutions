#include <bits/stdc++.h>
using namespace std;

int solution(int cap, const vector<int> &items) {
    if (items.empty()) return cap;
    vector<int> pr(cap + 1), r(cap + 1);
    for (int c = 0; c <= cap; ++c) {
        if (c >= items[0]) {
            pr[c] = items[0];
        } else {
            pr[c] = 0;
        }
    }
    for (size_t i = 1; i < items.size(); ++i) {
        for (int c = 0; c <= cap; ++c) {
            // 求r[i][c]
            if (c >= items[i]) {
                r[c] = max(pr[c], pr[c - items[i]] + items[i]);
            } else {
                r[c] = pr[c];
            }
        }
        r.swap(pr);
    }
    return cap - pr.back();
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
