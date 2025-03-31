#ifndef BINARYTREE_H
#define BINARYTEE_H

#include <iostream>
using namespace std;

struct BinaryTreeNode {
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    // Const.
    BinaryTreeNode(const int value) : value(value), left(nullptr), right(nullptr) {}

};

class BinarySearchTree {
    public: 
        BinarySearchTree(); // Const.
        ~BinarySearchTree(); // Dest.

        void insert(int value);
        bool search(int value);
        void delete(int value);
        void preOrderTravarsal();
        void inOrderTraversla();
        void postOrderTraversal();
        void levelOrderTraveral();
        int getCount();
        int getTreeHeight();
    
    private:
        BinarySearchTree* root;
        


}

#endif