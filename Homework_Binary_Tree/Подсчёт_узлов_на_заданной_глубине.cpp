#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int countNodesAtDepth(TreeNode* root, int k, int depth = 1) {
    if (!root) return 0;
    if (depth == k) return 1;

    return countNodesAtDepth(root->left, k, depth + 1) + countNodesAtDepth(root->right, k, depth + 1);
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int count = countNodesAtDepth(root, 3);
    std::cout << count;
    return 0;
}
