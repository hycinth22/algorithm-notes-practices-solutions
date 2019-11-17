#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

struct usSet {
    using hash_type = usSet*;

    usSet() = default;

    usSet(int pkey) {
        key = pkey;
        root = this;
        rank = 1;
    }

    int key;
    usSet *root;
    int rank;

    void unionSet(usSet &s) {
        // 判断是否已被并入其他集合
        if (root != this) {
            root->unionSet(s);
            return;
        }
        // 按秩合并
        if (this->rank < s.rank) {
            s.unionSet(*this);
            return;
        }
        s.root = this->getroot(); // 合并集合
        this->rank += s.rank;
    }

    hash_type getroot() {
        if (root == this) {
            return this;
        }
        root = root->getroot(); // 查询的同时进行路径压缩
        return root;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<usSet> s(1);
    for (int i = 1; i <= n; i++) {
        s.emplace_back(i);
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        s[a].unionSet(s[b]);
    }
    unordered_set<usSet::hash_type> c;
    for (int i = 1; i <= n; i++) {
        c.insert(s[i].getroot());
    }
    cout << c.size() << endl;
}