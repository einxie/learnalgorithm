#include "rbtree.h"

void rbprint_root(struct Rbnode* root) {
    printf("************************ print begin\n");
    if(root == 0) {
        printf("empty tree\n");
    } else {
        printf("root key:%d color:%d\n", root->key, root->color);
    }
    rbprint_node(root);
    printf("************************ print end\n");
}

void rbprint_node(struct Rbnode* node) {
    if(node == 0) {
        return;
    } else {
        printf("node key:%d color:%d\n", node->key, node->color);
    }
    if(node->left != 0) {
        printf("node key:%d left key:%d color:%d\n", node->key, node->left->key, node->left->color);
        rbprint_node(node->left);
    } else {
        printf("%d left end\n", node->key);
    }
    if(node->right != 0) {
        printf("node key:%d right key:%d color:%d\n", node->key, node->right->key, node->right->color);
        rbprint_node(node->right);
    } else {
        printf("%d right end\n", node->key);
    }
}
