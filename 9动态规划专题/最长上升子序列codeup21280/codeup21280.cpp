#include <bits/stdc++.h>
using namespace std;

size_t maxLISlen(const vector<int> &d) {
    vector<size_t> r(d.size(), 1);
    for (size_t i = 1; i < d.size(); ++i) {
        // for each d[i]
        // find its maximum r[t] that satisfy d[t]<d[i] from r[0, i)
        // and r[i] is the maximum r[t]+1
        size_t maxRk = 0;// 此处不能直接选中第一个元素，因为第一个元素也有可能不满足d[t] < d[i]而不应该被选中。当所有元素都不满足，应该为0，所以此处赋值初值0正好。
        for (size_t t = 0; t < i; ++t) {
            if (r[t] > maxRk && d[t] < d[i]) {
                maxRk = r[t];
            }
        }
        r[i] = maxRk + 1;
    }
    return *max_element(r.begin(), r.end()); // 注意还要选出最大的。不是最后一个。
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v;
    while (n--) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    cout << maxLISlen(v) << endl;
}
