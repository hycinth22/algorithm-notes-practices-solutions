#include <bits/stdc++.h>
using namespace std;

string lcs(const string &rawstr) {
    string str; size_t k = 0;
    unordered_map<size_t, size_t> m;
    m.reserve(rawstr.size());
    for (size_t i = 0; i < rawstr.size(); ++i) {
        if (isalpha(rawstr[i])) {
            str.push_back(tolower(rawstr[i]));
            m[k++] = i;
        }
    }
    if (str.empty()) return "";
    size_t ansPos = 0, ansDiff = 0;
    size_t n = str.size();
    vector<vector<bool> > is(n, vector<bool>(n));
    for (size_t i = 0; i < n; ++i) {
        is[i][i] = true;
    }
    for (size_t i = 0, j = 1; j < n; ++i, ++j) {
        if (str[i] == str[j]) {
            is[i][j] = true;
            if (ansDiff < 1) {
                ansPos = i;
                ansDiff = 1;
            }
        }
    }
    for (size_t diff = 2; diff < n; ++diff) {
        for (size_t i = 0, j = i + diff; i < n && j < n && i < j; ++i, ++j) {
            if (str[i] == str[j] && is[i + 1][j - 1]) {
                is[i][j] = true;
                if (ansDiff < diff) {
                    ansPos = i;
                    ansDiff = diff;
                }
            }
        }
    }
    size_t rawPos = m.at(ansPos),
    rawLen = m.at(ansPos + ansDiff) - rawPos + 1;
    return rawstr.substr(rawPos, rawLen);
}

int main() {
    ios_base::sync_with_stdio(false);
    string str;
    while (getline(cin, str)) {
        cout << lcs(str) << endl;
    }
}
