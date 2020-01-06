//
// Created by inked on 2019/12/7 0007.
//
#include <bits/stdc++.h>

using namespace std;

struct maxHeap {
public:
    vector<int> data;

    maxHeap(size_t _cap) {
        cap = _cap;
    }

    void insert(int x) {
        if (data.size() < cap) {
            data.push_back(x);
            if (cap > 0) {
                for (size_t i = data.size() - 1; i > 0; i--) {
                    heapify(i);
                }
                heapify(0);
            }
            return;
        }
        if (cap == 0) {
            return;
        }
        if (x > data.front()) {
            //clog << x << " is greater than heap top. drop directly." << endl;
            return;
        }
        data.push_back(x);
        swap(data.front(), data.back());
        if (cap > 0) {
            cap++;
            heapify(0);
        }
        //clog << "erase max element " << data.front() << endl;
        swap(data.front(), data.back());
        data.pop_back();
        if (cap > 0) {
            cap--;
            heapify(0);
        }
    }

private:
    size_t cap;

    void heapify(size_t root) {
        size_t len = data.size();
        if (root >= len) {
            return;
        }
        size_t left = 2 * root + 1, right = 2 * root + 2, max = root;
        if (left < len && data[left] > data[max]) {
            max = left;
        }
        if (right < len && data[right] > data[max]) {
            max = right;
        }
        if (max != root) {
            swap(data[max], data[root]);
            heapify(max);
        }
    }
};

int main() {
#ifdef _DEBUG
    clog << "stdin is redirected." << endl;
    freopen("sequence6.in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a;
    a.reserve(n);
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    maxHeap h(n);
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        for (int j = 0; j < n; ++j) {
            int &ai = a[j];
            //clog << "insert " << ai << "+" << t << "=" << ai + t << "\n";
            h.insert(ai + t);
        }
    }
    if (!h.data.empty()) {
        sort(h.data.begin(), h.data.end());
        cout << h.data[0];
        for (int i = 1; i < h.data.size(); ++i) {
            cout << " " << h.data[i];
        }
    }
    cout << endl;
}
