#include <iostream>
    
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int countLeaves(TreeNode* root) {
    if(!root) return 0;
    if(root->left && root->right) {
       return countLeaves(root->left) + countLeaves(root->right);
    } else {
        return 1;
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int leaves = countLeaves(root);
    std::cout << leaves;
}