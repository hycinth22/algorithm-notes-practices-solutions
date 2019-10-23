//
// Created by inked on 2019/10/23.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 从0起始的子树序号计算方法。
inline size_t calcleft(size_t root) { return (root+1)*2-1; }
inline size_t calcright(size_t root) { return (root+1)*2; }
void levelTraversal(const vector<int> &d, size_t root) {
    if (root < 0 || root >= d.size()) {
        return;
    }
    queue<size_t> q;
    q.push(root);
    while (!q.empty()) {
        size_t &cur = q.front();
        if (cur != root) {
            cout << " ";
        }
        cout << d[cur];
        size_t left = calcleft(cur), right = calcright(cur);
        if (left >= 0 && left < d.size()) {
            q.push(left);
        }
        if (right >= 0 && right < d.size()) {
            q.push(right);
        }
        q.pop();
    }
    cout << endl;
}

template<class callbackType>
void inorderTraversal(vector<int> &tree, size_t root, const callbackType &callback) {
    if (root < 0 || root >= tree.size()) {
        return;
    }
    size_t left = calcleft(root), right = calcright(root); // 从0起始的子树序号计算方法。left=(root+1)*2-1, right=(root+1)*2
    inorderTraversal(tree, left, callback);
    callback(tree[root]);
    inorderTraversal(tree, right, callback);
}

int main() {
    size_t n;
    cin >> n;
    vector<int> d(n), bst(n);
    for (int &e: d) {
        cin >> e;
    }
    sort(d.begin(), d.end());
    // 由于BST性质，中序遍历应当是有序的，我们可以在中序遍历时从小到大插入数据，以此建立BST。
    size_t iFill = 0;
    inorderTraversal(bst, 0,
                     [&d, &iFill]
                             (int &elem) {
                         elem = d[iFill++];
                         // elem是中序遍历中的每个BST位置，为其插入d中数据（d中数据为有序）
                     }
    );
    levelTraversal(bst, 0);
}
