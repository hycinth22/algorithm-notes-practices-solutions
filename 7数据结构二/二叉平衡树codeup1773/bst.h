//
// Created by inked on 2019/11/6.
//

#ifndef BST_H
#define BST_H

class BST {
public:
    void insert(int key);
    bool contain(int key);

protected:
    struct node;
    node *root;
};

#endif //BST_H
