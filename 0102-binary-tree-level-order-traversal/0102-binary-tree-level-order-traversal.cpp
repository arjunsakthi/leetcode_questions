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
        vector<int> level;
        int k = 1;
        int count = 0;
        if(root == NULL) return {};
        while(!allNodes.empty()){
            TreeNode *temp = allNodes.front();
            level.push_back(temp->val);
            if(temp->left != NULL){
                allNodes.push(temp->left);
            }  
            count++;
            allNodes.pop();
            if(temp->right != NULL)  allNodes.push(temp->right);
            if(k == count){
                k = allNodes.size();
                count = 0;
                ans.push_back(level);
                level.clear();
            }
            
            
        }
        return ans;
    }
};