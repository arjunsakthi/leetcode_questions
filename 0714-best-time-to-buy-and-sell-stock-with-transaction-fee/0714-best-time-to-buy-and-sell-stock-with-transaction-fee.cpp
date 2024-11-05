class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        // vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        int currBuy = 0;
        int currSell = 0;
        for(int i=prices.size()-1; i>=0; i--){
            for(int j=0; j<2; j++){
                int prevBuy = currBuy;
                int prevSell = currSell;
                if(j == 1){
                    currBuy = max(prevBuy, prevSell-prices[i]);
                }
                else{

                    currSell = max(prevBuy+prices[i]-fee,prevSell);

                }
            }
        }
        // return dp[0][1]
        return currBuy;
    }
};