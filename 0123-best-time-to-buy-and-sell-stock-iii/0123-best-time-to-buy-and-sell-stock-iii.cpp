class Solution {
public:

    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=prices.size()-1; i>=0; i--){
            for(int j=0; j<2; j++){
                for(int k=0; k<3; k++){
                    if(k > 0 && j == 1){
                        dp[i][j][k] = max(dp[i+1][0][k-1]-prices[i],dp[i+1][1][k]);
                    }
                    else if(j == 0){
                        dp[i][j][k] = max(dp[i+1][1][k]+prices[i],dp[i+1][0][k]);
                    }
                    else{
                        dp[i][j][k] = 0;
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};