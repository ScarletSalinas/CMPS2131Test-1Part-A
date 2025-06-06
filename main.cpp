#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main() {

    BinarySearchTree tree;

    // Call insert method to insert values into tree
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    
    cout << "\nlevel order traversal:\n";
    tree.levelOrderTraversal();
    
    tree.remove(70);
    
    cout << "\nlevel order traversalfter deleting (40):\n ";
    tree.levelOrderTraversal();

    

}
