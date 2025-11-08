#include <iostream>
#include <climits>

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    explicit TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int findMax(TreeNode* root) {
    if (!root) return INT_MIN;  
    return std::max(root->data, std::max(findMax(root->left), findMax(root->right)));
}

int findMin(TreeNode* root) {
    if (!root) return INT_MAX; 
    return std::min(root->data, std::min(findMin(root->left), findMin(root->right)));
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    std::cout << "Max: " << findMax(root) << "\n";
    std::cout << "Min: " << findMin(root) << "\n";
    return 0;
}
