class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        // shortest path so dijkstra 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<vector<int>> distance = grid;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                distance[i][j] = -1;
            }
        }
        distance[0][0] = 1;
        pq.push({0,0});
        while(!pq.empty()){
            int dis = distance[pq.top().first][pq.top().second];
            
            int row = pq.top().first;
            int col = pq.top().second;
            pq.pop();
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    if(i==0 && j == 0)  continue;
                    if(  row+i < grid.size() && col+j < grid[0].size() && row+i >=0 && col+j >= 0 && grid[row+i][col+j] != 1 && (distance[row+i][col+j] == -1 || distance[row+i][col+j] > dis+1)){
                        distance[row+i][col+j] = dis+1;
                        pq.push({row+i,col+j});
                        if(row+i == grid.size()-1 && col+j == grid[0].size()-1) return distance[grid.size()-1][grid[0].size()-1];
                    }
                }
            }
            
        }
        return distance[grid.size()-1][grid[0].size()-1];
    }
};