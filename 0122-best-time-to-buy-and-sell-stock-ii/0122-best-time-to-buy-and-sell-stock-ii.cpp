class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<long long>> dp(prices.size()+1, vector<long long>(2,0));
        vector<int> prev(2,0),curr(2,0);
        dp[prices.size()][0] = dp[prices.size()][1] = 0;
        for(int i=prices.size()-1; i>=0; i--){
            curr = {0,0};
            for(int j=0; j<2; j++){
                if(j==1){
                    curr[j] = max(prev[0]-prices[i],prev[1]);
                }
                else{
                    curr[j] = max(prev[1]+prices[i],prev[0]);
                }
            }
            prev = curr;
        }
        return (int)curr[1];
    }
};