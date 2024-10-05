/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)    return "";
        queue<TreeNode*> qu;
        qu.push(root);
        string res = "";
        while(!qu.empty()){
            TreeNode *temp = qu.front();
            qu.pop();
            if(temp != NULL){
                qu.push(temp->left);
                qu.push(temp->right);
            }
            if(temp != NULL)    res += to_string(temp->val);
            else    res += "null";
            res+=",";
        }
        res.erase(res.size()-1,1);
        return res;
    }

    // Decodes your encoded data to tree.
   TreeNode* deserialize(string data) {
    if (data.empty()) return NULL;  // If the string is empty, return NULL

    // Split the input data into a vector of strings based on commas
    vector<string> nodes;
    stringstream ss(data);
    string temp;
    while (getline(ss, temp, ',')) {
        nodes.push_back(temp);
    }

    // Create the root of the tree
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> qu;
    qu.push(root);
    
    int i = 1;  // Index to track the current node in the 'nodes' vector
    
    // Iterate over the nodes and build the tree
    while (!qu.empty()) {
        TreeNode* curr = qu.front();
        qu.pop();

        // Add left child
        if (nodes[i] != "null") {
            curr->left = new TreeNode(stoi(nodes[i]));
            qu.push(curr->left);
        }
        i++;

        // Add right child
        if (nodes[i] != "null") {
            curr->right = new TreeNode(stoi(nodes[i]));
            qu.push(curr->right);
        }
        i++;
    }
    
    return root;
}

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));