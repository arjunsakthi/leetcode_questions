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

    int lcaLastLevel(TreeNode*root, TreeNode* &ans, int &level, int curr_level, int &sz){
        if(root == NULL)   return 0;
        int left = lcaLastLevel(root->left,ans,level,curr_level+1,sz);
        int right = lcaLastLevel(root->right,ans,level,curr_level+1,sz);
        int count = 0;
        if(curr_level == level) count++;
        count+=left;
        count+=right;
        if(count == sz){
            ans = root;
            return -1;
        }
        return count;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root == NULL)    return NULL;
        queue<TreeNode*> qu;
        qu.push(root);
        int sz = 0;
        int level=-1;
        while(!qu.empty()){
            level++;
            sz = qu.size();
            for(int i=0; i<sz; i++){
                TreeNode* top = qu.front();
                qu.pop();
                if(top->left != NULL)qu.push(top->left);
                if(top->right != NULL)qu.push(top->right);
            }
        }
        TreeNode* ans;
        lcaLastLevel(root,ans,level,0,sz);
        return ans;
    }
};