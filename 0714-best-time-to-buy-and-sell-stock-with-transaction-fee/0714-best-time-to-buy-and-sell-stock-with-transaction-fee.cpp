class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        for(int i=prices.size()-1; i>=0; i--){
            for(int j=0; j<2; j++){
                if(j == 1){
                    dp[i][j] = max(dp[i+1][j], dp[i+1][0]-prices[i]);
                }
                else{

                    dp[i][j] = max(dp[i+1][1]+prices[i]-fee,dp[i+1][j]);

                }
            }
        }
        return dp[0][1];
    }
};