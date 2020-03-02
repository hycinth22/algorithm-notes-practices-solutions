#include <bits/stdc++.h>
using namespace std;

template<size_t maxVal = 100001ul>
class stackWithPeekMed {
    const size_t nUnit = ceil(sqrt(maxVal));
    vector<multiset<int> > d;
    unordered_map<int, size_t> valCnt;
    vector<int> s;
public:
    stackWithPeekMed() : d(nUnit) {
        valCnt.reserve(maxVal);
    }

    void push(int x) {
        s.push_back(x);
        valCnt[x]++;
        d[x / nUnit].insert(x);
    }

    int pop() {
        int x = s.back();
        --valCnt[x];
        auto &u = d[x / nUnit];
        auto it = u.find(x);
        if (it != u.end()) {
            u.erase(it);
        }
        s.pop_back();
        return x;
    }

    int peekKthLarge(size_t k) {
        size_t cnt = 0;
        for (auto &t: d) {
            if (cnt + t.size() < k) {
                cnt += t.size();
            } else
                for (int xxx: t) {
                    if (k == cnt) {
                        return xxx;
                    }
                    ++cnt;
                }
        }
        return 0;
    }

    int peekMedInComp() {
        if (s.size() % 2) {
            // 1 2 3 4 5 ... ((N+1)/2) ... N
            // 0 1 2 3 4 ... ((N+1)/2)-1 ... N-1
            return peekKthLarge((s.size() + 1) / 2 - 1);
        }
        // 1 2 3 4 5 ... N/2 ... N
        // 0 1 2 3 4 ... N/2-1 ... N-1
        return peekKthLarge(s.size() / 2 - 1);
    }

    bool empty() {
        return s.empty();
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    stackWithPeekMed<> s;
    size_t n;
    cin >> n;
    string op;
    while (n--) {
        cin >> op;
        if (op == "Push") {
            int key;
            cin >> key;
            s.push(key);
        } else if (op == "Pop") {
            if (s.empty()) {
                cout << "Invalid\n";
                continue;
            }
            cout << s.pop() << endl;
        } else if (op == "PeekMedian") {
            if (s.empty()) {
                cout << "Invalid\n";
                continue;
            }
            cout << s.peekMedInComp() << endl;
        }
    }
}
