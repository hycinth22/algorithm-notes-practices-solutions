#include <bits/stdc++.h>
using namespace std;

size_t lenLSS(const string &str) {
    if (str.empty()) return 0;
    size_t n = str.size();
    vector<vector<bool> > is(n, vector<bool>(n));
    size_t len = 1;
    // diff=0, ans = 1
    for (size_t i = 0; i < n; ++i) {
        is[i][i] = true;
    }
    // diff=1, ans = 2 (不能统一在后面循环里)
    for (size_t i = 1; i < n; ++i) {
        if (str[i - 1] == str[i]) {
            is[i - 1][i] = true;
            len = 2;
        }
    }
    // diff>=2, ans=diff+1
    for (size_t diff = 2; diff < n; ++diff) {
        for (size_t i = 0, j = i + diff;
             i < n && j < n && i<j; ++i, j = i + diff) {
            if (str[i] == str[j] && is[i + 1][j - 1]) {
                len = diff + 1;
                is[i][j] = true;
            }
        }
    }
    return len;
}

int main() {
    ios_base::sync_with_stdio(false);
    string str;
    getline(cin, str);
    cout << lenLSS(str) << endl;
}
