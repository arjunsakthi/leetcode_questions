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
    void parser(int &ind, int depth, string &traversal, TreeNode* node){
        int k = ind;
        while(traversal[k] == '-')k++;
        if(k-ind == depth + 1){
            string num = "";
            while(traversal[k] >='0' && traversal[k] <='9')num.push_back(traversal[k]),k++;
            node->left = new TreeNode(stoi(num));
        
            ind = k;
            parser(ind, depth+1, traversal, node->left);
        }
        else if(k - ind < depth + 1){
            return ;
        }
        else{
            parser(ind, depth+1, traversal, node->left); // this won't happen
        }
        k=ind;
        while(traversal[k] == '-')k++;
        if(k-ind == depth + 1){
            string num = "";
            while(traversal[k] >='0' && traversal[k] <='9')num.push_back(traversal[k]),k++;
            node->right = new TreeNode(stoi(num));
        
            ind = k;
            parser(ind, depth+1, traversal, node->right);
        }
        else if(k - ind < depth + 1){
            return ;
        }
        else{
            parser(ind, depth+1, traversal, node->right); // this won't happen
        }
        return ;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        string num = "";
        int ind = 0;
        while(traversal[ind] >='0' && traversal[ind] <='9')num.push_back(traversal[ind]),ind++;
        TreeNode *node = new TreeNode(stoi(num));
        
        parser(ind, 0, traversal, node);
        return node;
    }
};