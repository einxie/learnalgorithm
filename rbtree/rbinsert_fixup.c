#include "rbtree.h"

void rb_insert_fixup(struct Rbnode** root, struct Rbnode* z) {
    while(z->parent != 0 && z->parent->color == 0 && z->parent->parent != 0) {
        if(z->parent == z->parent->parent->left) {
            struct Rbnode* y = z->parent->parent->right;
            if(y != 0 && y->color == 0) {
                z->parent->color = 1;
                y->color = 1;
                z->parent->parent->color = 0;
                z = z->parent->parent;
            } else {
                if(z == z->parent->right) {
                    z = z->parent;
                    left_rotate(root, z);
                }
                z->parent->color = 1;
                z->parent->parent->color = 0;
                right_rotate(root, z->parent->parent);
            }
        } else {
            struct Rbnode* y = z->parent->parent->left;
            if(y != 0 && y->color == 0) {
                z->parent->color = 1;
                y->color = 1;
                z->parent->parent->color = 0;
                z = z->parent->parent;
            } else {
                if(z == z->parent->left) {
                    z = z->parent;
                    right_rotate(root, z);
                }
                z->parent->color = 1;
                z->parent->parent->color = 0;
                left_rotate(root, z->parent->parent);
            }
        }
    }
    (*root)->color = 1;
}

