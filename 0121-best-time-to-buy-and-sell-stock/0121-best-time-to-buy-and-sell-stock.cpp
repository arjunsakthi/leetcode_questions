class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = prices[0];
        int ans=0;
        for(int i=0; i<prices.size();i++){
            ans = max(ans, prices[i]-maxi);
            maxi = min(maxi, prices[i]);
        }
        return ans;
    }
};