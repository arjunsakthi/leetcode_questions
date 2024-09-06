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
    int maxi = INT_MIN;
    int maxDepth(TreeNode *root){
        if(root == NULL)    return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);
        maxi = max(maxi, (root->val + lh + rh) );
        if((root->val +  max(lh,rh))<0) return 0;
        return root->val + max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        maxDepth(root);
        return maxi;
    }
};