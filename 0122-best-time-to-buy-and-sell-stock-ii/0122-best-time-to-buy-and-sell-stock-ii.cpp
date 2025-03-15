class Solution {
public:
    int maxProfit(vector<int>& prices) {
       vector<vector<int>> dp(prices.size(),vector<int>(2,0));
       dp[prices.size()-1][0] = 0; 
       dp[prices.size()-1][1] = prices[prices.size()-1];
       for(int i=prices.size()-2; i>=0; i--){
        dp[i][0] = max(-prices[i]+dp[i+1][1],dp[i+1][0]);
        dp[i][1] = max(+prices[i]+dp[i+1][0], dp[i+1][1]);
       } 
       return dp[0][0];
    }
};