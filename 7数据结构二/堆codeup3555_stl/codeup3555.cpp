//
// Created by inked on 2019/12/7 0007.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
    clog << "stdin is redirected." << endl;
    freopen("sequence7.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    int n;
    scanf("%d", &n);
    //cin >> n;
    vector<int> a, b;
    a.reserve(n); b.reserve(n);
    priority_queue<int> q;
    for (int i = 0; i < n; ++i) {
        int t;
        //cin >> t;
        scanf("%d", &t);
        a.push_back(t);
    }
    for (int i = 0; i < n; ++i) {
        int t;
        //cin >> t;
        scanf("%d", &t);
        b.push_back(t);
        q.push(t * a[0]);
    }
    for (int i = 1; i < n; ++i) {
        register int tt = a[i];
        for (int j = 0; j < n; ++j) {
            int k = tt + b[j];
            //clog << "insert " << a[i]  << "+" << b[j] << "=" << k << "\n";

            if (q.top() > k) {
                q.pop();
                q.push(k);
            }
        }
    }
    if (!q.empty()) {
        stack<int> rq;
        while (!q.empty()) {
            rq.push(q.top());
            q.pop();
        }
        cout << rq.top();
        rq.pop();
        while (!rq.empty()) {
            cout << " " << rq.top();
            rq.pop();
        }
        cout << endl;
    }
}
