class Solution {
public:

    void dfs(int ind, vector<int> &visited, unordered_map<int,vector<int>> &adj){
        visited[ind] = 1;
        for(auto i : adj[ind]){
            if(!visited[i]){
                dfs(i, visited, adj);
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>> adj;
        for(int i=0; i<isConnected.size(); i++){
            for(int j=0; j<isConnected[0].size(); j++){
                if(i != j && isConnected[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> visited(isConnected.size(), 0);
        int provisionCount = 0;
        for(int i=0; i<isConnected.size(); i++){
            if(!visited[i] ){
               dfs(i, visited, adj);
                provisionCount++;
            }
        }
        return provisionCount;
    }
};