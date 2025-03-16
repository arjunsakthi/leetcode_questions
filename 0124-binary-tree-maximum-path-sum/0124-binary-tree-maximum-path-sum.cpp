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
    int height(TreeNode* node, int &maxi){
        if(node == NULL)    return 0;
        int left = height(node->left,maxi);
        int right = height(node->right, maxi);
        maxi = max(maxi, max(0,left) + max(0,right) + node->val);
        return node->val + max(0,max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        height(root,maxi);
        return maxi;
    }
};