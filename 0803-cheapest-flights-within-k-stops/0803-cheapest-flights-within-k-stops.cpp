class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adj(n);
        for(auto i : flights){
            adj[i[0]].push_back({i[1],i[2]});
        }

        vector<int> distance(n);
        for(int i=0; i<n; i++){
            
                distance[i]= 1e9;
            
        }
        distance[src] = 0;
        queue<pair<int,pair<int,int>>> pq;
        // dis - k, ind
        pq.push({-1,{0,src}});
        while(!pq.empty()){
            int node = pq.front().second.second;
            int dis = pq.front().second.first;
            int kt = pq.front().first;
            pq.pop();
            for(auto i : adj[node]){
                if(kt+1 <= k && distance[i[0]] > dis+i[1]){
                    distance[i[0]] = dis+i[1];
                    pq.push({kt+1,{distance[i[0]], i[0]}});
                }
            }
        }
        
        return distance[dst] == 1e9? -1 : distance[dst];
    }
};