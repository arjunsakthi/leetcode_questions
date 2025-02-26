class Solution {
public:
    int ind = 1;
    void dfs(int n, vector<vector<int>> &adj, vector<int> &visited, int parent, vector<int> &tIn, vector<int> &mTin, vector<vector<int>> &ans){
        for(auto i : adj[n]){
            if(i != parent){
                if(!visited[i]){
                    tIn[i] = ind;
                    mTin[i] = ind;
                    ind++;
                    visited[i]=1;
                    dfs(i,adj,visited,n,tIn,mTin,ans);
                    if(mTin[i] <= tIn[n]){
                        // here min is requred as we are comparing to tIn only not mTin.
                        mTin[n] = min(mTin[i],mTin[n]);
                    }
                    else{
                        ans.push_back({i,n});
                    }
                }
                else if(visited[i]){
                    mTin[n] = min(tIn[i],mTin[n]);
                }
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
                vector<vector<int>> adj(n);
                for(auto &i : connections){
                    adj[i[0]].push_back(i[1]); 
                    adj[i[1]].push_back(i[0]); 
                }
                vector<int> visited(n,0);
                visited[0]=1;
                int parent = 0;
                vector<int> tIn(n);
                vector<int> mTin(n);
                tIn[0] = 0;
                mTin[0] = 0;
                vector<vector<int>> ans;
                dfs(0,adj,visited,parent,tIn,mTin, ans);
                return ans;
    }
};