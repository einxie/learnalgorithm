#include "rbtree.h"

void rb_insert(struct Rbnode** root, struct Rbnode* z) {
    struct Rbnode* y = 0;
    struct Rbnode* x = *root;
    while(x != 0) {
        y = x;
        if(z->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    z->parent = y;
    if(y == 0) {
        *root = z;
    } else if(z->key < y->key) {
        y->left = z;
    } else {
        y->right = z;
    }
    z->left = 0;
    z->right = 0;
    z->color = 0;
    rb_insert_fixup(root, z);
}

