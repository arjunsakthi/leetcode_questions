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
    bool rec(TreeNode* root, vector<int> paths, vector<string> &ans){
        if(root == NULL){
            return false;
        }
        paths.push_back(root->val);
        bool left = rec(root->left,paths,ans);
        bool right = rec(root->right,paths,ans);
        if(left == NULL&& right == NULL){
            string kk="";
            for(int i=0; i<paths.size()-1;i++){
            kk += to_string(paths[i]);
            kk+= "->";
            }
            kk+= to_string(paths[paths.size()-1]);
            ans.push_back(kk);
        
        }
        return true;
    }


    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> paths;
        vector<string> ans;
        rec(root, paths,ans);
        return ans;
        st.push(root);
        paths.push_back(root->val);
        TreeNode *temp = root->left;
        if(root->left == NULL && root->right == NULL)   return {to_string(root->val)};
        while(!st.empty()){
            if(temp != NULL){
                st.push(temp);
                paths.push_back(temp->val);
                temp = temp->left;
            }
            else{
                TreeNode *ktemp = st.top()->right;
                if(ktemp == NULL){
                    string kk="";
                    if(st.top()->left == NULL){
                        for(int i=0; i<paths.size()-1;i++){
                        kk += to_string(paths[i]);
                        kk+= "->";
                    }
                    kk+= to_string(paths[paths.size()-1]);
                    ans.push_back(kk);
                    }
                    
                    ktemp = st.top();
                    st.pop();
                    paths.pop_back();
                    while(!st.empty() && ktemp == st.top()->right){
                        ktemp = st.top();
                        st.pop();
                        paths.pop_back();
                    }
                }
                else{
                    temp = st.top()->right;
                }
            }
        }
        return ans;
    }
};