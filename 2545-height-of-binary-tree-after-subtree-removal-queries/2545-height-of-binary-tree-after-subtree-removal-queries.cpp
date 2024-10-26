class Solution {
    vector<int> max1;
    vector<int> max2;
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        // Resize the vectors to handle large depths
        max1.resize(1000001, -1);
        max2.resize(1000001, -1);
        
        unordered_map<int, int> nodesDepth;
        unordered_map<int, int> nodesHeight;

        // Calculate the height of the tree and update max1 and max2 arrays
        height(root, 0, nodesDepth, nodesHeight);

        vector<int> ans(queries.size(), 0);
        for (int i = 0; i < queries.size(); i++) {
            int node = queries[i];
            int depth = nodesDepth[node];
            // Check if max1[depth] corresponds to the node's height, and use max2 if so
            
             if (max1[depth] == nodesHeight[node] + depth) {
                if(max2[depth] != -1){
                ans[i] = max2[depth];
            }
            else{
                ans[i] = depth-1;
            }
                
            } else {
                ans[i] = max1[depth];
            }
        }
        return ans;
    }

private:
    int height(TreeNode* root, int depth, unordered_map<int, int>& nodesDepth, unordered_map<int, int>& nodesHeight) {
        if (root == nullptr) return 0;

        int left = height(root->left, depth + 1, nodesDepth, nodesHeight);
        int right = height(root->right, depth + 1, nodesDepth, nodesHeight);

        nodesDepth[root->val] = depth;
        nodesHeight[root->val] = max(left, right);

        if (max1[depth] <= depth + max(left, right)) {
            max2[depth] = max1[depth];
            max1[depth] = depth + max(left, right);
        } else if (max2[depth] < depth + max(left, right)) {
            max2[depth] = depth + max(left, right);
        }

        return max(left, right) + 1;
    }
};
