class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        if(nums.size() == 1)    return nums[0];

        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for(int i=2; i<nums.size();i++){
            int take = nums[i] + dp[i-2];
            int nottake = dp[i-1];
            dp[i] = max(take,nottake);
        }
        return dp[nums.size()-1];
    }
};