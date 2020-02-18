#include <bits/stdc++.h>
using namespace std;

size_t f(const vector<int> &stripe, const vector<int> &fav) {
    // m:stripe长度。L: fav个数。k:stripe中存在于fav的元素个数
    if (stripe.empty()) return 0;
    // 生成hash表: 逆向映射，喜欢的颜色-fav索引。平均O(L)
    unordered_map<int, size_t> favIndex;
    favIndex.reserve(fav.size());
    for (size_t i = 0; i < fav.size(); ++i) {
        favIndex[fav[i]] = i;
    }
    // 从stripe分离出所有喜欢的颜色的fav索引。平均O(m)
    vector<int> stripeFavIndex;
    for (auto& color : stripe) {
        if (favIndex.count(color)) {
            stripeFavIndex.push_back(favIndex[color]);
        }
    }
    // LIS算法。元素为fav索引。O(k^2)
    vector<size_t> r(stripeFavIndex.size(), 1);
    for (size_t i = 0; i < stripeFavIndex.size(); ++i) {
        for (size_t j = 0; j < i; ++j) {
            if (stripeFavIndex[j] <= stripeFavIndex[i] && r[j] + 1 > r[i]) {
                r[i] = r[j] + 1;
            }
        }
    }
    return *max_element(r.begin(), r.end());
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, l;
    cin >> n;
    cin >> m;
    vector<int> fav; fav.reserve(m);
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        fav.push_back(t);
    }
    vector<int> stripe;
    cin >> l;  stripe.reserve(l);
    for (int i = 0; i < l; i++) {
        int t;
        cin >> t;
        stripe.push_back(t);
    }
    cout << f(stripe, fav) << endl;
}
