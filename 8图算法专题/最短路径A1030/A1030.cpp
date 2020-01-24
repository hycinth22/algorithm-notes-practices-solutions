#include <bits/stdc++.h>

using namespace std;

#ifndef _DEBUG
struct fakeOSType {
    template<class contentType>
    inline fakeOSType &operator<<(const contentType &cont) {return *this;}
    inline fakeOSType &operator<<(ostream &op(ostream &)) {return *this;}
} nullos;
#define clog nullos
#define cerr nullos
#endif

int n, m, start, dest;
vector<unordered_map<int, int> > dis;
vector<unordered_map<int, int> > cost;

list<int> dijkstra(int &totaldis, int &totalcost) {
    vector<bool> v(n);
    vector<int> sumdistance(n, 0x3f3f3f3f);
    vector<int> sumcost(n, 0x3f3f3f3f);
    vector<int> prev(n, -1);
    sumdistance[start] = 0; sumcost[start]=0;

    for (int cnt = 0; cnt < n; ++cnt) {
        int s = -1;
        for (int i = 0; i < n; ++i) {
            if (!v[i] &&
                (s == -1 ||
                 sumdistance[i] < sumdistance[s] ||
                 (sumdistance[i] == sumdistance[s] && sumcost[i] < sumcost[s])
                )) {
                s = i;
            }
        }
        if (s == -1) {
            break;
        }
        clog << s << " has minimum distance " << sumdistance[s] << endl;
        v[s] = true;
        for (int i = 0; i < n; ++i) {
            // 使用map，一定要记得用count检测是否有道路。防止自动生成零值，最好直接用.at()
            if (!v[i] && dis[s].count(i)) {
                if (sumdistance[s] + dis[s].at(i) < sumdistance[i] ||
                    (sumdistance[s] + dis[s].at(i) == sumdistance[i] && sumcost[s] + cost[s].at(i) < sumcost[i])) {
                    prev[i] = s;
                    sumdistance[i] = sumdistance[s] + dis[s][i];
                    sumcost[i] = sumcost[s] + cost[s][i];
                    clog << " could reach " << i << " in (" << sumdistance[i] << "," << sumcost[i] << ") via " <<  s << endl;
                }
            }
        }
    }
    if (prev[dest] == -1) {
        totaldis = -1;
        totalcost = -1;
        return {};
    }
    list<int> route;
    int p = dest;
    while(p != -1) {
        route.push_front(p);
        p = prev[p];
    }
    totaldis = sumdistance[dest];
    totalcost = sumcost[dest];
    return route;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> start >> dest;
    dis.resize(n);
    cost.resize(n);
    for (int i = 0; i < m; i++) {
        int c1, c2, d, c;
        cin >> c1 >> c2 >> d >> c;
        dis[c1][c2] = dis[c2][c1] = d;
        cost[c1][c2] = cost[c2][c1] = c;
    }
    int totaldis, totalcost;
    auto v = dijkstra(totaldis, totalcost);
    auto it = v.begin();
    assert(!v.empty());
    cout << *it++;
    for (; it!=v.end(); it++) {
        cout << " " << *it;
    }
    cout << " " << totaldis << " " << totalcost << endl;
}
