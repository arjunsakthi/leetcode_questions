class Solution {
public: 
    int lic(int i,int mini, vector<int>& nums){
        if(i == nums.size())     return 0;
        int take = 0;
        int nottake = 0;
        if(nums[i] > mini)  take = 1 + lic(i+1,nums[i],nums); 
        nottake = lic(i+1,mini, nums);
        return max(nottake, take);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1,0));
        // return lic(0,-1e5,nums,vector<int> dp);
        for(int i=1 ;i<=nums.size(); i++){
            for(int j=i; j<=nums.size(); j++){
                int k = 0;
                if(j == nums.size() || nums[i-1] < nums[j]){
                    k = 1+dp[i-1][i-1];
                }
                dp[i][j] = max(k,dp[i-1][j]);
            }
        }
        return dp[nums.size()][nums.size()];
    }
};