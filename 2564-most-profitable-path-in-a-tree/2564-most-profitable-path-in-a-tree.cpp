class Solution {
public:
    vector<vector<int>> adj;
    vector<int> parent;
    void dfs_parent(int n, int p){
        parent[n] = p;
        for(auto i : adj[n]){
            if(i != p)
                dfs_parent(i,n);
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        int maxi = -1e6;
        adj.resize(1e5+1);
        parent.resize(1e5+1);
        for (auto& i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs_parent(0,0);
        queue<pair<int, int>> qu;
        if (bob == 0) {
            qu.push({0, amount[0] / 2});
        } else {
            qu.push({0, amount[0]});
            amount[bob] = 0;
        }
        while (!qu.empty()) {
                    bob = parent[bob];
            int sz = qu.size();
            
            for (int i = 0; i < sz; i++) {
                int node = qu.front().first;
                int am = qu.front().second;
                int count = 0;
                qu.pop();
                for (int j = 0; j < adj[node].size(); j++) {
                    if (adj[node][j] != parent[node]) {
                        count++;
                        if (bob == adj[node][j]) {
                            qu.push(
                                {adj[node][j], am + amount[adj[node][j]] / 2});
                        } else {
                            qu.push({adj[node][j], am + amount[adj[node][j]]});
                        }
                    }
                }
                if (count == 0) {
                    maxi = max(am, maxi);
                }
            }
            amount[bob] = 0;
        }
        return maxi;
    }
};