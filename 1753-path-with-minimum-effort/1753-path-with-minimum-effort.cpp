class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        // shortest path so dijkstra 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<vector<int>> distance = heights;
        if(heights.size() == 1 && heights[0].size() == 1)   return 0;
        for(int i=0; i<heights.size(); i++){
            for(int j=0; j<heights[0].size(); j++){
                distance[i][j] = -1;
            }
        }
        pq.push({0,0});
        while(!pq.empty()){
            int row = pq.top().first;
            int col = pq.top().second;
            pq.pop();
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    if(i==j)  continue;
                    if(  row+i < heights.size() && col+j < heights[0].size() && row+i >=0 && col+j >= 0 &&  (distance[row+i][col+j] == -1 || distance[row+i][col+j] >  max(abs(heights[row][col]-heights[row+i][col+j]), distance[row][col]))){ 
                        distance[row+i][col+j] = max(abs(heights[row][col]-heights[row+i][col+j]), distance[row][col]);
                        pq.push({row+i,col+j});
                    }
                }
            }
            
        }
        return distance[heights.size()-1][heights[0].size()-1];
    }
};