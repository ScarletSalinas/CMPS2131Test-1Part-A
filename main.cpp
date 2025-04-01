#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main() {

    BinarySearchTree tree;
    tree.insert(50);
    tree.insert(30);
    cout << endl;
    cout << "count: " << tree.getCount();
    cout << "\nResult: " << tree.search(30) << endl;
    tree.preOrderTraversal();
    cout << endl;
    tree.inOrderTraversal();
    cout << endl;
    tree.postOrderTraversal();
    cout << endl;
    tree.levelOrderTraversal();

}