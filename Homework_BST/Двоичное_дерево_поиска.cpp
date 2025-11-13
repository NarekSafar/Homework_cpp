#include <iostream>
#include <limits>
#include <vector>

template <typename T>
class BST {
    struct TreeNode {
        T data;
        TreeNode* left;
        TreeNode* right;
        
        explicit TreeNode(const T& data) : data(data), left(nullptr), right(nullptr) {};
        
        void insert(const T& val) {
            if(val < data) {
                if(!left) {
                    left = new TreeNode(val);
                } else {
                    left->insert(val);   
                }
            } else if(val > data) {
                if(!right) {
                    right = new TreeNode(val);
                } else {
                    right->insert(val);   
                }
            } 
        }
        
        bool search(const T& val) const {
            if (val > data) {
                if (!right) {
                  return false;
                }
                return right->search(val);
            } else if (val < data) {
                if (!left) {
                  return false;
                }
                return left->search(val);
            } else {
                return true;
            }
        }
        
        bool isValidBST(T min, T max) const {
            if(!left && right) return right->isValidBST(data, max);
            else if (left && !right) return left->isValidBST(min, data);
            else if (!left && !right) return true;
            else {
                return left->isValidBST(min, data) && right->isValidBST(data, max);
            }
        }
        
        void kthSmallest(int& k, T& result) const {
            if(left) left->kthSmallest(k, result);
            k--;
            if(k == 0) {
                result = data;
                return;
            }
            if(right) right->kthSmallest(k, result);
        }
        
        TreeNode* deleteNode(const T& val) {
            if(val < data) {
                if(left) left = left->deleteNode(val);
            } else if(val > data) {
                if(right) right = right->deleteNode(val);
            } else {
                if(!left && !right) {
                    delete this;
                    return nullptr;
                }
                if(!left) {
                    TreeNode* tmp = right;
                    delete this;
                    return tmp;
                }
                if(!right) {
                    TreeNode* tmp = left;
                    delete this;
                    return tmp;
                }
                TreeNode* tmp = right;
                while(tmp->left) tmp = tmp->left;
                data = tmp->data; 
                right = right->deleteNode(tmp->data); 
            }
            return this;
        }
        
        int countInRange(const T& low, const T& high) const {
            if (data < low && right) return right->countInRange(low, high);
            if (data > high && left) return left->countInRange(low, high);
        
            int count = 0;
            if (data >= low && data <= high) count++;
        
            if (left) count += left->countInRange(low, high);
            if (right) count += right->countInRange(low, high);
        
            return count;
        }
        
        bool hasPathSum(T sum) const {
            sum -= data; 
            if (!left && !right) return (sum == 0);
        
            bool leftHas = left ? left->hasPathSum(sum) : false;
            bool rightHas = right ? right->hasPathSum(sum) : false;
        
            return leftHas || rightHas;
        }

        void print() const {
            if(left) left->print();
            std::cout << data << ' ';
            if(right) right->print();
        }
    };
    
    TreeNode* root = nullptr;
    
public:
    void insert(const T& val) {
        if(!root) {
            root = new TreeNode(val);
        } else {
            root->insert(val);
        }
    }
    
    bool search(const T& val) const {
        if(!root) return false;
        return root->search(val);
    }
    
    void print() const {
        if(!root) {
            std::cout << "Root is empty!\n";
        }
        root->print();
    }
    
    T findMinBST() const {
        if(!root) throw std::exception();
        TreeNode* tmp = root;
        while(tmp->left) {
            tmp = tmp->left;
        }
        return tmp->data;
    }
    
    T findMaxBST() const {
        if(!root) throw std::exception();      
        TreeNode* tmp = root;
        while(tmp->right) {
            tmp = tmp->right;
        }
        return tmp->data;
    }
    
    bool isValidBST() const {
        if (!root) return true;
        return root->isValidBST(std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
    } 
    
    T kthSmallest(int k) const {
        if(!root) throw std::out_of_range("Tree is empty");
        T result{};
        root->kthSmallest(k, result);
        if(k > 0) throw std::out_of_range("k is larger than the number of nodes in the tree");
        return result;
    }
    
    void deleteNode(const T& val) {
        if(root) root = root->deleteNode(val);
    }
    
    int countInRange(const T& low, const T& high) const {
        if(!root) return 0;
        return root->countInRange(low, high);
    }
    
    bool hasPathSum(const T& sum) const {
        if(!root) return false;
        return root->hasPathSum(sum);
    }
};

    BST<int> sortedArrayToBST(const std::vector<int>& vec) {
        BST<int> root;
        root.insert(vec[vec.size() / 2]);
        for(int val : vec) root.insert(val);
        return root;
    }

int main() {
    BST<int> root;
    root.insert(5);
    root.insert(3);
    root.insert(7);
    root.insert(1);
    root.print();
    std::cout << std::endl << std::boolalpha << root.search(1);
    std::cout << "\nMin: " << root.findMinBST();
    std::cout << "\nMax: " << root.findMaxBST();
    std::cout << "\nIsBalanced: " << std::boolalpha << root.isValidBST();
    std::cout << "\nkth smallest element: " << root.kthSmallest(3);
    std::cout << "\nCount of the elements inside the range: " << root.countInRange(2, 6);
    std::cout << "\nIs there a path?: " << root.hasPathSum(12);
    
    std::cout << std::endl;
    root.deleteNode(1);
    root.print();
    
    std::cout << std::endl;
    std::vector<int> vec = {1, 2, 4, 5, 7};
    sortedArrayToBST(vec).print();
    return 0;
}