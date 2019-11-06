//
// Created by inked on 2019/11/6.
//
#include <algorithm>
using namespace std;

class AVLTree {
public:
    void insert(int key);
    bool contain(int key);

protected:
    struct node;
    node *root = nullptr;
};

struct AVLTree::node {
    node *left = nullptr, *right = nullptr;
    int key{};
    int height = 1;

    bool contains(int s_key) {
        if (key == s_key) {
            return true;
        } else if (key > s_key && left && left->contains(s_key)) {
            return true;
        } else if (key < s_key && right && right->contains(s_key)) {
            return true;
        }
        return false;
    }

    node *insert(int s_key) {
        if (key > s_key) {
            if (left) {
                return left->insert(s_key);
            } else {
                left = new node();
                left->key = s_key;
                return left;
            }
        }
        if (key < s_key) {
            if (right) {
                return right->insert(s_key);
            } else {
                right = new node();
                right->key = s_key;
                return right;
            }
        }
        return nullptr; // drop the equivalent element
    }

    int updateHeight() {
        int hLeft = 0, hRight = 0;
        if (left) {
            hLeft = left->updateHeight();
        }
        if (right) {
            hRight = right->updateHeight();
        }
        height = max(hLeft, hRight) + 1;
        return height;
    }
    int balanceFactor() {
        return (left?left->height:0) - (right?right->height:0);
    }

    node* leftRotate() {
        node* newRoot = right;
        right = newRoot->left;
        newRoot->left = this;
        return newRoot;
    }
    node* rightRotate() {
        node* newRoot = left;
        left = newRoot->right;
        newRoot->right = this;
        return newRoot;
    }
};

void AVLTree::insert(int key) {
    if (this->root == nullptr) {
        root = new node();
        root->key = key;
        root->height = 1;
        return;
    }
    root->insert(key);
    root->updateHeight();
    int bfRoot = root->balanceFactor();
    if (bfRoot == 2) {
        int bfLeft = root->left->balanceFactor();
        if (bfLeft == -1) {
            // LR
            root->left = root->left->leftRotate(); // LR to LL
        }
        // LL
        root = root->rightRotate(); // LL to AVL
    }
    else if (bfRoot == -2) {
        int bfRight = root->right->balanceFactor();
        if (bfRight == 1) {
            // RL
            root->right = root->right->rightRotate(); // RL to RR
        }
        // RR
        root = root->leftRotate(); // RR to AVL
    }
    root->updateHeight();
}

bool AVLTree::contain(int key) {
    return root && root->contains(key);
}