//
// Created by inked on 2019/11/4.
// http://codeup.cn/problem.php?cid=100000614&pid=0
#include <iostream>
#include "avl.h"
using namespace std;


int main() {
    AVLTree tree;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        static int key;
        cin >> key;
        tree.insert(key);
    }
    for (int i = 0; i < k; i++) {
        static int key;
        cin >> key;
        cout << (tree.contain(key) ? 1 : 0);
        if (i != k - 1) {
            cout << " ";
        }
    }
    cout << endl;
}