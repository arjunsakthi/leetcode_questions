class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adj(n);
        for(auto i : flights){
            adj[i[0]].push_back({i[1],i[2]});
        }

        vector<vector<int>> distance(n,vector<int>(k+1));
        for(int i=0; i<n; i++){
            for(int j=0; j<=k; j++){
                distance[i][j] = 1e9;
            }
        }
        distance[src][0] = 0;
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        // dis - k, ind
        pq.push({0,{-1,src}});
        while(!pq.empty()){
            int node = pq.top().second.second;
            int dis = pq.top().first;
            int kt = pq.top().second.first;
            pq.pop();
            for(auto i : adj[node]){
                if(kt+1 <= k && distance[i[0]][kt+1] > dis+i[1]){
                    distance[i[0]][kt+1] = dis+i[1];
                    pq.push({distance[i[0]][kt+1],{kt+1, i[0]}});
                }
            }
        }
        int mini = INT_MAX;
        for(int i=0; i<=k; i++){
            mini = min(distance[dst][i],mini);
        }
        return mini == 1e9? -1 : mini;
    }
};