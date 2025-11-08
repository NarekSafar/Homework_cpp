#include <iostream>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void mirrorTree(TreeNode* root) {
    if(!root) return;
    std::swap(root->left, root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
}

void inorder(TreeNode* root) {
    if(!root) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

int main() {
   TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    inorder(root);
    mirrorTree(root);
    std::cout << std::endl;
    inorder(root);
    return 0;
}
