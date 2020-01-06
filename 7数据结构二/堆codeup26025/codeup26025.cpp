//
// Created by inked on 2019/12/7 0007.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    priority_queue<int, deque<int>, greater<int>> q;
    int n; cin >> n;
    while (n--) {
        int t;
        cin >> t;
        q.push(t);
    }
    int ans = 0;
    while (q.size() > 1) {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        int s = a+b; q.push(a+b);
        ans += s;
    }
    cout << ans << endl;
}