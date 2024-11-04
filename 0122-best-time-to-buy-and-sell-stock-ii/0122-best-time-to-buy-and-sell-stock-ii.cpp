class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<long long>> dp(prices.size()+1, vector<long long>(2,0));
        dp[prices.size()][0] = dp[prices.size()][1] = 0;
        for(int i=prices.size()-1; i>=0; i--){
            for(int j=0; j<2; j++){
                if(j==1){
                    dp[i][j] = max(dp[i+1][0]-prices[i],dp[i+1][1]);
                }
                else{
                    dp[i][j] = max(dp[i+1][1]+prices[i],dp[i+1][0]);
                }
            }
        }
        return (int)dp[0][1];
    }
};