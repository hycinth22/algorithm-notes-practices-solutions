//
// Created by inked on 2019/11/6.
//

class BST {
public:
    void insert(int key);
    bool contain(int key);

protected:
    struct node;
    node *root = nullptr;
};

struct BST::node {
    node *left = nullptr, *right = nullptr;
    int key{};

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
};

void BST::insert(int key) {
    if (!root) {
        root = new node();
        root->key = key;
        return;
    }
    root->insert(key);
}

bool BST::contain(int key) {
    return root && root->contains(key);
}