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
    bool SameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)  return true;
        if(p == NULL || q == NULL)  return false;
        if(p->val != q->val)    return false;
        bool left = SameTree(p->left, q->left);
        if(left == false)   return false;
        bool right = SameTree(p->right, q->right);
        if(right == false)  return false;
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return SameTree(p,q);
    }
};