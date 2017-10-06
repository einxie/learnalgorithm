#include "rbtree.h"

// y为要调整节点父节点，child为要调整节点是其父节点左右孩子类型 0：左孩子 1：右孩子
// 父节点为0表示要调整节点是root。要调整节点为0需要特殊处理
void rb_delete_fixup(struct Rbnode** root, struct Rbnode* y, int child) {
	struct Rbnode* x = 0;
    // 父节点为0只需要调整root
    if(y != 0) {
	    if(child == 0) {
		    x = y->left;
	    } else {
		    x = y->right;
	    }
    } else {
        if(*root != 0) {
            (*root)->color = 1;
        }
        return;
    }
    // 要调整节点为0默认颜色为黑
	int x_color = 1;
	if(x != 0) {
		x_color = x->color;
	}
    while(y != 0 && x != (*root) && x_color == 1) {
        if(child == 0) {
            // w不会为0
            struct Rbnode* w = y->right;
            if(w->color == 0) {
                w->color = 1;
                y->color = 0;
                left_rotate(root, y);
                w = y->right;
            }
            // w左右节点都不存在认为左右节点都为黑
            if((w->left == 0 && w->right == 0) || (w->left != 0 && w->right != 0 && w->left->color == 1 && w->right->color == 1)) {
                w->color = 0;
                // 设置循环条件
                if(y->parent != 0) {
				    if(y == y->parent->left) {
				    	child = 0;
				    } else {
				    	child = 1;
				    }
                }
                x = y;
				x_color = y->color;
                y = y->parent;
            } else {
                // w右节点不存在认为右节点为黑
                if((w->right == 0) || (w->right != 0 && w->right->color == 1)) {
                    if(w->left != 0) {
                        w->left->color = 1;
                    }
                    w->color = 0;
                    right_rotate(root, w);
                    w = y->right;
                }
                w->color = y->color;
                y->color = 1;
                w->right->color = 1;
                left_rotate(root, y);
                x = *root;
            }
        } else {
            // w不会为0
            struct Rbnode* w = y->left;
            if(w->color == 0) {
                w->color = 1;
                y->color = 0;
                right_rotate(root, y);
                w = y->left;
            }
            // w左右节点都不存在认为左右节点都为黑
            if((w->left == 0 && w->right == 0) || (w->left != 0 && w->right != 0 && w->right->color == 1 && w->left->color == 1)) {
                w->color = 0;
                // 设置循环条件
                if(y->parent != 0) {
				    if(y == y->parent->left) {
				    	child = 0;
				    } else {
				    	child = 1;
				    }
                }
                x = y;
				x_color = y->color;
                y = y->parent;
            } else {
                // w左节点不存在认为左节点为黑
                if((w->left == 0) || (w->left != 0 && w->left->color == 1)) {
                    if(w->right != 0) {
                        w->right->color = 1;
                    }
                    w->color = 0;
                    left_rotate(root, w);
                    w = y->left;
                }
                w->color = y->color;
                y->color = 1;
                w->left->color = 1;
                right_rotate(root, y);
                x = *root;
            }
        }
    }
    x->color = 1;
}

