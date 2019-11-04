#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

struct node {
    size_t left, right;
    int key;
};

void fill(vector<node>& tree, deque<int>& dataQueue, size_t fillIndex = 0) {
    if (tree.size() <= fillIndex || fillIndex<0) {
        return;
    }
    fill(tree, dataQueue, tree[fillIndex].left);
    tree[fillIndex].key = dataQueue.front(); dataQueue.pop_front();
    fill(tree, dataQueue, tree[fillIndex].right);
}

void levelTraversal(const vector<node>& tree) {
    deque<int> q; q.push_back(0);
    bool first = true;
    while(!q.empty()) {
        if (first) {
            first = false;
        } else {
            cout << " ";
        }
        const node& n = tree[q.front()]; q.pop_front();
        cout << n.key;
        if (n.left != -1) {
            q.push_back(n.left);
        }
        if (n.right != -1) {
            q.push_back(n.right);
        }
    }
}

int main() {
    int n; cin >> n;
    vector<node> tree(n); deque<int> data(n);
    for (int i=0; i<n;i++) {
        cin >> tree[i].left >> tree[i].right;
    }
    for (int i=0; i<n;i++) {
        cin >> data[i]; // deque可随机迭代，但queue不行
    }
    sort(data.begin(), data.end());
    fill(tree, data);
    levelTraversal(tree);
}