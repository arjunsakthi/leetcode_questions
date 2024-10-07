class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if(root->val == key)    return deleter(root);
        TreeNode *kroot = root;
        while(root != NULL){
            if(root->val > key){
                if(root->left != NULL && root->left->val == key){
                    root->left = deleter(root->left);
                    return kroot;
                }
                else{
                    root = root->left;
                }
            }
            else{
                if(root->right != NULL && root->right->val == key){
                    root->right = deleter(root->right);
                    return kroot;
                }
                else{
                    root = root->right;
                }
            }
        }
        return kroot;
       
    }
    
private:
    TreeNode* deleter(TreeNode *root){
        if(root->left == NULL)  return root->right;
        if(root->right == NULL) return root->left;
        findMin(root->right)->left = root->left;
        return root->right;
    }
    // Helper function to find the minimum value in the right subtree
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};
