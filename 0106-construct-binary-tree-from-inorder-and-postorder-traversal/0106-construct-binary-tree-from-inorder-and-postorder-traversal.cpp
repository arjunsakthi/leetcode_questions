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
TreeNode *fun( vector<int> inorder, vector<int> postorder,int prek, int instrt, int inend){
    if(inend<instrt) return nullptr;
    int k = -1;
    for (int j = instrt; j <= inend; j++) {
        if (inorder[j] == postorder[prek]) {
            k = j;
            break;
        }
    }
    if(k == -1) return nullptr;
    TreeNode* kroot = new TreeNode();
    kroot->val = inorder[k];
    kroot->left = fun(inorder,postorder,prek-(inend-k)-1,instrt,k-1);
    kroot->right = fun(inorder,postorder,prek-1,k+1,inend);
    return kroot;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return fun(inorder,postorder,postorder.size()-1,0,inorder.size()-1);
    }
};