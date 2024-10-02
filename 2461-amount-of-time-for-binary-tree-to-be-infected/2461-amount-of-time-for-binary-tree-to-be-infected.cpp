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
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> qu, que;

        
        qu.push(root);
        parent[root] = nullptr;
        TreeNode* targetNode = nullptr;

        
        while (!qu.empty()) {
            TreeNode* temp = qu.front();
            if (temp->val == start) 
                targetNode = temp;
            qu.pop();
            
            if (temp->left) {
                parent[temp->left] = temp;
                qu.push(temp->left);
            }
            if (temp->right) {
                parent[temp->right] = temp;
                qu.push(temp->right);
            }
        }

        
        que.push(targetNode);
        int time = 0;
        visited[targetNode] = true;

        while (!que.empty()) {
            int sz = que.size();
            time++;
            for (int i = 0; i < sz; i++) {
                TreeNode* temp = que.front();
                que.pop();
                
                
                if (temp->left && !visited[temp->left]) {
                    que.push(temp->left);
                    visited[temp->left] = true;
                }

                
                if (temp->right && !visited[temp->right]) {
                    que.push(temp->right);
                    visited[temp->right] = true;
                }

                
                if (parent[temp] && !visited[parent[temp]]) {
                    que.push(parent[temp]);
                    visited[parent[temp]] = true;
                }
            }
        }
        return time - 1;  
    }
};
