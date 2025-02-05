class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
         unordered_map<int,vector<int>> adj;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(i != j && grid[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        queue<pair<int,int>> qu;
        vector<int> deleteRow = {0, 0, +1, -1};
        vector<int> deleteCol = {+1, -1, 0, 0};

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2){
                    qu.push({i,j});
                }
            }
        }
        int count = 0;
        while(!qu.empty()){
  
            int flag = 0;
            int sz = qu.size();
            for(int lo=0; lo<sz; lo++){
                pair<int,int> ele = qu.front();
                int i=ele.first;
                int j=ele.second;
                qu.pop();
                for(int k=0; k<4; k++){
                        if(i+deleteRow[k] >=0 && i+deleteRow[k] < grid.size() && j+deleteCol[k]>=0 &&  j+deleteCol[k]<grid[0].size() && grid[i+deleteRow[k]][j+deleteCol[k]] == 1){
                            grid[i+deleteRow[k]][j+deleteCol[k]] = 2;
                            qu.push({i+deleteRow[k],j+deleteCol[k]});
                            flag = 1;
                        }
                }
            }
            if(flag){
                count++;
            }
        }
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return count;
    }
};