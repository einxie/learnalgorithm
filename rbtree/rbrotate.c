#include "rbtree.h"

void left_rotate(struct Rbnode** root, struct Rbnode* x) {
    if(x->right == 0) {
        return;
    }
    struct Rbnode* y = x->right;
    x->right = y->left;
    if(y->left != 0) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if(x->parent == 0) {
        *root = y;
    } else if(x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void right_rotate(struct Rbnode** root, struct Rbnode* y) {
    if(y->left == 0) {
        return;
    }
    struct Rbnode* x = y->left;
    y->left = x->right;
    if(x->right != 0) {
        x->right->parent = y;
    }
    x->parent = y->parent;
    if(y->parent == 0) {
        *root = x;
    } else if(y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }
    x->right = y;
    y->parent = x;
}

