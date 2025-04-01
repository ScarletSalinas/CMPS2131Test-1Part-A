#include "BinaryTree.h"
#include <iostream>
#include <queue>
using namespace std;

// Constructor
BinarySearchTree::BinarySearchTree() : root(nullptr), nodeCount(0) {}

// Destructor
BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
}

// Public methods
void BinarySearchTree::insert(int value) {
    root = insertHelper(root, value);
    nodeCount++;
    cout << "Sucessfully inserted: " << value << endl;
    
}

bool BinarySearchTree::search(int value) const {
    return searchHelper(root, value);
}

void BinarySearchTree::remove(int value) {
    root = removeHelper(root, value);
}

// Traversal methods
void BinarySearchTree::preOrderTraversal() const {
    preOrderHelper(root);
}

void BinarySearchTree::inOrderTraversal() const {
    inOrderHelper(root);
}

void BinarySearchTree::postOrderTraversal() const {
    postOrderHelper(root);
}

void BinarySearchTree::levelOrderTraversal() const {
    levelOrderHelper(root);
}

// Tree properties
int BinarySearchTree::getCount() const {
    return nodeCount;
}

int BinarySearchTree::getHeight() const {
    return treeHeight(root);
}

// private helper methods
BinaryTreeNode* BinarySearchTree::insertHelper(BinaryTreeNode* node, int value) {
    // Case 1: empty tree
    if(node == nullptr) {
        return new BinaryTreeNode(value); // Insert new node
    }

    // Case 2: if value < current (parent) node's value
    if(value < node->value) {
        node->left = insertHelper(node->left, value); 
    } else if(value > node->value) {  // Case 3: if value > current (parent) node's value
        node->right = insertHelper(node->right, value);
    }
    
    return node;
}

BinaryTreeNode* BinarySearchTree::removeHelper(BinaryTreeNode* node, int value) {
    return node;

}

bool BinarySearchTree:: searchHelper(BinaryTreeNode* node, int value) const {
    // Case 1: end of tree
    if(node == nullptr) {
        return false;
    }   

    // Case 2: found match
    if(value == node->value) {
        return true;
    }

    // Recursive cases
    if(value < node->value) {
        return searchHelper(node->left, value); 
    } else {  
        return searchHelper(node->right, value);
    }
}

void BinarySearchTree:: preOrderHelper(BinaryTreeNode* node) const {
    if(node == nullptr) {
    return;
   }

    cout << node->value << " ";
    preOrderHelper(node->left);
    preOrderHelper(node->right);
}

void BinarySearchTree:: inOrderHelper(BinaryTreeNode* node) const {
    cout << "inOrderHelper Implementation goes here:";
}
void BinarySearchTree:: postOrderHelper(BinaryTreeNode* node) const {
    cout << "postOrderHelper Implementation goes here:";
}
void BinarySearchTree:: levelOrderHelper(BinaryTreeNode* node) const {
    cout << "levelOrderHelper Implementation goes here:";

}

int BinarySearchTree:: treeHeight(BinaryTreeNode* node) const {
    // TODO: Implement height calculation
    return 0;
}
void BinarySearchTree:: destroyTree(BinaryTreeNode* node) {
    // TODO: Implement tree destruction

}