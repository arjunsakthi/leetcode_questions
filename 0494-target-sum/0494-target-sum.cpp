class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,0)) ;
        dp[0][0] = 1;
        dp[0][nums[0]] += 1;
        for(int i=1; i<nums.size(); i++){
            for(int j=0; j<sum+1; j++){
                int nottake = dp[i-1][j];
                int take = 0;
                if(nums[i] <=j)    take = dp[i-1][j-nums[i]];
                dp[i][j] = take + nottake;
            }
        }
        if((sum-abs(target))%2 != 0) return 0;
        if(sum >= abs(target)){
            int tar = (sum-abs(target))/2;
        return dp[nums.size()-1][tar];
        }
        else{
            return 0;
        }
        
    }
};