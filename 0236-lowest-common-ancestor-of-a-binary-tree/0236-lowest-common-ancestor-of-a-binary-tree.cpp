/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int lca(TreeNode *node,TreeNode*p ,TreeNode*q,TreeNode* &ans){
        int c=0;
        if(node == NULL)    return 0;
        if(node == p || node == q){
            c++;
        }
        int left = lca(node->left, p, q, ans);
        int right = lca(node->right, p, q, ans);
        if(left == -1 || right == -1)   return -1;
        c+= left;
        c+= right;
        if(c == 2){
            ans = node;
            return -1;
        }
        return c;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        lca(root,p,q,ans);
        return ans;
    }
};