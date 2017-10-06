#include "rbtree.h"

void rb_delete(struct Rbnode** root, struct Rbnode* z) {
    struct Rbnode* y = z;
    int y_ori_color = y->color;
	int child = 0;//用于保存要调整节点是父节点孩子的类型
	struct Rbnode* p = 0;//用于保存要调整节点的父节点
    if(z->left == 0) {
		p = z->parent;// 父节点为空时说明父节点是根节点，调整时只需要设置颜色为黑
		if(p != 0) {
			if(z == z->parent->left) {
				child = 0;
			} else {
				child = 1;
			}
		}
        rb_transplant(root, z, z->right);
    } else if(z->right == 0) {
		p = z->parent;// 父节点为空时说明父节点是根节点，调整时只需要设置颜色为黑
		if(p != 0) {
			if(z == z->parent->left) {
				child = 0;
			} else {
				child = 1;
			}
		}
        rb_transplant(root, z, z->left);
    } else {
        y = rb_minimum(z->right);
        y_ori_color = y->color;
        // z左右孩子都存在，此处父节点不会为空，但子节点可能为空
		p = y->parent;
		if(y == y->parent->left) {
			child = 0;
		} else {
			child = 1;
		}
        if(y->parent == z) {
            p = y;// z会被右孩子替换，所以此处要调整节点父节点为y
            child = 1;
        } else {
            rb_transplant(root, y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        rb_transplant(root, z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if(y_ori_color == 1) {
        rb_delete_fixup(root, p, child);
    }
}

