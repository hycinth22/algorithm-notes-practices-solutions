#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &v, int &a, int &b) {
    if (v.empty()) return 0;
    if (all_of(v.begin(), v.end(), bind2nd(less<int>(), 0))) {
        a = v.front(), b = v.back();
        return 0;
    }
    struct state {
        int sum;
        size_t left, right;
    };
    vector<state> s(v.size());
    s[0] = {v[0], 0, 0};
    for (size_t i = 1; i < v.size(); ++i) {
        if (s[i - 1].sum >= 0) {
            s[i] = {s[i - 1].sum + v[i], s[i - 1].left, i};
        } else {
            s[i] = {v[i], i, i};
        }
    }
    auto it = max_element(s.cbegin(), s.cend(), [](const state &a, const state &b) {
        return a.sum < b.sum;
    });
    a = v[it->left], b = v[it->right];
    return it->sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        vector<int> v;
        while (n--) {
            int k;
            cin >> k;
            v.push_back(k);
        }
        int s, a, b;
        s = f(v, a, b);
        cout << s << " " << a << " " << b << endl;
    }
}
