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
    if (search(value)) {  // Check for existing value
        cerr << "Error: " << value << " already exists.\n";
        return;
    }

    root = insertHelper(root, value);
    nodeCount++;
    cout << "(" << value << ")" << " sucessfully inserted. Total nodes in Tree: " << nodeCount << endl;
}

bool BinarySearchTree::search(int value) const {
    return searchHelper(root, value);
}

void BinarySearchTree::remove(int value) {
    // Using search
    if(!search(value)) {
        cout << "Value (" << value << ") not found.\n";
        return;
    }
    root = removeHelper(root, value);
    nodeCount--;
    cout << "Value (" << value << ")" << " sucessfully removed. Total nodes in Tree: " << nodeCount << endl;
    
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
    // Exit early if value dosent exist
    if (node == nullptr) {
        return nullptr;  // Base case: value not found
    } 

    // Recurse left/right if not the target node
    if (value < node->value) {
        node->left = removeHelper(node->left, value);
        return node;
    } 

    if (value > node->value) {
        node->right = removeHelper(node->right, value);
        return node;
    }

    // Case 1: No left child
    if (node->left == nullptr) {
        BinaryTreeNode* rightChild = node->right;
        delete node;
        nodeCount--;
        return rightChild;
    }

    // Case 2: No right child
    if (node->right == nullptr) {
        BinaryTreeNode* leftChild = node->left;
        delete node;
        nodeCount--;
        return leftChild;
    }

    // Case 3: Two children
    BinaryTreeNode* successor = node->right;
    while (successor->left != nullptr) {
        successor = successor->left;
    }
    node->value = successor->value;  // Replace value
    node->right = removeHelper(node->right, successor->value);  // Delete successor
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
    if(node == nullptr) {
        return;
    }

    inOrderHelper(node->left);
    cout << node->value << " ";
    inOrderHelper(node->right);
}

void BinarySearchTree:: postOrderHelper(BinaryTreeNode* node) const {
    if(node == nullptr) {
        return;
    }

    postOrderHelper(node->left);
    postOrderHelper(node->right);
    cout << node->value << " ";
}

void BinarySearchTree:: levelOrderHelper(BinaryTreeNode* node) const {
    if(node == nullptr) {
        return;
    }

    queue<BinaryTreeNode*> q;
    q.push(node);
    
    while (!q.empty()) {
        int levelSize = q.size();  // Capture current level size

        for (int i = 0; i < levelSize; ++i) {
            BinaryTreeNode* current = q.front();
            q.pop();
            cout << current->value << " ";
            
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        cout << endl;  // Newline after level
    }
    
}

int BinarySearchTree:: treeHeight(BinaryTreeNode* node) const {
    // TODO: Implement height calculation
    return 0;
}
void BinarySearchTree:: destroyTree(BinaryTreeNode* node) {
    // TODO: Implement tree destruction

}