/**
 * Definition for a binary tree TreeNode.
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        queue<pair<TreeNode*,int>> st;
        if(root == NULL)    return {};
        st.push({root,0});
        map<int,int> mp;
        while(!st.empty()){
            pair<TreeNode*,int> topp = st.front();
            st.pop();
            mp[topp.second] = topp.first->val;
            if(topp.first->left != NULL)    st.push({topp.first->left, topp.second+1});
            if(topp.first->right != NULL)    st.push({topp.first->right, topp.second+1});
        }
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};