//
// Created by inked on 2020/1/21 0021.
// 任意一点出发，找到最远的点（可能有数个最远点具有相等的距离），这些最远点就是一部分deepestRoot。
// 然后从这些最远点中任取一点出发，再次寻找最远点，可得剩余deepestRoot。
// 测试点0仍然结果错误
// 测试点1为n=1

#include <bits/stdc++.h>

using namespace std;


void dfs(const vector<vector<int>> &nearby, int n,
         set<int> &furthest, vector<bool> &visited,
         int start, int &deepestDepth, int depth = 0
) {
    clog << " visit " << start << " depth " << depth << endl;
    if (nearby[start].size() <= 1) {
        if (furthest.empty() || deepestDepth == depth) {
            furthest.insert(start);
            deepestDepth = depth;
            clog << "node" << start << " has depth " << depth << endl;
        } else if (deepestDepth < depth){
            clog << "clear furthest" << endl;
            furthest.clear();
            furthest.insert(start);
            deepestDepth = depth;
            clog << "node" << start << " has depth " << depth << endl;
        }
    }
    for (int v: nearby[start]) {
        if (!visited[v]) {
            visited[v] = true;
            dfs(nearby, n, furthest, visited, v, deepestDepth, depth + 1);
        }
    }
}

int solve(const vector<vector<int>> &nearby, int n,
          vector<int> &deepestRoot) {
    if (n <= 0) { return 0; }
    vector<bool> v(n + 1);
    int cnt = 1, deepestDepth = 0;
    set<int> deepest1, deepest2;
    v[1] = true;
    dfs(nearby, n, deepest1, v, 1, deepestDepth);
    clog << "edge point:";
    for (int v : deepest1) {
        clog << " " << v;
    }
    clog << endl;
    clog << "---" << endl;
    for (int i = 2; i <= n; i++) {
        if (!v[i]) {
            v[i] = true;
            dfs(nearby, n, deepest1, v, i, deepestDepth);
            ++cnt;
        }
    }
    // 由于题目给定n-1条边，对于n个点，在只有一个连通块的情形下，一定不成环。
    // 满足一个连通块，无环自动满足，无须额外检查即一定成树。
    if (cnt == 1) {
        fill_n(v.begin(), n, false);
        dfs(nearby, n, deepest2, v, *deepest1.begin(), deepestDepth);
        set_union(deepest1.begin(), deepest1.end(), deepest2.begin(), deepest2.end(), back_inserter(deepestRoot));
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> nearby(n + 1);
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;
        nearby[a].push_back(b);
        nearby[b].push_back(a);
    }
    vector<int> ans; sort(ans.begin(), ans.end()); unique(ans.begin(), ans.end());
    int ret = solve(nearby, n, ans);
    if (ret == 1) {
        for (int a: ans) {
            cout << a << endl;
        }
    } else {
        cout << "Error: " << ret << " components" << endl;
    }
}