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
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        TreeNode* req = new TreeNode();
        req->val = val;
        TreeNode* temper = root;
        if(root == NULL){
            return req;
        }
        TreeNode*temp=root;
        while(root!=NULL){
            temp = root;
            if(root->val > val){
                root = root->left;
            }
            else{
                root = root->right;
            }
        }
        if(val > temp->val) temp->right = req;
        else    temp->left = req;
        return temper;
    }
};