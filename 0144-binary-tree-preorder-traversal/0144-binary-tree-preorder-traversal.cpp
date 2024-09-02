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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        if(root == NULL) return {};
        vector<int> ans;
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            if(curr->right != NULL) st.push(curr->right);
            if(curr->left != NULL) st.push(curr->left);
        }
        return ans;
    }
};