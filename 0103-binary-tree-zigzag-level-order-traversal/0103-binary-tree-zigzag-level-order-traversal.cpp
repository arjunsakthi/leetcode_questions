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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> container;
        container.push(root);
        vector<vector<int>> ans;
        bool togglee = true;
        if(root == NULL)    return {};
        while(!container.empty()){
            int sizee = container.size();
            vector<int> roww(sizee);
            for(int i=0; i<sizee; i++){
                TreeNode* topp = container.front();
                container.pop();
                if(topp->left != NULL)  container.push(topp->left);
                if(topp->right != NULL)  container.push(topp->right);
                if(!togglee){
                    roww[sizee-1-i] = topp->val;
                }
                else{
                    roww[i] = topp->val;
                }
            }
            ans.push_back(roww);
            togglee = !togglee;   
        }   
    return ans;
    }
};