#include "BinaryTree.h"
#include <iostream>
using namespace std;

int main() {

    BinarySearchTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);
    tree.insert(10);
    tree.insert(89);
    tree.insert(66);
    tree.insert(77);
    tree.insert(34);
    tree.insert(56);
    tree.insert(100);

    tree.remove(89);
    tree.remove(66);
    tree.remove(40);
    tree.remove(34);
    tree.remove(10);
    tree.remove(100);



    

}