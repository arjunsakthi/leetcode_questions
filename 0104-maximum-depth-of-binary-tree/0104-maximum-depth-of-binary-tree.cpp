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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> st;
        if(root == NULL)    return 0;
        st.push(root);
        int height=0;
        while(!st.empty()){
            int size = st.size();
            height++;
            for(int i=0; i<size; i++){
                TreeNode *top = st.front();
                st.pop();
                if(top->left != NULL)   st.push(top->left);
                if(top->right != NULL)   st.push(top->right);
            }
        }
        return height;
    }
};