//
// Created by inked on 2019/12/7 0007.
//
#include <bits/stdc++.h>

using namespace std;

// 维护大顶堆。要求仅根节点不符合要求， 左右子树均已是大顶堆。
// 此函数可将根节点也调整至符合要求。
void heapify(vector<int> &v, size_t root, size_t end) {
    if (root >= end) return;
    size_t left = root * 2 + 1, right = root * 2 + 2;

    int max = root;
    if (left < end && v[left] > v[max]) {
        max = left;
    }
    if (right < end && v[right] > v[max]) {
        max = right;
    }
    if (max != root) {
        swap(v[root], v[max]);
        heapify(v, max, end);
    }
}

void buildMaxHeap(vector<int> &v) {
    if (v.empty()) return;
    size_t end = v.size();
    for (size_t i = v.size() - 1; i > 0; i--) {
        // clog << "heapify [" << i << "," << end << ")" << endl;
        heapify(v, i, end);
    }
    //clog << "heapify [" << 0 << "," << end << endl;
    heapify(v, 0, end);
}

void heapSort(vector<int> &v) {
    if (v.empty()) return;
    buildMaxHeap(v);
    size_t end = v.size();
    for (size_t i = v.size() - 1; i > 0; i--) {
        // 将最大的元素取出，置最后。
        swap(v[0], v[i]);
        --end;
        // （此时原最后元素暂时作为新的root）重新调整
        heapify(v, 0, end);
    }
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