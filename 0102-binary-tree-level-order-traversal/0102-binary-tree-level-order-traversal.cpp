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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> allNodes;
        allNodes.push(root);
        vector<vector<int>> ans;
        
        if(root == NULL) return {};
        while(!allNodes.empty()){
            int s = allNodes.size();
            vector<int> level;
            for(int i=0; i<s; i++){
                TreeNode *temp = allNodes.front();
                allNodes.pop();
                if(temp->left != NULL)  allNodes.push(temp->left);            
                if(temp->right != NULL)  allNodes.push(temp->right);
                level.push_back(temp->val);
            }
            ans.push_back(level);           
        }
        return ans;
    }
};