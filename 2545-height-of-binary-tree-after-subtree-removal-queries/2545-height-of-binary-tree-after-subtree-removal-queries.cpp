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
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        map<int,vector<int>> depthNodes;
        map<int,int> nodesDepth;
        map<int,int> nodesHeight;
        height(root,0,depthNodes,nodesDepth,nodesHeight);
        for(auto &depth : depthNodes){
            
            sort(depth.second.begin(),depth.second.end());
            // for(int i=0;i<depth.second.size() ;i++){
            //     cout << depth.second[i] << " ";
            // }
            // cout <<endl;
        }
        vector<int> ans;
        for(int i=0; i<queries.size();i++){
            int node = queries[i];
            int depth = nodesDepth[node];
            int sz = depthNodes[depth].size();
            // cout << depth << " " << node <<" " <<  sz <<endl;
            // for(int i=0;i<depthNodes[depth].size() ;i++){
            //     cout << depthNodes[depth][i] << " ";
            // }
            // cout <<endl;
            if(sz == 1){
                ans.push_back(depth-1);
            }
            else{
                
                // cout << depthNodes[depth][sz-1] << " " << depth+nodesHeight[node] <<endl;
                if(depthNodes[depth][sz-1] > depth+nodesHeight[node]){
                    ans.push_back(depthNodes[depth][sz-1]);
                }
                else{
                    ans.push_back(depthNodes[depth][sz-2]);
                }
            }
        }
        return ans;
    }
private:
    int height(TreeNode *root,int depth,map<int,vector<int>> &depthNodes,map<int,int> &nodesDepth,map<int,int> &nodesHeight){
        if(root == NULL)    return 0;
        int left = height(root->left, depth+1,depthNodes,nodesDepth,nodesHeight);
        int right = height(root->right, depth+1,depthNodes,nodesDepth,nodesHeight);
        depthNodes[depth].push_back(max(left,right)+depth);
        nodesDepth[root->val] = depth;
        nodesHeight[root->val] = max(left,right);
        return max(left,right)+1;
    }
};