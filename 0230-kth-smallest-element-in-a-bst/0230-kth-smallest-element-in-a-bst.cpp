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
    int ans;
    int count;
public:
    void rec(TreeNode* root, int k){
        if(!root) return;
        rec(root->left,k);
        count++;
        if(count==k){
            ans = root->val;
        }
        rec(root->right,k);
        return ;
    }
    int kthSmallest(TreeNode* root, int k) {
        count=0;
        rec(root,k);
        return ans;
    }
};