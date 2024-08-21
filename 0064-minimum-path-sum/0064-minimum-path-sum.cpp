class Solution {
public:
    int f(int i, int j,vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i == 0 && j == 0){
            return grid[0][0];
        }
        if(i < 0 || j < 0) return INT_MAX;
        int left = INT_MAX;
        if(dp[i][j] != -1) return dp[i][j];
        if(j>0)
        left = grid[i][j]+f(i,j-1,grid,dp);
        int up = INT_MAX;
        if(i>0)
        up = grid[i][j]+f(i-1,j,grid,dp);
        return dp[i][j] = min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, -1));
        vector<int> prev(col,0);
        for(int i=0; i<row; i++){
            vector<int> curr(col,0);
            for(int j=0; j<col; j++){
                if(i == 0 && j == 0) curr[j]=grid[0][0];
                else{   
                    if(i == 0) curr[j] = grid[i][j]+curr[j-1];
                    else if(j == 0) curr[j] = grid[i][j]+prev[j];
                    else{
                        curr[j] = min(grid[i][j]+prev[j],grid[i][j]+curr[j-1]);
                    }
                }
            }
            prev = curr;
        }
        return prev[col-1];
        return f(row-1,col-1,grid,dp);
    }
};