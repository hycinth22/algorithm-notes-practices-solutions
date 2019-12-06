//
// Created by inked on 2019/11/17 0017.
//

#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("sample.in", "r", stdin);
    int n;
    cin >> n;
    vector<int> hobbyRoot(1000 + 1, -1);
    vector<int> personGroup(n + 1, -1);
    vector<int> groupRank(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        personGroup[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        int nt;
        cin >> nt;
        cin.get(); // skip the :
        while (nt--) {
            int h;
            cin >> h;
            auto &root = hobbyRoot[h];
            if (root == -1) {
                // create new group
                root = i;
            } else {
                // union two groups
                int anc1 = i, anc2 = root;
                while (personGroup[anc1] != anc1) {
                    anc1 = personGroup[anc1];
                }
                while (personGroup[anc2] != anc2) {
                    anc2 = personGroup[anc2];
                }
                if (anc1 != anc2) {
                    personGroup[anc1] = anc2;
                    groupRank[anc2] += groupRank[anc1];
                }
            }
        }
    }
    int cnt = 0; vector<int> result;
    for (int i = 1; i <= n; i++) {
        if (personGroup[i] == i) {
            cnt++;
            result.push_back(groupRank[i]);
        }
    }
    sort(result.rbegin(), result.rend());
    cout << cnt << endl;
    if (cnt > 0) {
        cout << result[0];
    }
    for (int i = 1; i < cnt; i++) {
        cout << " " <<result[i];
    }
    cout << endl;
}