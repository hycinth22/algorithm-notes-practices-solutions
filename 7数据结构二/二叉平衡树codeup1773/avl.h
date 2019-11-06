//
// Created by inked on 2019/11/6.
//

#ifndef AVL_H
#define AVL_H

class AVLTree {
public:
    void insert(int key);
    bool contain(int key);
protected:
    struct node;
    node *root = nullptr;
};

#endif //AVL_H
