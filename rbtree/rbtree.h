#include <stdio.h>
#include <stdlib.h>

// red-black tree's node
struct Rbnode {
    int key;
    int color; // 0:red 1:balck
    struct Rbnode* left;
    struct Rbnode* right;
    struct Rbnode* parent;
};

void left_rotate(struct Rbnode** root, struct Rbnode* x);
void right_rotate(struct Rbnode** root, struct Rbnode* y);
void rb_insert(struct Rbnode** root, struct Rbnode* z);
void rb_insert_fixup(struct Rbnode** root, struct Rbnode* z);
void rb_transplant(struct Rbnode** root, struct Rbnode* u, struct Rbnode* v); 
void rb_delete(struct Rbnode** root, struct Rbnode* z); 
void rb_delete_fixup(struct Rbnode** root, struct Rbnode* y, int child); 

struct Rbnode* rb_minimum(struct Rbnode* x);
struct Rbnode* rb_maxmum(struct Rbnode* x);
struct Rbnode* rb_successor(struct Rbnode* x);
struct Rbnode* rb_predecessor(struct Rbnode* x);

void rbprint_root(struct Rbnode* root); 
void rbprint_node(struct Rbnode* node); 
