class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        // shortest path so dijkstra 
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> distance = grid;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                distance[i][j] = -1;
            }
        }
        distance[0][0] = 1;
        pq.push({1,{0,0}});
        while(!pq.empty()){
            int dis = pq.top().first;
            
            pair<int,int> cor = pq.top().second;
            int row = cor.first;
            int col = cor.second;
            pq.pop();
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    if(i==0 && j == 0)  continue;
                    if(  row+i < grid.size() && col+j < grid[0].size() && row+i >=0 && col+j >= 0 && grid[row+i][col+j] != 1 && (distance[row+i][col+j] == -1 || distance[row+i][col+j] > dis+1)){
                        distance[row+i][col+j] = dis+1;
                        pq.push({dis+1, {row+i,col+j}});
                    }
                }
            }
            
        }
        return distance[grid.size()-1][grid[0].size()-1];
    }
};