class Solution {
public:
    int func(int row, int col, vector<vector<int>>& grid ){
        if(row == 0 && col == 0){
            return grid[0][0];
        }
        int val = grid[row][col];
        int up=INT_MAX, left =INT_MAX;
        if(row > 0)
        up = func(row-1,col,grid);
        if(col > 0)
        left = func(row,col-1,grid);
        return min(up, left)+val;
    }
    int minPathSum(vector<vector<int>>& grid) {
        // return func(grid.size()-1,grid[0].size()-1,grid);
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        dp[0][0] = grid[0][0];
        for(int i=0; i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int val = grid[i][j];
                int up=INT_MAX, left =INT_MAX;
                if(i > 0)
                up = dp[i-1][j];
                if(j > 0)
                left = dp[i][j-1];
                if(!(i==0 && j==0))
                dp[i][j] = min(up,left)+val;
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};