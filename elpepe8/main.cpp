#include <iostream>
#include "bstree.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    address root = nil;
    insertNode(root, 1);
    insertNode(root, 2);
    insertNode(root, 6);
    insertNode(root, 4);
    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 6);
    insertNode(root, 7);
    printInOrder(root);
    cout << "\n";
    cout << "Delete 6" << endl;
    deleteNode(root, 6);
    printInOrder(root);
    return 0;
}
