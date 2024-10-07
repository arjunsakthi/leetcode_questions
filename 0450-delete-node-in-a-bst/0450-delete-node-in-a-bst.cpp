class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        
        // Find the node to be deleted
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // Node found, now delete it
            // Case 1: No children (leaf node)
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            // Case 2: One child (left or right)
            else if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // Case 3: Two children
            else {
                TreeNode* successor = findMin(root->right); // Find in-order successor
                root->val = successor->val;  // Copy the value of the successor to the current node
                root->right = deleteNode(root->right, successor->val);  // Delete the successor node
            }
        }
        return root;
    }
    
private:
    // Helper function to find the minimum value in the right subtree
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};
