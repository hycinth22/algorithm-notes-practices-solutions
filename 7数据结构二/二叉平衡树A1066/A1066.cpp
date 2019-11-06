//
// Created by inked on 2019/11/6.
//
#include <iostream>
using namespace std;

struct avl {
    avl *left = nullptr, *right = nullptr;
    int key;
    int height = 1;

    void insert(int x) {
        // 如果不能掌握好updateHeight的调用时机，建议每次使用height前、可能变更后都调用一次。
        if (x < key) {
            if (left) {
                left->insert(x);
                this->updateHeight();
                left = left->keepBalance();
            } else {
                left = new avl();
                left->key = x;
                this->updateHeight();
            }
        } else if (x > key) {
            if (right) {
                right->insert(x);
                this->updateHeight();
                right = right->keepBalance();
            } else {
                right = new avl();
                right->key = x;
                this->updateHeight();
            }
        }
    }

    // 返回新根。保证调整结束后也更新了节点记录的高度。
    avl *keepBalance() {
        // 下面的所有else不能省略，必须写else if。因为要寻找最接近的不平衡点（bf=+-2），因此会有条件既不是+2也不是-2的点。
        int bfrt = this->bf();
        if (bfrt == 2) {
            int bfl = left->bf();
            if (bfl == 1) {
                // LL
                return this->rRotate();
            } else if (bfl == -1) {
                // LR
                left = left->lRotate();
                return this->rRotate();
            }
        } else if (bfrt == -2) {
            int bfr = right->bf();
            if (bfr == 1) {
                // RL
                right = right->rRotate();
                return this->lRotate();
            } else if (bfr == -1) {
                // RR
                return this->lRotate();
            }
        }
        return this;
    }


    int getHeight() {
        if (this == nullptr) {
            return 0;
        }
        return height;
    }

    void updateHeight() {
        height = max(left->getHeight(), right->getHeight()) + 1;
    }

    int bf() {
        return left->getHeight() - right->getHeight();
    }

    avl *lRotate() {
        avl *newRoot = this->right;
        this->right = newRoot->left;
        newRoot->left = this;
        // 顺序不能反，从叶到根更新
        this->updateHeight();
        newRoot->updateHeight();
        return newRoot;
    }

    avl *rRotate() {
        avl *newRoot = this->left;
        this->left = newRoot->right;
        newRoot->right = this;
        // 顺序不能反，从叶到根更新
        this->updateHeight();
        newRoot->updateHeight();
        return newRoot;
    }
};

void insert(avl *&t, int key) {
    if (t == nullptr) {
        t = new avl();
        t->key = key;
        return;
    }
    t->insert(key);
    t = t->keepBalance();
}

int main() {
    int n;
    cin >> n;
    avl *tree = nullptr;
    while (n--) {
        static int t;
        cin >> t;
        insert(tree, t);
    }
    cout << tree->key << endl;
}

