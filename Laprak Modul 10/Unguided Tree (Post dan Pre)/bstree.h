#ifndef BSTREE_H
#define BSTREE_H
#define Nil NULL

typedef int infotype;
typedef struct Node *address;

struct Node {
    infotype info;
    address left;
    address right;
};

// Fungsi & Prosedur BST
address alokasi(infotype x);
void insertNode(address &root, infotype x);
void preOrder(address root);
void postOrder(address root);

#endif
