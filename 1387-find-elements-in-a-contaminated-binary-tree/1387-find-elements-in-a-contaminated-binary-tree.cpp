/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    map<int,int> mp;
    FindElements(TreeNode* root) {
        
        if((root->left != NULL && root->left->val == 2 * root->val + 1) || (root->right != NULL && root->right->val == 2 * root->val + 1)){
            root->val = 0;
            rectify(root);
        }
        value(root);
    }
    void value(TreeNode* node){
        if(node == NULL)    return;
        mp[node->val]++;
        if(node->left != NULL){
            value(node->left);
        }
        if(node->right != NULL){
            value(node->right);
        }
        return;
    }
    void rectify(TreeNode* node){
        if(node == NULL)    return;
        if(node->left != NULL){
            node->left->val = 2*(node->val) + 1;
            rectify(node->left);
        }
        if(node->right != NULL){
            node->right->val = 2*(node->val) + 2;
            rectify(node->right);
        }
        return;
    }
    bool find(int target) {
        return mp.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */