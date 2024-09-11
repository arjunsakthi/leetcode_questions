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
    void rec(int i,int j,TreeNode* root,map<int,vector<pair<int,int>>> &mpp){
        mpp[j].push_back(make_pair(i,root->val));
        if(root->left != NULL) {
            rec(i+1,j-1,root->left,mpp);
        } 
        if(root->right != NULL){
            rec(i+1,j+1,root->right,mpp);
        }       
    }


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL)    return {};
        map<int,vector<pair<int,int>>> mpp;
        vector<vector<int>> ans;
        rec(0,0,root,mpp);
        for(auto k:mpp){
            vector<pair<int,int>> pp = k.second;
            sort(pp.begin(),pp.end(),[](pair<int,int>a,pair<int,int>b){
                if(a.first != b.first)   return a.first<b.first;
                else return (a.second < b.second);
            });
            vector<int> kk;
            for(auto i:pp){
                kk.push_back(i.second);
            }
            ans.push_back(kk);
        }
        return ans;
    }
};