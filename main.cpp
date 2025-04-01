#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main() {

    BinarySearchTree tree;
    tree.insert(50);
    tree.insert(30);
    cout << endl;
    cout << "count: " << tree.getCount();
    cout << endl << tree.search(30);

}