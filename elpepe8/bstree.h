#ifndef BSTREE_H_INCLUDED
#define BSTREE_H_INCLUDED

#include <iostream>
using namespace std;
#define right(P) P->right
#define left(P) P->left
#define info(P) P->info
#define nil NULL

typedef struct node *address;
typedef int infotype;

struct node{
    infotype info;
    address left;
    address right;
};

address alokasi(infotype x);
void insertNode(address &root, infotype x);
void printInOrder(address root);
address findNode(address root, infotype x);
address deleteNode(address &root, infotype x);
address deleteMostRight(address &root, address n);
address deleteMostLeft(address &root, address n);

#endif // BSTREE_H_INCLUDED
