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
TreeNode *fun( vector<int> inorder, vector<int> preorder,int prek, int instrt, int inend){
    if(inend<instrt) return nullptr;
    int k = -1;
    for (int j = instrt; j <= inend; j++) {
        if (inorder[j] == preorder[prek]) {
            k = j;
            break;
        }
    }
    if(k == -1) return nullptr;
    TreeNode* kroot = new TreeNode();
    kroot->val = inorder[k];
    kroot->left = fun(inorder,preorder,prek+1,instrt,k-1);
    kroot->right = fun(inorder,preorder,prek + (k - instrt) + 1,k+1,inend);
    return kroot;
}

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       return fun(inorder,preorder,0,0,inorder.size()-1);
    }
};