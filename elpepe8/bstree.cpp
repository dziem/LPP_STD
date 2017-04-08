#include "bstree.h"

address alokasi(infotype x){
    address p = new node;
    info(p) = x;
    left(p) = nil;
    right(p) = nil;
    return p;
}
void insertNode(address &root, infotype x){
    address n;
    n = alokasi(x);
    if(root != nil){
        if(x < info(root)){
            insertNode(left(root), x);
        }else if(x > info(root)){
            insertNode(right(root), x);
        }
    }else{
        root = n;
    }
}
void printInOrder(address root){
    if(root != nil){
        printInOrder(left(root));
        cout << info(root) << " ";
        printInOrder(right(root));
    }
}
address findNode(address root, infotype x){
    if(info(root) != x){
        if(x > info(root)){
            findNode(right(root), x);
        }else if(x < info(root)){
            findNode(left(root), x);
        }
    }else{
        return root;
    }
}
address deleteNode(address &root, infotype x){
    if(root != nil){
        if(x < info(root)){
            left(root) = deleteNode(left(root), x);
        }else if(x > info(root)){
            right(root) = deleteNode(right(root), x);
        }else if(x == info(root)){
            if(left(root) == nil && right(root) == nil){
                root = nil;
                return nil;
            }else if(left(root) != nil){
                root = deleteMostRight(root, left(root));
            }else if(right(root) != nil){
                root = deleteMostLeft(root, right(root));
            }
        }
        return root;
    }else{
        return nil;
    }
}
address deleteMostRight(address &root, address n){
    while(right(n) != nil){
        n = right(n);
    }
    info(root) = info(n);
    left(root) = deleteNode(left(root), info(n));
    return root;
}
address deleteMostLeft(address &root, address n){
    while(left(n) != nil){
        n = left(n);
    }
    info(root) = info(n);
    right(root) = deleteNode(right(root), info(n));
    return  root;
}
