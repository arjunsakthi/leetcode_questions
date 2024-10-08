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
    bool validation(TreeNode* root, int low, int high, int lowt, int hight){
        if(root == NULL)    return true;
        if(((root->val <= low)&lowt) || ((root->val >= high)&&hight))   return false;
        return validation(root->left,low,root->val,lowt,1) & validation(root->right,root->val,high,1,hight);
    }

    bool isValidBST(TreeNode* root) {
        return validation(root, INT_MIN, INT_MAX,0,0);
    }
};