#include "rbtree.h"

void rb_transplant(struct Rbnode** root, struct Rbnode* u, struct Rbnode* v) {
    if(u->parent == 0) {
        *root = v;
    } else if(u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if(v != 0) {
        v->parent = u->parent;
    }
}

