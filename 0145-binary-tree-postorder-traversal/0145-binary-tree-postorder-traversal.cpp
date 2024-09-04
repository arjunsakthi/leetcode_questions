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

    void f(TreeNode* root, vector<int>& pOrder){
        if(root == NULL){
            return;
        }
        f(root->left, pOrder);
        f(root->right, pOrder);
        pOrder.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        // f(root, ans);
        // return ans;
        stack<TreeNode*> s1,s2;
        s1.push(root);
        TreeNode* curr = root;
        if(root == NULL)return {};
        while(!s1.empty()){
            curr = s1.top();
            s1.pop();
            s2.push(curr);
            if(curr->left != NULL){
                s1.push(curr->left);
            }
            if(curr->right != NULL){
                s1.push(curr->right);
            }   
        }
        while(!s2.empty()){
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};