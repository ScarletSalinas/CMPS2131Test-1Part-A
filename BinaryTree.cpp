#include "BinaryTree.h";
#include <iostream>;
#include <queue>;

// Constructor
BinarySearchTree::BinarySearchTree() : root(nullptr) {}

// Destructor
BinarySearchTree::~BinarySearchTree() {
    destroyTree(root);
}

// Public methods
void BinarySearchTree::insert(int value) {
    root = insertHelper(root, value);
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
