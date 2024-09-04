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

    void f(TreeNode* root, vector<int>& pOrder){
        if(root == NULL){
            return;
        }
        f(root->left, pOrder);
        f(root->right, pOrder);
        pOrder.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        // f(root, ans);
        // return ans;
        stack<TreeNode*> s1;
        TreeNode* curr = root;
        if(root == NULL)    return {};
        while(!s1.empty() || curr != NULL){
            if(curr != NULL){
                s1.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode* temp = s1.top()->right;
                if(temp == NULL){
                    temp = s1.top();
                    ans.push_back(temp->val);
                    s1.pop();
                    while(!s1.empty() && temp == s1.top()->right){
                        temp = s1.top();
                        s1.pop();
                        ans.push_back(temp->val);
                    }
                }
                else{
                    curr = temp;
                }
            }
        }
        return ans;
    }
};