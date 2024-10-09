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

class TreeIterator{
    public:
    stack<TreeNode *> stl;
    stack<TreeNode *> str;
    TreeIterator(TreeNode *root){
        pushstl(root);
        pushstr(root);
    }

    int next(){
        TreeNode * a = stl.top();
        stl.pop();
        pushstl(a->right);
        return a->val;
    }
    int before(){
        TreeNode * a = str.top();
        str.pop();
        pushstr(a->left);
        return a->val;
    }

    void pushstl(TreeNode *root){
        while(root!= NULL){
            stl.push(root);
            root = root->left;
        }
    }
    void pushstr(TreeNode *root){
        while(root!= NULL){
            str.push(root);
            root = root->right;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        TreeIterator * p = new TreeIterator(root);
        int l=p->next();
        int r=p->before();
        while(l<r){
            if(l+r == k)    return true;
            if(l+r < k) l=p->next();
            else r=p->before();
        }
        return false;
    }
};