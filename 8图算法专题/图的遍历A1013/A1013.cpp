// 该题可以转化为求图中连通块个数。
//
// 该题的大意：从图中删除特定点及其边。如何添加最少的边，使得剩下的整个图连通？
// 思路：只要将图中各个连通块之间相连，即可添加最少的边，
// 则 要添加的边数 转化为 连通块个数-1
//
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> road;
int countConnectedBlocks(int n, int deleted_vertex) {
    vector<bool> visited(n+1);
    fill(visited.begin(), visited.begin()+n+2, false);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (i != deleted_vertex && !visited[i]) {
            ++cnt;
            // visit each vertex in the block
            visited[i] = true;
            queue<int> q; q.push(i);
            while (!q.empty()) {
                for (const int &v: road[q.front()]) {
                    if (!visited[v] && v != deleted_vertex) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
                q.pop();
            }
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, k; scanf("%d%d%d", &n, &m, &k); // cin >> n >> m >> k;
    road.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b; scanf("%d%d", &a, &b); // cin >> a >> b;
        road[a].push_back(b); road[b].push_back(a);
    }
    for (int i = 0; i < k; ++i) {
        int lost; scanf("%d", &lost); //cin >> lost;
        int ans = countConnectedBlocks(n, lost) - 1;
        printf("%d\n", ans); // cout << ans << endl;
    }
}