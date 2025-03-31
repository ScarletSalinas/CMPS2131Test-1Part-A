#ifndef BINARYTREE_H
#define BINARYTEE_H
struct BinaryTreeNode {
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    // Const.
    explicit BinaryTreeNode(const int val) : value(val), left(nullptr), right(nullptr) {}

};

class BinarySearchTree {
    public: 
        BinarySearchTree(); // Const.
        ~BinarySearchTree(); // Dest.

        // Public interface
        void insert(int value);
        bool search(int value) const;
        void remove(int value);
        void preOrderTraversal() const;
        void inOrderTraversal() const;
        void postOrderTraversal() const;
        void levelOrderTraversal() const;
        int getCount() const;
        int getHeight() const;
    
    private:
        BinaryTreeNode* root;

        // Helper funcs
        BinaryTreeNode* insertHelper(BinaryTreeNode* node, int value);
        BinaryTreeNode* removeHelper(BinaryTreeNode* node, int value);
        bool searchHelper(BinaryTreeNode* node, int val) const;
        void preOrderHelper(BinaryTreeNode* node) const;
        void inOrderHelper(BinaryTreeNode* node) const;
        void postOrderHelper(BinaryTreeNode* node) const;
        void levelOrderHelper(BinaryTreeNode* node) const;
        int treeCount(BinaryTreeNode* node) const;
        int treeHeight(BinaryTreeNode* node) const;
        void destroyTree(BinaryTreeNode* node);

};

#endif