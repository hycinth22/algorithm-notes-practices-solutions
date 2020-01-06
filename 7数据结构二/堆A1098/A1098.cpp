//
// Created by inked on 2020/1/6 0006.
//
#include <bits/stdc++.h>

using namespace std;

ostream &operator<<(ostream &os, const vector<int> &cont) {
    if (!cont.empty()) {
        os << cont[0];
        for (size_t i = 1; i < cont.size(); ++i)
            os << " " << cont[i];
    }
    return os;
}

bool isHeapSort(vector<int> &data, const vector<int> &target) {
    make_heap(data.begin(), data.end());
    for (auto begin = data.begin(), end = data.end(); begin != end; --end) {
        pop_heap(begin, end);
        if (data == target) {
            pop_heap(begin, --end);
            return true;
        }
    }
    return false;
}

void oneTurnInsertionSort(vector<int> &data) {
    if (data.empty()) return;
    size_t unsorted = 1;
    while (unsorted < data.size() && data[unsorted - 1] <= data[unsorted]) // 注意这个判断要用<=而不能用<，否则出现相等元素会误判为无序
        unsorted++;
    // 排序区域[0, unsorted]
    sort(&data[0], &data[unsorted+1]); // 注意并不用真的模拟排序过程，局部排序可以直接调用排序函数，以此节省代码量
    /*
    // find the pos
    size_t insertPos = 0;
    while (insertPos < unsorted && data[insertPos] < data[unsorted]) {
        insertPos++;
    }
    // move backward
    for (size_t i = insertPos; i != unsorted; ++i) {
        swap(data[i], data[unsorted]);
    }
    */
}

int main() {
    int n;
    cin >> n;
    vector<int> init(n), target(n);
    for (int i = 0; i < n; i++) cin >> init[i];
    for (int i = 0; i < n; i++) cin >> target[i];

    if (isHeapSort(init, target)) {
        cout << "Heap Sort\n" << init << endl;
    } else {
        oneTurnInsertionSort(target);
        cout << "Insertion Sort\n" << target << endl;
    }
}
