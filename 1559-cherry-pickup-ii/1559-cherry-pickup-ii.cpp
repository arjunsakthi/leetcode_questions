class Solution {
public:

    int f(int i, int j, int k,vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(i == grid.size())  return 0;
        if(j < 0 || k >= grid[0].size())    return 0;
        int l = grid[i][j] + grid[i][k];
        if(dp[i][j][k] != -1)   return dp[i][j][k];
        int l0=0,l1=0,l2=0,l3=0,l4=0,l5=0,l6=0,l7=0,l8=0;
                        l0 = l + f(i + 1,j-1,k-1, grid, dp);
        if(j+1 != k)    l1 = l + f(i + 1,j,k-1, grid, dp);
        if(k-j > 2)     l2 = l + f(i + 1,j+1,k-1, grid, dp);
                        l3 = l + f(i + 1,j-1,k, grid, dp);
                        l4 = l + f(i + 1,j,k, grid, dp);
        if(j+1 != k)    l5 = l + f(i + 1,j+1,k, grid, dp);
                        l6 = l + f(i + 1,j-1,k+1, grid, dp);
                        l7 = l + f(i + 1,j,k+1, grid, dp);
                        l8 = l + f(i + 1,j+1,k+1, grid, dp);
        return dp[i][j][k] = max(l0,max(l1,max(l2,max(l3,max(l4,max(l5,max(l6,max(l7, l8))))))));
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int i=0,j=0,k=grid[0].size()-1;
        if(k>0){
             vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return f(i,j,k,grid,dp);
        }
       else{
        int sum;
        for(int i=0; i<k; i++){
            sum+= grid[i][0];
        }
        return sum;
       }

    }
};