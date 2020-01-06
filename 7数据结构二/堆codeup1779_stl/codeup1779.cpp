//
// Created by inked on 2019/12/7 0007.
//
#include <bits/stdc++.h>

using namespace std;

void heapSort(vector<int> &v) {
    if (v.empty()) return;
    make_heap(v.begin(), v.end());
    sort_heap(v.begin(), v.end()); // 该行等价于以下被注释的循环
    /*
    for (auto begin = v.begin(), end = v.end(); begin != end; --end) {
        pop_heap(begin, end);
    }
    */
}

int main() {
    int n;
    cin >> n;
    vector<int> v;
    v.reserve(n);
    while (n--) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    heapSort(v);
    if (!v.empty()) {
        cout << v[0];
        for (int i = 1; i < v.size(); i++) {
            cout << " " << v[i];
        }
    }
    cout << endl;
}