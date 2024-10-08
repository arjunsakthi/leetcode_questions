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
    TreeNode *traversal(TreeNode *root, int p, int q){
        if(root == NULL)    return NULL;
        if(root->val >=p && root->val <= q) return root;
        if(root->val >=p && root->val >= q){
            TreeNode *left = traversal(root->left, p, q);
            if(left != NULL)    return left;
        }
        else{
             TreeNode *right = traversal(root->right, p, q);
            if(right != NULL)    return right;
        }
       
        return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int pp = p->val;
        int qq = q->val;
        if(pp>qq) swap(pp,qq);
        return traversal(root,pp,qq);
    }
};