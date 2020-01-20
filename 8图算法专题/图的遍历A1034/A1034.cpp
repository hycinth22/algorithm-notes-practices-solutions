//
// Created by inked on 2020/1/7 0007.
//

#include <bits/stdc++.h>

using namespace std;

struct edgeHash {
    // 书写时注意，STL hash返回值是unsigned long
    unsigned long operator()(const pair<string, string> &p) const {
        constexpr static const auto hashString = hash<string>();
        return hashString(p.first) ^ hashString(p.second);
    }
};

unordered_map<string, bool> visitedPoint;
unordered_map<pair<string, string>, bool, edgeHash> visitedEdge;
void visitBlock(const string &start,
                const unordered_map<string, map<string, int> >& call,
                const unordered_map<string, int>& callTime,
                string &gangHead, int &gangHeadTime, int &gangTime, int &gangMember
) {
    visitedPoint[start] = true;
    ++gangMember;
    // clog << "find new gang member" << start << endl;
    if (callTime.count(start) && callTime.at(start) > gangHeadTime) {
        gangHead = start;
        gangHeadTime = callTime.at(start);
    }
    if (call.count(start))
        for (const auto &p : call.at(start)) {
            // 通过区分访问节点与访问边，在环状关系中，既没有重复访问点造成死循环，又没有漏掉最后一条边
            auto edge = make_pair(start, p.first),
                    redge = make_pair(p.first, start);
            if (!visitedEdge[edge]) {
                //clog << "gangTime+" << p.second << " from " << start << " to " << p.first << endl;
                gangTime += p.second;
                visitedEdge[edge] = true;
                visitedEdge[redge] = true;
            }
            if (!visitedPoint[p.first]) {
                visitBlock(p.first,
                           call, callTime,
                           gangHead, gangHeadTime, gangTime, gangMember);
            } else {
                // clog << "find old gang member" << p.first << endl;
            }
        }
}


set<pair<string, int>> findAllGangs(
        const unordered_map<string, map<string, int> >& call,
        const unordered_map<string, int>& callTime,
        int tMememer, int tTime) {
    visitedPoint.clear();
    visitedEdge.clear();
    set<pair<string, int>> gangs;
    // 遍历所有连通块
    for (const auto &p1 : call) {
        if (!visitedPoint[p1.first]) {
            string gangHead;
            int gangHeadTime = 0;
            int gangTime = 0, gangMember = 0;
            visitBlock(p1.first,
                       call, callTime,
                       gangHead, gangHeadTime, gangTime, gangMember);
            //clog << "the pregang is " << gangMember << " " << gangTime << endl;
            if (gangMember > tMememer && gangTime > tTime) {
                gangs.emplace(gangHead, gangMember);
            }
        }
    }
    return gangs;
}


int main() {
    int n, t;
    cin >> n >> t;
    unordered_map<string, map<string, int> > call;
    unordered_map<string, int> callTime;
    while (n--) {
        static string name1, name2;
        int time;
        cin >> name1 >> name2 >> time;
        call[name1][name2] += time;
        call[name2][name1] += time;
        callTime[name1] += time;
        callTime[name2] += time;
        // 此处处理双向边为无向边
    }
    auto gangs = findAllGangs(call, callTime, 2, t);
    // 注意此处结果必须排序，此处使用set已保证有序
    cout << gangs.size() << endl;
    for (const auto &p: gangs) {
        cout << p.first << " " << p.second << endl;
    }
}