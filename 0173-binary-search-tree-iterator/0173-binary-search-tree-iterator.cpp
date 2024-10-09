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
class BSTIterator {
    vector<TreeNode *> inorder;
    int i;
public:
    BSTIterator(TreeNode* root) {
        i=0;
        TreeNode *temp = root->left;
        stack<TreeNode *> st;
        st.push(root);

        while(true){
            if(temp != NULL){
                st.push(temp);
                temp = temp->left;
            }
            else{
                if(st.empty())    break;
                temp = st.top();
                inorder.push_back(temp);
                st.pop();
                temp = temp->right;
            }
        }
        cout << inorder.size();
    }
    
    int next() {
        return i != inorder.size()?inorder[i++]->val:0;
    }
    
    bool hasNext() {
        if(i == inorder.size()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */