#include "rbtree.h"

struct Rbnode* rb_minimum(struct Rbnode* x) {
    while(x->left != 0) {
        x = x->left;
    }
    return x;
}

struct Rbnode* rb_maxmum(struct Rbnode* x) {
    while(x->right != 0) {
        x = x->right;
    }
    return x;
}

struct Rbnode* rb_successor(struct Rbnode* x) {
    if(x->right != 0) {
        return rb_minimum(x->right);
    }
    struct Rbnode* y = x->parent;
    while(y != 0 && x == y->right) {
        x = y;
        y = y->parent;
    }
    return y;
}

struct Rbnode* rb_predecessor(struct Rbnode* x) {
    if(x->left != 0) {
        return rb_maxmum(x->left);
    }
    struct Rbnode* y = x->parent;
    while(y != 0 && x == y->left) {
        x = y;
        y = y->parent;
    }
    return y;
}

