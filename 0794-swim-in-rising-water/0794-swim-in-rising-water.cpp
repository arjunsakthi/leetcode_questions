class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int time = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> visited(n,vector<int>(n,0));
        pq.push({grid[0][0],0,0,0});// grid of neighbour , index of negibour , value of original
        visited[0][0]=1;
        while(!pq.empty()){
            int req = pq.top()[0];
            if(time < req){
                time++;
                continue;
            }
            int r = pq.top()[1];
            int c = pq.top()[2];

            pq.pop();
            if(r == n-1 && c == n-1)    return time;
            if(r+1 < n && !visited[r+1][c]){
                pq.push({grid[r+1][c],r+1,c});
                visited[r+1][c]=1;
            }
            if(c+1 < n && !visited[r][c+1]){
                pq.push({grid[r][c+1],r,c+1});
                visited[r][c+1]=1;
            }
            if(r-1 >=0 && !visited[r-1][c]){
                pq.push({grid[r-1][c],r-1,c});
                visited[r-1][c]=1;
            }
            if(c-1 >=0 && !visited[r][c-1]){
                pq.push({grid[r][c-1],r,c-1});
                visited[r][c-1]=1;
            }
        }
        return time;
    }
};